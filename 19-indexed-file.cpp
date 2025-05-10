#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> files(10, 0);
    int index_block = 3;
    vector<int> blocks = {5, 7, 9};

    if (files[index_block])
    {
        cout << "Index block already allocated\n";
        return 0;
    }
    files[index_block] = 1;
    for (int b : blocks)
    {
        if (files[b])
        {
            cout << "Block " << b << " already allocated\n";
            return 0;
        }
        files[b] = 1;
    }
    cout << "File Allocated with index block " << index_block << "\n";
    cout << "Blocks are: ";
    for (int b : blocks)
        cout << b << " ";
}