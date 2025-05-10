#include <bits/stdc++.h>
using namespace std;

int main()
{
    struct P
    {
        int id, bt, pr;
    };
    vector<P> p = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}, {4, 6, 3}};
    sort(p.begin(), p.end(), [](P a, P b)
         { return a.pr < b.pr; });

    vector<int> wt(4), tat(4);
    for (int i = 1; i < 4; i++)
        wt[i] = wt[i - 1] + p[i - 1].bt;
    for (int i = 0; i < 4; i++)
        tat[i] = wt[i] + p[i].bt;

    cout << left << setw(10) << "Process" << setw(12) << "Burst Time" << setw(12) << "Priority"
         << setw(15) << "Waiting Time" << "Turnaround Time" << endl;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << setw(10) << p[i].id << setw(12) << p[i].bt << setw(12) << p[i].pr
             << setw(15) << wt[i] << tat[i] << endl;
    }

    return 0;
}
