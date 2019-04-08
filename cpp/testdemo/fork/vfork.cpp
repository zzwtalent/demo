#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int vfork_test()
{
	int cpid;
	int ret;
	if((ret=vfork()) == -1)
	{
		printf("vfork failed\n");
	}else if(ret == 0)
	{
		printf("I am child.pid[%d].ppid[%d]\n", getpid(), getppid());
		char * execvp_str[] = {"vfork_exec", NULL};
//		char * execvp_str[] = {"ping", "www.baidu.com", NULL};
//		if(execvp("ping", execvp_str)<0){
		if(execvp("vfork_exec", execvp_str)<0){
/* 如果exec函数返回，表明没有正常执行命令，打印错误信息*/
			perror("error on exec");
			exit(3);
		}
		
		//_exit(0);
		exit(0);
	}else{
		//defunct僵尸进程产生
		for(int i=0 ;i <100; i++)
		{
			printf("I am parent.pid[%d].ppid[%d]\n", getpid(), getppid());
			sleep(1);
		}
	}
}


int main(int argc, char* argv[])
{
	printf("before vfork_test\n");
	vfork_test();
	printf("end vfork_test\n");
}
