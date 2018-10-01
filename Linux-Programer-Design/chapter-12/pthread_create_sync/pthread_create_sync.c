#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *thread_function(void *arg);

char message[]="Hi Bye!\n";
int run_row=1;
int main()
{
	int res;
	pthread_t a_pthread;
	void *thread_result;
	res = pthread_create(&a_pthread,NULL,thread_function,(void *)message);
	if(res!=0)
	{
		perror("Thread creation failed\n");
		exit(EXIT_FAILURE);	
	}
	
	int print_count1=0;
	
	while(print_count1++<20)
	{
		if(run_row==1)
		{
			printf("1");
			run_row=2;
		}
		else{
			sleep(1);
		}
	}
	
	printf("\nWaitting join thread to finish ...\n");	

	res = pthread_join(a_pthread,&thread_result);
	if(res!=0)
	{
		perror("Thread join failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined\n");
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	int print_count2=0;
	
	while(print_count2++<20)
	{
		if(run_row==2){
			printf("2");
			run_row=1;
		}
		else{
			sleep(1);
		}
	}
	//printf("Thread running Argument was %s\n",(char *)arg);
	sleep(3);
	//strcpy(message,"Bye Bye Bye!\n");
	//pthread_exit("Thank you for cpu time!\n");
}
