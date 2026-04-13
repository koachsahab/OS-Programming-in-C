#include <stdio.h>

int main() {
    int n = 3;             // Number of processes
    int quantum = 4;       // Time Quantum
    int pid[] = {1, 2, 3};
    int bt[] = {10, 5, 8}; // Burst Times
    int rem_bt[n];         // Remaining Burst Times
    int wt[n], tat[n];
    int t = 0;             // Current time
    
    // Initialize remaining burst times
    for (int i = 0; i < n; i++) rem_bt[i] = bt[i];

    // 1. Calculate Waiting Times
    while (1) {
        int done = 1; // Flag to check if all processes are finished
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is still a pending process
                
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i]; // Waiting time = Total time - Burst time
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1) break;
    }

    // 2. Calculate Turnaround Times
    for (int i = 0; i < n; i++) tat[i] = bt[i] + wt[i];

    // 3. Display Results
    printf("=======================================================\n");
    printf(" Round Robin (Quantum: %d) | Credit: Mr. Dinesh Kumar\n", quantum);
    printf("=======================================================\n");
    printf("PID\tBurst\tWaiting\tTurnaround\n");

    float total_wt = 0, total_tat = 0;
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
