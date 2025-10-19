#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    pid_t childpid;
    int status;
    childpid = fork();
    printf("PID: %d", getpid());
    if (childpid < 0) {
        exit(EXIT_FAILURE);
    }
    else if (childpid == 0) {
        waitpid(%d);
        printf("successfully forked. starting process.. child pid: %d\n", getpid());
        sleep(2);
        printf("child process is exiting.. pid: %d\n", getpid());
        exit(EXIT_SUCCESS);
        kill(childpid);
    }
    else {
        printf("parent process (pid: %d) is waiting for child (pid %d)..\n", getpid(), childpid);
        waitpid(-1);
        
    }
}

