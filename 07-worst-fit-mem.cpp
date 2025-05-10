#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> par = {20, 15, 40, 60, 25};
    int n = par.size();
    int mem = 25;
    int worst_fit = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (mem <= par[i])
        {
            worst_fit = max(worst_fit, par[i]);
        }
    }
    cout << "Worst fit is " << worst_fit << endl;
    return 0;
}
