#include <stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];
    int t = 0;
    while (1)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;

                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {

                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("\nPN\t BT\t WT\t TAT\n");
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" %d\t %d\t %d\t %d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time = %.2f\n", (float)total_wt / (float)n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / (float)n);
}
int main()
{
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processes[n], burst_time[n];
    for (int i = 0; i < n; i++)
    {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    findavgTime(processes, n, burst_time, quantum);

    return 0;
}