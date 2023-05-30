#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void forkExampler() {
    int x = 1;
    if (fork() == 0)
        printf("Child x=%d.\n", ++x);
    else
        printf("Parent x=%d.\n", --x);
}

int main() { 
    forkExampler();
    return 0;
}
