#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> bt = {5, 15, 4, 3}, rem = bt, wt(4), tat(4);
    int q = 2, t = 0, done;
    do
    {
        done = 1;
        for (int i = 0; i < 4; i++)
        {
            if (rem[i])
            {
                done = 0;
                if (rem[i] > q)
                {
                    t += q;
                    rem[i] -= q;
                }
                else
                {
                    t += rem[i];
                    wt[i] = t - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while (!done);

    for (int i = 0; i < 4; i++)
        tat[i] = bt[i] + wt[i];

    cout << left << setw(10) << "Process" << setw(12) << "Burst Time" << setw(15) << "Waiting Time"
         << setw(18) << "Turnaround Time" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << setw(10) << i + 1 << setw(12) << bt[i] << setw(15) << wt[i] << tat[i] << endl;
    }

    cout << fixed << setprecision(2)
         << "\nAverage Waiting Time: " << accumulate(wt.begin(), wt.end(), 0.0) / 4
         << "\nAverage Turnaround Time: " << accumulate(tat.begin(), tat.end(), 0.0) / 4 << endl;

    return 0;
}
