#include <bits/stdc++.h>
using namespace std;
int main()
{
    int par[] = {20, 15, 40, 60, 25};
    int n = sizeof(par) / sizeof(par[0]);
    int mem = 25;
    int best_fit = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mem <= par[i])
        {
            best_fit = min(best_fit, par[i]);
        }
    }
    cout << "Best fit is " << best_fit << endl;
    return 0;
}