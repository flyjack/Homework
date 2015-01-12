#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define CHAR_BUFSIZE 20

int main(int argc, char **argv)
{
    int fd[2], len;
    char message[CHAR_BUFSIZE];

    if (socketpair(AF_LOCAL, SOCK_STREAM, 0, fd) == -1) 
    {
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("fork error \n");
        return 1;
    }

    //子进程
    if (pid == 0)
    {
        close(fd[0]);

        len = read(fd[1], message, CHAR_BUFSIZE-1);
        message[len] = '\0';
        printf("Read [%s] from %d \n", message, pid);
    }
    else
    {
        close(fd[1]);

        snprintf(message, CHAR_BUFSIZE, "First message");
        printf("Write [%s] from %d \n", message, pid);
        write(fd[0], message, strlen(message) + 1);
    }

    return 0;
}
