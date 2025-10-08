#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int rc = fork();
    int wc;
    if (rc == 0) {
        wc = wait(NULL);
        printf("Hello from child! pid: %d, wait()returned %d\n", (int) getpid(), wc);
    }
    else {
        wc = wait(NULL);
        printf("parent pid: %d, child pid %d. wait() returne %d\n ", (int) getpid(), rc, wc);
    }
    return 0;
}
