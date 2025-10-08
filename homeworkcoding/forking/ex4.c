#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc == 0) {
        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
        printf("This line will never run if execvp succeeds!\n");
    }
    else {
        wait(NULL);
    }
}
