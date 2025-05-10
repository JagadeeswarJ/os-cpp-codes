#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> req = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53, seek = 0;
    vector<bool> done(req.size(), false);

    cout << "Seek Sequence: ";
    for (int i = 0; i < req.size(); i++)
    {
        int min_dist = INT_MAX, idx = -1;
        for (int j = 0; j < req.size(); j++)
        {
            if (!done[j] && abs(head - req[j]) < min_dist)
            {
                min_dist = abs(head - req[j]);
                idx = j;
            }
        }
        seek += min_dist;
        head = req[idx];
        done[idx] = true;
        cout << head << " ";
    }
    cout << "\nTotal Seek Time: " << seek << endl;
    return 0;
}