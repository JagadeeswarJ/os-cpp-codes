#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> bt = {6, 8, 7, 3, 2};
    int n = bt.size();
    sort(bt.begin(), bt.end());
    vector<int> wt(n), ct(n);
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
        ct[i] = ct[i - 1] + bt[i];

    cout << "Shortest Job first order:\n";
    for (int x : bt)
        cout << x << " ";
    cout << "\nWaiting Time:\n";
    for (int x : wt)
        cout << x << " ";
    cout << "\nCompletion Time:\n";
    for (int x : ct)
        cout << x << " ";
    cout << fixed << setprecision(2);
    cout << "\nAverage Wait Time: " << accumulate(wt.begin(), wt.end(), 0.0) / n;
    cout << "\nAverage Completion Time: " << accumulate(ct.begin(), ct.end(), 0.0) / n;
}
