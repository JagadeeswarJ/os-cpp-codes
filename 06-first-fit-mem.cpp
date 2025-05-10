#include <bits/stdc++.h>
using namespace std;
int main()
{
    int par[] = {20, 15, 40, 60, 25};
    int n = sizeof(par) / sizeof(par[0]);
    int mem = 25;
    for (int i = 0; i < n; i++)
    {
        if (mem <= par[i])
        {
            cout << "First fit is " << par[i] << " at index " << i << endl;
            break;
        }
        else if (i == n - 1)
        {
            cout << "No first fit found" << endl;
        }
    }
    return 0;
}
