#include <bits/stdc++.h>
using namespace std;

int main()
{
    const vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    vector<int> frames(3, -1);
    int page_faults = 0, next_replace = 0;

    for (int page : pages)
    {
        if (find(frames.begin(), frames.end(), page) == frames.end())
        {
            frames[next_replace] = page;
            next_replace = (next_replace + 1) % frames.size();
            page_faults++;
            cout << "Page Fault: " << page << "\n";
        }
        else
        {
            cout << "Page Hit: " << page << "\n";
        }
        cout << "Frames: ";
        for (int f : frames)
            cout << f << " ";
        cout << "\n";
    }
    cout << "Total Page Faults: " << page_faults << "\n";
    cout << "Total Page Hits: " << pages.size() - page_faults << "\n";
}