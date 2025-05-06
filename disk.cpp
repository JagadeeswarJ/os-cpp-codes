#include <bits/stdc++.h>
using namespace std;

void sortVector(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}

void FCFS(const vector<int> &req, int head)
{
    int seek = 0;
    cout << "Seek Sequence: ";
    for (int r : req)
    {
        cout << r << " ";
        seek += abs(head - r);
        head = r;
    }                
    cout << "\nTotal Seek Time: " << seek << endl;
}

void SSTF(vector<int> req, int head)
{
    int seek = 0;
    vector<bool> done(req.size(), false);
    cout << "Seek Sequence: ";
    for (int c = 0; c < req.size(); c++)
    {
        int minDist = INT_MAX, idx = -1;
        for (int i = 0; i < req.size(); i++)
        {
            if (!done[i] && abs(head - req[i]) < minDist)
            {
                minDist = abs(head - req[i]);
                idx = i;
            }
        }
        seek += minDist;
        head = req[idx];
        done[idx] = true;
        cout << head << " ";
    }
    cout << "\nTotal Seek Time: " << seek << endl;
}

void SCAN_CSCAN_LOOK_CLOOK(vector<int> req, int head, int size, int type)
{
    int seek = 0;
    vector<int> left, right;

    for (int r : req)
    {
        if (r < head)
            left.push_back(r);
        else
            right.push_back(r);
    }

    if (type == 3 || type == 4)
    {
        left.push_back(0);
        right.push_back(size - 1);
    }

    sortVector(left);
    sortVector(right);

    cout << "Seek Sequence: ";
    if (type == 3 || type == 5)
    { // SCAN or LOOK
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
    }
    else
    { // CSCAN or CLOOK
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
            for (int i = 0; i < left.size(); i++)
            {
                cout << left[i] << " ";
                if (i > 0)
                    seek += abs(head - left[i]);
                head = left[i];
            }
        }
    }
    cout << "\nTotal Seek Time: " << seek << endl;
}

int main()
{
    int n, head, size, choice;
    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> req(n);
    cout << "Enter request sequence:\n";
    for (int i = 0; i < n; i++)
        cin >> req[i];

    cout << "Enter initial head position: ";
    cin >> head;
    cout << "Enter disk size: ";
    cin >> size;

    cout << "\nChoose Algorithm:\n";
    cout << "1.FCFS 2.SSTF 3.SCAN 4.CSCAN 5.LOOK 6.CLOOK\nChoice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        FCFS(req, head);
        break;
    case 2:
        SSTF(req, head);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        SCAN_CSCAN_LOOK_CLOOK(req, head, size, choice);
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
