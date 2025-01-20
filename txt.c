#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

  
    pid = fork();
    if (pid < 0) { 
        fprintf(stderr, "Fork Failed\n");
        exit(-1);
    } else if (pid == 0) { 
        execlp("/bin/ls", "ls", NULL);
       
        fprintf(stderr, "execlp Failed\n");
        exit(-1);
    } else { 
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}
