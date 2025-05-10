#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> req = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53, seek = 0, size = 200;
    vector<int> left, right;

    for (int r : req)
    {
        if (r < head)
            left.push_back(r);
        else
            right.push_back(r);
    }
    left.push_back(0);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    cout << "Seek Sequence: ";
    for (int r : right)
    {
        cout << r << " ";
        seek += abs(head - r);
        head = r;
    }
    for (int i = left.size() - 1; i >= 0; i--)
    {
        cout << left[i] << " ";
        seek += abs(head - left[i]);
        head = left[i];
    }
    cout << "\nTotal Seek Time: " << seek << endl;
    return 0;
}