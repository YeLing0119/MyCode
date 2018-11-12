#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
struct student{
	int id;
	char name[20];
};

int main(){
	int shmid = shmget(1234, 0 ,0 );
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}

	struct student *stu = (struct student*)shmat(shmid, NULL, 0);
	if(stu == NULL){
		perror("shmat");
		exit(1);
	}
	
	stu->id = 1;
	strcpy(stu->name,"ls -al");
	sleep(60);
	shmdt(stu);
	exit(0);
}
