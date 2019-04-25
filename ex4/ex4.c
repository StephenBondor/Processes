// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call? BECAUSE THEY WANTED TO
// SUPPORT THIS FEATURE, UNLIKE THOUSANDS OF OTHER FEATURES.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	// Your code here

	pid_t pid = fork();

	if (pid == 0)
	{
		execlp("ls", "ls", NULL);

		// If we got this far, exec failed, so print an error message.
		// (perror() is in stdio.h)
		perror("exec");
		exit(1);
	}
	else
	{
		// This line guarantees that the child will run first:
		wait(NULL);

		printf("I'm the parent!\n");
	}

	return 0;
}
// execl
// execlp
// execle
// execv
// execve
// execvP
// execvp