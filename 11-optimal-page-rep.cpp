#include <bits/stdc++.h>
using namespace std;

int findOptimal(const vector<int> &pages, const vector<int> &frames, int curr_pos)
{
    int farthest = -1, replace_pos = 0;
    for (int i = 0; i < frames.size(); i++)
    {
        auto it = find(pages.begin() + curr_pos, pages.end(), frames[i]);
        if (it == pages.end())
            return i;
        if (it - pages.begin() > farthest)
        {
            farthest = it - pages.begin();
            replace_pos = i;
        }
    }
    return replace_pos;
}

int main()
{
    const vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    vector<int> frames(3, -1);
    int page_faults = 0;

    for (int i = 0; i < pages.size(); i++)
    {
        if (find(frames.begin(), frames.end(), pages[i]) == frames.end())
        {
            auto empty = find(frames.begin(), frames.end(), -1);
            if (empty != frames.end())
            {
                *empty = pages[i];
            }
            else
            {
                int pos = findOptimal(pages, frames, i + 1);
                frames[pos] = pages[i];
            }
            page_faults++;
            cout << "Page Fault: " << pages[i] << "\n";
        }
        else
        {
            cout << "Page Hit: " << pages[i] << "\n";
        }
        cout << "Frames: ";
        for (int f : frames)
            cout << f << " ";
        cout << "\n";
    }
    cout << "Total Page Faults: " << page_faults << "\n";
    cout << "Total Page Hits: " << pages.size() - page_faults << "\n";
}
