#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    printf("hello (pid:%d)\n", (int) getpid());
    int rc = fork();

    if(rc < 0) {
        fprintf(stderr, "forking failed\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("hello i'm child (pid: %d)\n", (int) getpid());
    }
    else {
        printf("hello, i am parent of %d (pid: %d)\n", rc, (int) getpid());
    }
    return 0;
}
