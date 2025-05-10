#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> files(10, 0);
    vector<int> blocks = {1, 4, 7, 2};

    if (files[blocks[0]])
    {
        cout << "Starting block already allocated\n";
        return 0;
    }
    files[blocks[0]] = 1;
    for (int i = 1; i < blocks.size(); i++)
    {
        if (files[blocks[i]])
        {
            cout << "Block " << blocks[i] << " already allocated\n";
            return 0;
        }
        files[blocks[i]] = 1;
    }
    cout << "File blocks: ";
    for (int b : blocks)
        cout << b << " -> ";
    cout << "NULL\n";
}