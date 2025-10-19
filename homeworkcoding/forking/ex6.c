#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    pid_t child_pid = fork();
    int wc;
    
    if (child_pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0) {
        printf("successfully forked. child pid: %d", getpid());
    }
}
