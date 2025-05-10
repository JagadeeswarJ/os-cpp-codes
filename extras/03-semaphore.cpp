#include <bits/stdc++.h>
using namespace std;

int mutex = 1;

void wait(int &s)
{
    while (s <= 0)
        ;
    s--;
}

void signal(int &s)
{
    s++;
}

void critical(int id)
{
    wait(mutex);
    cout << "Process " << id << " in critical section\n";
    signal(mutex);
}

int main()
{
    for (int i = 1; i <= 5; i++)
        critical(i);
}