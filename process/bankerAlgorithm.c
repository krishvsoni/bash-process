#include<stdio.h>

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int max[n][m], allocation[n][m], need[n][m], available[m];
    int finish[n], safe_sequence[n];
    
    printf("Enter maximum resources required by each process:\n");
    for(int i = 0; i < n; i++) {
        printf("For process P%d: ", i+1);
        for(int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
        finish[i] = 0;
    }

    printf("Enter allocated resources for each process:\n");
    for(int i = 0; i < n; i++) {
        printf("For process P%d: ", i+1);
        for(int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("Enter available resources: ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    int count = 0;
    while(count < n) {
        int found = 0;
        for(int i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int j;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > available[j])
                        break;
                }
                if(j == m) {
                    for(int k = 0; k < m; k++) {
                        available[k] += allocation[i][k];
                    }
                    safe_sequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0) {
            printf("System is not in safe state\n");
            return 0;
        }
    }

    printf("Safe sequence: ");
    for(int i = 0; i < n; i++) {
        printf("P%d ", safe_sequence[i] + 1);
    }
    printf("\n");

    return 0;
}
