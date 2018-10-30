#include <stdio.h>

int main(){
	char murder = 0;
	for (murder = 'A' ; murder <= 'D'; murder++){
		if((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D') == 3){
			printf("Murderer is %c\n", murder);
		}
	}
	return 0;
}
