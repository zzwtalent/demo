#include <stdio.h>
#include <unistd.h>

int fork_test()
{
	int cpid;
	int ret;
	if((ret=fork()) == -1)
	{
		printf("fork failed\n");
	}else if(ret == 0)
	{
		printf("I am child.pid[%d].ppid[%d]\n", getpid(), getppid());
	}else{
		printf("I am parent.pid[%d].ppid[%d]\n", getpid(), getppid());
	}
}


int main(int argc, char* argv[])
{
	printf("before fork_test\n");
	fork_test();
	printf("end fork_test\n");
}
