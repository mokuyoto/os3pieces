#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    size_t bytes_written;
    const char *message1 = "This is a test message\n";
    const char *message2 = "This is a second test message\n";
    int fd = open("new_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening/creating file\n");
        exit(1);
    }

    printf("creating new file... the process is pid: %d\n", (int) getpid());
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("Child will perform write.. pid: %d\n", (int) getpid());
        bytes_written = write(fd, message2, strlen(message2));
        if (bytes_written == -1) {
            perror("Error writing to file\n");
            close(fd);
            return 1;
        }
        else if(bytes_written < strlen(message2)) {
            fprintf(stderr, "Warning: Partial write occured. Only %zd bytes written.\n", bytes_written);
        }
        printf("Successfully written to 'new_file.txt'\n");
        close(fd);
    }
    else {
        printf("Parent writing to file... pid %d\n", rc, (int) getpid());
        bytes_written = write(fd, message1, strlen(message1));
        if (bytes_written == -1) {
            perror("Error writing to file\n");
            close(fd);
            return 1;
        }
        else if (bytes_written < strlen(message1)) {
            fprintf(stderr, "Warning: Partial write occured. Only %zd bytes written.\n", bytes_written);
        }    
        printf("Successfully written to 'new_file.txt'\n");
        close(fd);
    }
    return 0;
}
