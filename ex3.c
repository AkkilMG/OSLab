#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void forkExampler() {
    if (fork() == 0)
        printf("Hello from child.\n");
    else
        printf("Hello from parent.\n");
}

int main() { 
    forkExampler();
    return 0;
}
