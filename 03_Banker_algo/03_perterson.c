#include <stdio.h>
#include <stdbool.h>

bool flag[2] = {false, false};
int turn;

void peterson(int i)
{
    int j = 1 - i;
    flag[i] = true;
    turn = j;
    while (flag[j] && turn == j)
        ;
    printf("Process %d is in critical section\n", i);
    flag[i] = false;
}

int main()
{
    peterson(0);
    peterson(1);
    return 0;
}
