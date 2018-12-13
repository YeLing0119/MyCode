#include <stdio.h>
#include <unistd.h>

int main()
{
	char buf[101] = {};
	char cir[5]="-/|\\";	
	
	//printf("\033[?25l");	//隐藏光标
	
	for(int i = 0 ; i < 100 ; i++)
	{
		static int per = 1;
		buf[i] = '#';
		printf("\r[%-100s] [%c] %d%%", buf, cir[i%4] ,per);	
		fflush(stdout);
		usleep(100000);
		per += 1;
	}
	//printf("\033[0m\n");	//显示光标并换行
	printf("\n");
}


