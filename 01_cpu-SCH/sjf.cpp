#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter no.of Processes:" << endl;
    cin >> n;
    vector<int> bt(n);
    cout << "Enter burst times:" << endl;
    for (int i = 0; i < n; i++)
        cin >> bt[i];
    sort(bt.begin(),bt.end());
    cout << "Shortest Job first order:" << endl;
    for (int x : bt)
        cout << x << " ";
    cout << endl;
    vector<int> wt(n);
    vector<int> ct(n);
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    ct[0] = bt[0];
    for (int i = 1; i < n; i++)
        ct[i] = bt[i] + ct[i - 1];

    cout << "Waiting Time:" << endl;
    for (int x : wt)
        cout << x << " ";

    cout << endl;
    cout << "Completion Time:" << endl;
    for (int x : ct)
        cout << x << " ";
    cout << endl;
    float avgWaitTime = (float)(accumulate(wt.begin(), wt.end(), 0)) / n;
    float avgCompletionTime = (float)(accumulate(ct.begin(), ct.end(), 0)) / n;
    cout << setprecision(3);
    cout << "Average Wait time: " << avgWaitTime << endl
         << "Average Completion Time: " << avgCompletionTime << endl;

    return 0;
}
