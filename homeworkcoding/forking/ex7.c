#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        exit(EXIT_FAILURE);
    }
    else if (rc == 0) {
        close(STDOUT_FILENO);
        printf("This will not be printed on the terminal.\n");
        fflush(stdout);
        exit(EXIT_SUCCESS);
    }
    else {
        wait(NULL);
        printf("Child has finished execution..\n");
    }

    return 0;
}
