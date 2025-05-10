#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id, at, bt, rt, ct, wt, tat;
};

int main()
{
    vector<Process> ps = {
        {1, 0, 6},
        {2, 1, 8},
        {3, 2, 7}};

    for (auto &p : ps)
        p.rt = p.bt;

    int time = 0, done = 0;
    float total_wt = 0, total_tat = 0;

    while (done < ps.size())
    {
        int idx = -1, min_rt = INT_MAX;

        for (int i = 0; i < ps.size(); i++)
        {
            if (ps[i].at <= time && ps[i].rt && ps[i].rt < min_rt)
            {
                min_rt = ps[i].rt;
                idx = i;
            }
        }

        if (idx != -1)
        {
            ps[idx].rt--;
            time++;
            if (ps[idx].rt == 0)
            {
                done++;
                ps[idx].ct = time;
                ps[idx].tat = ps[idx].ct - ps[idx].at;
                ps[idx].wt = ps[idx].tat - ps[idx].bt;
                total_wt += ps[idx].wt;
                total_tat += ps[idx].tat;
            }
        }
        else
        {
            time++;
        }
    }

    cout << "ID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &p : ps)
    {
        cout << p.id << "\t" << p.at << "\t" << p.bt << "\t"
             << p.ct << "\t" << p.tat << "\t" << p.wt << "\n";
    }

    cout << "\nAvg WT: " << total_wt / ps.size()
         << "\nAvg TAT: " << total_tat / ps.size();
}