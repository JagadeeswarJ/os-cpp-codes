#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id, arrivalTime, burstTime;
    int remainingTime, completionTime, waitingTime, turnaroundTime;
};

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; ++i)
    {
        processes[i].id = i + 1;
        cout << "Process P" << processes[i].id << " (AT BT): ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
    }

    int currentTime = 0, completed = 0;
    double totalWT = 0, totalTAT = 0;

    while (completed < n)
    {
        int idx = -1, minRT = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (processes[i].arrivalTime <= currentTime &&
                processes[i].remainingTime > 0 &&
                processes[i].remainingTime < minRT)
            {
                minRT = processes[i].remainingTime;
                idx = i;
            }
        }

        if (idx != -1)
        {
            processes[idx].remainingTime--;
            currentTime++;

            if (processes[idx].remainingTime == 0)
            {
                completed++;
                processes[idx].completionTime = currentTime;
                processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
                processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;

                totalWT += processes[idx].waitingTime;
                totalTAT += processes[idx].turnaroundTime;
            }
        }
        else
        {
            currentTime++; // No process ready; CPU idle
        }
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto &p : processes)
    {
        cout << "P" << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime
             << "\t" << p.completionTime << "\t" << p.turnaroundTime
             << "\t" << p.waitingTime << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << totalWT / n << endl;
    cout << "Average Turnaround Time: " << totalTAT / n << endl;

    return 0;
}
