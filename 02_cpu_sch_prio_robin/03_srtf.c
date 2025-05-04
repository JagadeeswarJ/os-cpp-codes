#include <stdio.h>

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

int main()
{
    int n, currentTime = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("Process %d (AT BT): ", p[i].id);
        scanf("%d %d", &p[i].arrivalTime, &p[i].burstTime);
        p[i].remainingTime = p[i].burstTime;
        p[i].waitingTime = 0;
        p[i].turnaroundTime = 0;
        p[i].completionTime = 0;
    }

    while (completed < n)
    {
        int idx = -1;
        int minRT = 1e9;

        for (int i = 0; i < n; i++)
        {
            if (p[i].arrivalTime <= currentTime && p[i].remainingTime > 0 && p[i].remainingTime < minRT)
            {
                minRT = p[i].remainingTime;
                idx = i;
            }
        }

        if (idx != -1)
        {
            p[idx].remainingTime--;
            currentTime++;

            if (p[idx].remainingTime == 0)
            {
                p[idx].completionTime = currentTime;
                p[idx].turnaroundTime = p[idx].completionTime - p[idx].arrivalTime;
                p[idx].waitingTime = p[idx].turnaroundTime - p[idx].burstTime;
                completed++;
            }
        }
        else
        {
            currentTime++; // No process is ready, CPU is idle
        }
    }

    double totalWT = 0, totalTAT = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        totalWT += p[i].waitingTime;
        totalTAT += p[i].turnaroundTime;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrivalTime, p[i].burstTime,
               p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
    }

    printf("\nAverage Waiting Time: %.2lf", totalWT / n);
    printf("\nAverage Turnaround Time: %.2lf\n", totalTAT / n);

    return 0;
}
