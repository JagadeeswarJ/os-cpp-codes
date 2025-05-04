#include <bits/stdc++.h>
using namespace std;

int main()
{
    int par[] = {20, 15, 40, 60, 25};
    int n = sizeof(par) / sizeof(par[0]);
    int mem = 25;

    int first_fit = -1, first_index = -1;
    int best_fit = INT_MAX;
    int worst_fit = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (mem <= par[i])
        {
            if (first_fit == -1)
            {
                first_fit = par[i];
                first_index = i;
            }
            best_fit = min(best_fit, par[i]);
            worst_fit = max(worst_fit, par[i]);
        }
    }

    if (first_fit != -1)
        cout << "First fit is " << first_fit << " at index " << first_index << endl;
    else
        cout << "No first fit found" << endl;

    if (best_fit != INT_MAX)
        cout << "Best fit is " << best_fit << endl;
    else
        cout << "No best fit found" << endl;

    if (worst_fit != INT_MIN)
        cout << "Worst fit is " << worst_fit << endl;
    else
        cout << "No worst fit found" << endl;

    return 0;
}
