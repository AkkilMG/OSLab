#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    /**
     * 
     * Child process: Hello, i'm the child!
    Child process: My PID is 17680
    Child process: My parent's PID is 17679
    Parent process: Hello, I'm the parent!
    Parent process: My PID is 17679
    Parent process: My parent's PID is 17680
    Parent process: Child process terminated normally.
    */
    pid_t pid;
    // fork a child process using vfork()
    pid = vfork();
    if (pid == -1) {
        // forking failed
        perror("vfork");
        return 1;
    } else if (pid == 0) {
        // child process
        printf("Child process: Hello, i'm the child!\n");
        printf("Child process: My PID is %d\n", getpid());
        printf("Child process: My parent's PID is %d\n", getppid());
        // Terminate the child process
        exit(0);
    } else {
        // Parent process 
        printf("Parent process: Hello, I'm the parent!\n");
        printf("Parent process: My PID is %d\n", getpid());
        printf("Parent process: My parent's PID is %d\n", pid);
        // Wait for the child process to terminate
        int status;
        waitpid(pid, &status, 0);
        if(WIFEXITED(status)) {
            printf("Parent process: Child process terminated normally.\n");
        } else {
            printf("Parent process: Child process terminated abnormally.\n");
        }
    }
    return 1;
}