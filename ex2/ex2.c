// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? SURE, WHY NOT. What happens when they are written to the file concurrently?
// LOL is this questions asking, "what happens when the child and parent are written to the file concurrently?"
// I DONT KNOW, WRITING SYSTEM PROCESSES TO FILES SEEMS A BIT ABSURDIST, BUT OK. CONSIDER IT DONE FAM.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	// Your code here
	FILE *fp;

	fp = fopen("text.txt", "w");
	int rc = fork();
	// ------------------------------------------------ child process starts executing here
	if (rc < 0)
	{ // fork failed; exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{ // child process satisfies this branch
		FILE *iCaNhAsACeSs = fp;
		fprintf(iCaNhAsACeSs, "hello, child here (pid: %d) \n", (int)getpid());
	}
	else
	{
		FILE *iCaaaaaaaaaaaaNhAsACeSs = fp;
		fprintf(iCaaaaaaaaaaaaNhAsACeSs, "hello, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
	}

	return 0;
}
