#include<stdio.h>

void round_robin(int burst_time[], int n, int time_quantum) {
    int remaining_time[n];
    int waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    for(int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }

    int t = 0;
    while(1) {
        int done = 1;
        for(int i = 0; i < n; i++) {
            if(remaining_time[i] > 0) {
                done = 0;
                if(remaining_time[i] > time_quantum) {
                    t += time_quantum;
                    remaining_time[i] -= time_quantum;
                } else {
                    t += remaining_time[i];
                    waiting_time[i] = t - burst_time[i];
                    remaining_time[i] = 0;
                }
            }
        }
        if(done == 1)
            break;
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n];
    printf("Enter burst times for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("Burst time for process P%d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    round_robin(burst_time, n, time_quantum);

    return 0;
}
