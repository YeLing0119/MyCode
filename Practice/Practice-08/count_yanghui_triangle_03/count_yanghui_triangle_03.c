#include <stdio.h>

void PrintYangHui(int* Arr,int line){
	int count = 0;
	int space_count = line;
	for (int now_line = 0; now_line <= line; now_line++){
		for (int i = space_count; i > 0; i--){
			printf(" ");
		}
		space_count -= 1;
		for (int ele_count = 0; ele_count < now_line; ele_count++){
			printf("%d ", Arr[count]);
			count++;
		}
		printf("\n");
	}
}

void CountYangHui(int line){
	int Arr[1024] = { 0 };
	int now_line_count = 0;
	int before_line_count = 0;
	for (int now_line = 1; now_line <= line; now_line++){
		if (now_line == 1){
			Arr[now_line_count] = 1; now_line_count++;
		}
		if (now_line == 2){
			Arr[now_line_count] = 1; now_line_count++;
			Arr[now_line_count] = 1; now_line_count++;
			before_line_count = now_line_count - now_line;
		}
		if (now_line >= 3){
			for (int ele_count = 1; ele_count <= now_line; ele_count++){
				if (ele_count == 1){
					Arr[now_line_count] = 1; now_line_count++;
					continue;
				}
				if (ele_count == now_line){
					Arr[now_line_count] = 1; now_line_count++;
					before_line_count = now_line_count - now_line;
					continue;
				}
				Arr[now_line_count] = Arr[before_line_count] + Arr[before_line_count + 1];
				now_line_count++; before_line_count++;
			}
		}
	}

	PrintYangHui(Arr, line);
}

int main(){
	int line = 0;
	printf("*********打印杨辉三角*********\n");
	printf("请输入你要打印多少行：");
	scanf("%d", &line);
	CountYangHui(line);
	return 0;
}
