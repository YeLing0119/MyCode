#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void *thread_function(void *arg);

char message[]="Hi Bye!\n";

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

	res = pthread_join(a_pthread,&thread_result);
	if(res!=0)
	{
		perror("Thread join failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Thread join success! - It returned %d\n",(char *)thread_result);
	printf("Message is now %s",message);
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	printf("Thread running Argument was %s\n",(char *)arg);
	sleep(3);
	strcpy(message,"Bye Bye Bye!\n");
	pthread_exit("Thank you for cpu time!\n");
}
