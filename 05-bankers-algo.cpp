#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> max = {{7, 5, 3},
                               {3, 2, 2},
                               {9, 0, 2},
                               {4, 2, 2},
                               {5, 3, 3}};
    vector<vector<int>> allot = {{0, 1, 0},
                                 {2, 0, 0},
                                 {3, 0, 2},
                                 {2, 1, 1},
                                 {0, 0, 2}};
    vector<int> avail = {3, 3, 2}, finish(5, 0), safeSeq, work = avail;

    while (safeSeq.size() < 5)
    {
        bool found = false;
        for (int i = 0; i < 5; i++)
        {
            if (!finish[i])
            {
                bool canAllocate = true;
                for (int j = 0; j < 3; j++)
                {
                    if (max[i][j] - allot[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        work[j] += allot[i][j];
                    }
                    finish[i] = 1;
                    safeSeq.push_back(i);
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "Unsafe State\n";
            return 0;
        }
    }

    cout << "Safe State\nSafe Sequence: ";
    for (int i : safeSeq)
        cout << i + 1 << " ";
    cout << endl;

    return 0;
}
