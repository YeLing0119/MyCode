#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	for(int i = 0 ; i < 10 ; i++)
	{
		perror("%d",i);
	}	
}
