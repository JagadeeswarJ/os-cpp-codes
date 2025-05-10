#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> files(10, 0);
    vector<pair<int, int>> requests = {{2, 3}, {5, 4}};

    for (int i = 0; i < requests.size(); i++)
    {
        int start = requests[i].first, length = requests[i].second;
        bool can_allocate = true;
        for (int j = start; j < start + length; j++)
        {
            if (files[j])
                can_allocate = false;
        }
        if (can_allocate)
        {
            for (int j = start; j < start + length; j++)
                files[j] = 1;
            cout << "File " << i + 1 << " allocated\n";
        }
        else
        {
            cout << "File " << i + 1 << " cannot be allocated\n";
        }
    }
    cout << "Final Allocation:\n";
    for (int f : files)
        cout << f << " ";
}