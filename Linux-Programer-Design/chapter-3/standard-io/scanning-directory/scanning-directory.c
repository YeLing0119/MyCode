#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>

void printdir(char *dir,int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if(dp=opendir(dir)==NULL){
		fprintf(stderr,"cannot open the directory");
		return ;
	}
	
	

}
