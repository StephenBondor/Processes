// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MSGSIZE 16

char *msg1 = "hello world #1\n";
char *msg2 = "hello world #2\n";
char *msg3 = "hello world #3\n";

// the command `man pipe` can be used to list the commands we can use in c! handy dandy.
int main(void)
{
	char buf1[128];
	int fd1[2];

	pipe(fd1);

	pid_t pid = fork();

	if (pid == 0)
	{
		int bytes_written1 = write(fd1[1], msg1, MSGSIZE);
		int bytes_written2 = write(fd1[1], msg2, MSGSIZE);
		int bytes_written3 = write(fd1[1], msg3, MSGSIZE);
	}
	else
	{
		int bytes_read1 = read(fd1[0], buf1, sizeof buf1);
		write(STDOUT_FILENO, buf1, bytes_read1);
	}
	return 0;
}
