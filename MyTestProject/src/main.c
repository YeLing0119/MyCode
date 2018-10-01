#include <stdio.h>
#include <add.h>
#include <mul.h>
#include <sub.h>

int main()
{
	int a = 19, b = 3;
	printf("%d + %d = %d\n",a, b, add(a,b));
	printf("%d - %d = %d\n",a, b, sub(a,b));
	printf("%d * %d = %d\n",a, b, mul(a,b));
}
