#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    int x = 100;
    printf("Hello, this is process x: %d\n", x);
    
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "forking failed.\n");
        exit(1);
    }
    else if (rc == 0) {
        x = 25;
        printf("Hello, i'm child. (pid: %d), x is %d\n", (int) getpid(), x);
    }
    else {
        x = 30;
        printf("Hello, i am parent of %d (pid:%d), x is %d\n", rc, (int) getpid(), x);
    }

    return 0;
}
