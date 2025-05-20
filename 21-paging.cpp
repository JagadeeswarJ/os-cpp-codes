#include <bits/stdc++.h>
using namespace std;

int main()
{
    int pages = 4;
    vector<int> page_table = {2, 0, 3, 1}; // page i is stored in frame page_table[i]

    cout << left << setw(10) << "Page No" << "Frame No\n";
    cout << "-------------------\n";
    for (int i = 0; i < pages; i++)
    {
        cout << setw(10) << i << page_table[i] << endl;
    }

    // Optional: converting logical address to physical address
    int page_size = 100; // Assume each page is 100 bytes
    int logical_address;
    cout << "\nEnter logical address (0 to " << pages * page_size - 1 << "): ";
    cin >> logical_address;

    int page_no = logical_address / page_size;
    int offset = logical_address % page_size;
    int frame_no = page_table[page_no];
    int physical_address = frame_no * page_size + offset;

    cout << "Logical Address → Page: " << page_no << ", Offset: " << offset << endl;
    cout << "Physical Address = " << physical_address << endl;

    return 0;
}
