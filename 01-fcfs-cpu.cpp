#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> bt = {5, 3, 8, 6}, wt(4), ct(4);
    int n = bt.size();
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
        ct[i] = bt[i] + ct[i - 1];

    cout << "Waiting Time:\n";
    for (int x : wt)
        cout << x << " ";
    cout << "\nCompletion Time:\n";
    for (int x : ct)
        cout << x << " ";

    cout << fixed << setprecision(2);
    cout << "\nAverage Wait Time: " << accumulate(wt.begin(), wt.end(), 0.0) / n;
    cout << "\nAverage Completion Time: " << accumulate(ct.begin(), ct.end(), 0.0) / n;

    return 0;
}
