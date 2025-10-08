#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    printf("hello world! now this process will use fork, and wait! pid:(%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed.\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("hello, i am child (pid: %d)\n", getpid());
    }
    else {
        int wc = wait(NULL);
        printf("hello, i am parent of %d (wc: %d) (pid:%d)\n", rc, wc, (int) getpid());
    }
    return 0;
}
