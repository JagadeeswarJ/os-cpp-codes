#include <stdio.h>

struct Process
{
    int pid;
    int burst_time;
    int priority;
};

void sortByPrority(struct Process proc[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n - i - 1; j++)
            if (proc[j].priority > proc[j + 1].priority)
            {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
}

void calculateTimes(struct Process proc[], int n, int wt[], int tat[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + proc[i - 1].burst_time;

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + proc[i].burst_time;
}

int main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    struct Process proc[n];
    int wt[n], tat[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for process %d:\n", i + 1);
        proc[i].pid = i + 1;
        printf("Burst time: ");
        scanf("%d", &proc[i].burst_time);
        printf("Priority: ");
        scanf("%d", &proc[i].priority);
    }

    sortByPrority(proc, n);

    calculateTimes(proc, n, wt, tat);

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].priority, wt[i], tat[i]);
    }

    return 0;
}