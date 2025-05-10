#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> req = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53, seek = 0;
    vector<int> left, right;

    for (int r : req)
    {
        if (r < head)
            left.push_back(r);
        else
            right.push_back(r);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    cout << "Seek Sequence: ";
    for (int r : right)
    {
        cout << r << " ";
        seek += abs(head - r);
        head = r;
    }
    if (!left.empty())
    {
        seek += abs(head - left[0]);
        head = left[0];
        for (int r : left)
        {
            cout << r << " ";
            seek += abs(head - r);
            head = r;
        }
    }
    cout << "\nTotal Seek Time: " << seek << endl;
    return 0;
}