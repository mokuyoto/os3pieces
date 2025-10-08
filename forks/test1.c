#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    printf("hi (pid: %d)\n", (int) getpid());
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "forking failed.\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("i am child (pid: %d)\n", (int) getpid());
    }
    else {
        int wc = wait(NULL);
        printf("helo, im parent of %d (wc: %d) (pid: %d)\n", rc, wc, (int) getpid());
    }

    return 0;
}
