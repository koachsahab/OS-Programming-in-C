#include <stdio.h>

int main() {
    int n = 3; // Number of processes
    int processes[] = {1, 2, 3};
    int burst_time[] = {10, 5, 8};
    
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    // 1. Calculate Waiting Time (WT)
    wt[0] = 0; // First process doesn't wait
    for (int i = 1; i < n; i++) {
        wt[i] = burst_time[i-1] + wt[i-1];
    }

    // 2. Calculate Turnaround Time (TAT)
    for (int i = 0; i < n; i++) {
        tat[i] = burst_time[i] + wt[i];
    }

    // 3. Display Results
    printf("=======================================================\n");
    printf(" FCFS Scheduling | Credit: Mr. Dinesh Kumar\n");
    printf("=======================================================\n");
    printf("PID\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%d\t%d\n", processes[i], burst_time[i], wt[i], tat[i]);
    }

    printf("-------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("=======================================================\n");

    return 0;
}
