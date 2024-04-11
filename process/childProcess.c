#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h> 

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("I am the child process\n");
        printf("Child process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());
    } else {
        printf("I am the parent process\n");
        printf("Parent process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());
    }

    return 0;
}
