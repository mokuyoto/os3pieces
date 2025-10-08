#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "forking failed");
        exit(1);
    }
    else if (rc == 0) {
        printf("Child: hello, pid: %d\n", (int) getpid());
    }
    else {
        usleep(1000);
        printf("Parent: goodbye, child pid: %d, my pid: %d\n", rc, (int) getpid());
    }
    
    return 0;
}
