#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 0;
	int b = 0; 
	int c = 0; 
	int d = 0; 
	int e = 0;
	for(; a <= 5 ; a++){
		for(; b <= 5 ; b++){			   //**********////**********//
			for(; c <= 5 ; c++){						//
				for(; d <= 5 ; d++){					//
					for(; e <= 5 ; e++){				//
						if ((2 == b && 3 != a) || (2 != b && 3 == a) == 1){
							if ((4 == e && 2 != b) || (4 != e && 2 == b) == 1){
								if ((1 == c && 2 != d) || (1 != c && 2 == d) == 1){
									if ((5 == c && 3 != d) || (5 != c && 3 == d) == 1){
										if ((4 == e && 1 != a) || (4 != e && 1 == a) == 1){
											if (((a != b) && (a != c) && (a != d) && (a != e))
													&& ((b != c) && (b != d) && (b != e))
													&& ((c != d) && (c != e))
													&& ((d != e))){
												printf("a= %d, b= %d,c= %d,d= %d,e= %d\n", 
															a, b, c, d, e);
											}
										}
									}
								}
							}	
						}
					}
				}
			}
		}
	}
	printf("Process end!\n");
	exit(0);
}
