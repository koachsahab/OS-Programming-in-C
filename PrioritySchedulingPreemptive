/******************************************************************************
 * Author:      Mr. Dinesh Kumar
 * Affiliation: Rawal Institute of Engineering & Technology
 * Concept:     Preemptive Priority Scheduling (Smallest Priority # = Highest Priority)
 *****************************************************************************/

#include <stdio.h>

struct Process {
    int pid;            // Process ID
    int at;             // Arrival Time
    int bt;             // Burst Time
    int priority;       // Priority
    int rt;             // Remaining Time (for preemption)
    int ct, wt, tat;    // Completion, Waiting, and Turnaround times
};

int main() {
    int n, count = 0, time = 0, best_p;
    struct Process p[10];
    float total_wt = 0, total_tat = 0;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%d [Arrival, Burst, Priority]: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].rt = p[i].bt; // Initially, remaining time is full burst time
    }

    // Logic: At every second, find the highest priority process that has arrived
    while(count != n) {
        best_p = -1;
        int min_val = 9999; // Represents infinity

        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0 && p[i].priority < min_val) {
                min_val = p[i].priority;
                best_p = i;
            }
        }

        if(best_p != -1) {
            p[best_p].rt--; // Execute for 1 second
            
            if(p[best_p].rt == 0) { // Process finished
                count++;
                p[best_p].ct = time + 1;
                p[best_p].tat = p[best_p].ct - p[best_p].at;
                p[best_p].wt = p[best_p].tat - p[best_p].bt;
                total_wt += p[best_p].wt;
                total_tat += p[best_p].tat;
            }
        }
        time++; // Move to next second
    }

    // Output Table
    printf("\nPID\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
                p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
