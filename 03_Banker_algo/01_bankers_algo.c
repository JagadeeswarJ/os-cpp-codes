#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int isSafe(int processes[], int avail[], int max[][MAX_RESOURCES], int allot[][MAX_RESOURCES], int n, int m)
{
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safeSeq[MAX_PROCESSES];
    int work[MAX_RESOURCES];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }

    while (count < n)
    {
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                int canAllocate = 1;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = 0;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allot[i][j];
                    }
                    finish[i] = 1;
                    safeSeq[count++] = i;
                    found = 1;
                    break;
                }
            }
        }
        if (!found)
        {
            printf("System is in an unsafe state.\n");
            return 0;
        }
    }

    printf("System is in a safe state.\nSafe Sequence: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", safeSeq[i]);
    }
    printf("\n");

    return 1;
}

int main()
{
    int processes[MAX_PROCESSES] = {0, 1, 2, 3, 4};
    int avail[MAX_RESOURCES] = {3, 3, 2};

    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}};

    int allot[MAX_PROCESSES][MAX_RESOURCES] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}};

    int n = 5;
    int m = 3;

    isSafe(processes, avail, max, allot, n, m);

    return 0;
}
