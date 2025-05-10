#include <bits/stdc++.h>
using namespace std;

bool flag[2] = {false, false};
int turn;

void enter_critical(int pid)
{
    int other = 1 - pid;
    flag[pid] = true;
    turn = other;
    while (flag[other] && turn == other)
    {
    }
}

void exit_critical(int pid)
{
    flag[pid] = false;
}

int main()
{
    enter_critical(0);
    cout << "Process 0 in critical section\n";
    exit_critical(0);

    enter_critical(1);
    cout << "Process 1 in critical section\n";
    exit_critical(1);
}