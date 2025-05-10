#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> req = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53, seek = 0;

    cout << "Seek Sequence: ";
    for (int r : req) {
        cout << r << " ";
        seek += abs(head - r);
        head = r;
    }
    cout << "\nTotal Seek Time: " << seek << endl;
    return 0;
}