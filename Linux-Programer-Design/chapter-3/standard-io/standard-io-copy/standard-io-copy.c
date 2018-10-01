#include<stdio.h>
#include<stdlib.h>

int main()
{
	char c;
	FILE *in,*out;
	
	in=fopen("file.in","r");
	out=fopen("file.out","w");
	while((c=fgetc(in))!=EOF)
		fputc(c,out);
	
	exit(0);
}
