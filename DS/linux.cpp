#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
int main()
{
	pid_t pid, pid1;
	/* fork a child process */
	pid = fork();
	if (pid < 0) { /* error occurred */
	fprintf(stderr, "Fork Failed");
	return 1;
	}
	else if (pid == 0) { /* child process */
	pid1 = getpid();
	printf("child: pid = %d",pid); /* A */
	printf("child: pid1 = %d",pid1); /* B */
	}
	else { /* parent process */
	pid1 = getpid();
	printf("parent: pid = %d",pid); /* C */
	printf("parent: pid1 = %d",pid1); /* D */
	cwait(NULL);
	}
	return 0;
}