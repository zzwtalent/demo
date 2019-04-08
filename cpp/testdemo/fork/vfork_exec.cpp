#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
	printf("before vfork_exec\n");
	printf("I am vfork_exec.pid[%d].ppid[%d]\n", getpid(), getppid());
	printf("end vfork_exec\n");
}
