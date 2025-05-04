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
            std::cout << "first fit is " << par[i] << " at index " << i << std::endl;
            break;
        }
        else if (i == n - 1)
        {
            std::cout << "No first fit found" << std::endl;
            break;
        }
    }

    return 0;
}