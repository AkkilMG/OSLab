#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    /**
    This is the parent process with PID: 12074
    Child process PID: 12082
    This is the child process with PID: 12082
    Parent process PID: 12074
    README.md  process  process.c
    Child process exited with status: 0
    */
    pid_t pid;
    int status;
    pid = fork();
    if(pid<0) {
        printf("Error: fork() failed.\n");
        return 1;
    } else if (pid==0) {
        printf("This is the child process with PID: %d\n", getpid());
        printf("Parent process PID: %d\n", getppid());

        execlp("/bin/pwd", "ls", NULL);
        printf("This should not be printed if exec() is successful.\n");
        return 0;
    } else {
        printf("This is the parent process with PID: %d\n", getpid());
        printf("Child process PID: %d\n", pid);
        wait(&status);
        printf("Child process exited with status: %d\n", status);
        return 0;
    }
}