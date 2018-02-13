#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int fork_test()
{
	int cpid;
	int ret;
	int status;
	if((ret=fork()) == -1)
	{
		printf("fork failed\n");
	}else if(ret == 0)
	{
		printf("I am child.pid[%d].ppid[%d]\n", getpid(), getppid());
//		char * execvp_str[] = {"echo", "hello,I am child!", NULL};
		char * execvp_str[] = {"ping", "www.baidu.com", NULL};
		if(execvp("ping", execvp_str)<0){
/* 如果exec函数返回，表明没有正常执行命令，打印错误信息*/
			perror("error on exec");
			exit(3);
		}
	}else{
		printf("I am parent.pid[%d].ppid[%d]\n", getpid(), getppid());
		wait(&status);
		printf("execvp done.status[%d]\n", status);
	}
}


int main(int argc, char* argv[])
{
	printf("before fork_test\n");
	fork_test();
	printf("end fork_test\n");
}
