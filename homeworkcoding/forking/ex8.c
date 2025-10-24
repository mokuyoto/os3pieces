#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd[2];
    pipe(fd); // pipe .... fd[2] is declared, and -> [0] and [1].
    // kernel fills both of them as 0 to read and 1 to write ALWAYS...

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[1]); // close write end....
        char msg[100];
        read(fd[0], msg, sizeof(msg)); // read data sent by parent... 
        printf("Child received: %s\n", msg);
        close(fd[0]);
    }
    else {
        close(fd[0]); // close read end...
        char *text = "Hello from parent!";
        write(fd[1], text, strlen(text) + 1); // write data to child
        close(fd[1]);
    }
}
