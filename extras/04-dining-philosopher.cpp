#include <bits/stdc++.h>
using namespace std;

int fork_status[5] = {1, 1, 1, 1, 1};

void dine(int id)
{
    int left = id;
    int right = (id + 1) % 5;
    if (fork_status[left] && fork_status[right])
    {
        fork_status[left] = fork_status[right] = 0;
        printf("Philosopher %d is eating\n", id);
        fork_status[left] = fork_status[right] = 1;
    }
    else
    {
        printf("Philosopher %d is waiting for forks\n", id);
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        dine(i);
    }
    return 0;
}
