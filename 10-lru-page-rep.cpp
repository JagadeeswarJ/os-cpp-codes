#include <bits/stdc++.h>

using namespace std;

int main()
{
    const vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    vector<int> frames(3, -1), time(3, 0);
    int page_faults = 0, counter = 0;

    for (int page : pages)
    {
        auto it = find(frames.begin(), frames.end(), page);
        if (it != frames.end())
        {
            time[it - frames.begin()] = ++counter;
            cout << "Page Hit: " << page << "\n";
        }
        else
        {
            int pos = min_element(time.begin(), time.end()) - time.begin();
            frames[pos] = page;
            time[pos] = ++counter;
            page_faults++;
            cout << "Page Fault: " << page << "\n";
        }
        cout << "Frames: ";
        for (int f : frames)
            cout << f << " ";
        cout << "\n";
    }
    cout << "Total Page Faults: " << page_faults << "\n";
    cout << "Total Page Hits: " << pages.size() - page_faults << "\n";
}
