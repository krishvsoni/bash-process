#include<stdio.h>

void fcfs(int burst_time[], int n) {
    int waiting_time[n], turnaround_time[n];
    float total_waiting_time = 0, total_turnaround_time = 0;

    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];

    for(int i = 1; i < n; i++) {
        waiting_time[i] = turnaround_time[i - 1];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n];
    printf("Enter burst times for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("Burst time for process P%d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    fcfs(burst_time, n);

    return 0;
}
