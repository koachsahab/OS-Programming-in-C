#include <stdio.h>

int main() {
    int n = 4; // Number of processes
    int pid[] = {1, 2, 3, 4};
    int bt[] = {6, 8, 2, 3}; // Burst Times
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    // 1. Sort processes by Burst Time (Smallest to Largest)
    // Using simple Bubble Sort
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap Burst Time
                int temp_bt = bt[i];
                bt[i] = bt[j];
                bt[j] = temp_bt;
                // Swap Process ID to keep track
                int temp_pid = pid[i];
                pid[i] = pid[j];
                pid[j] = temp_pid;
            }
        }
    }

    // 2. Calculate Waiting Time (WT)
    wt[0] = 0; // The shortest job starts immediately
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i-1] + wt[i-1];
    }

    // 3. Calculate Turnaround Time (TAT)
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // 4. Display Results
    printf("=======================================================\n");
    printf(" SJF Scheduling (Non-Preemptive) | Credit: Mr. Dinesh Kumar\n");
    printf("=======================================================\n");
    printf("PID\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("-------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("=======================================================\n");

    return 0;
}
