# 伪目标
.PHONY : main clean


# $^ 代表所有依赖文件
# $@ 目标文件
# $< 第一个依赖文件
main : add.o sub.o mul.o main.o
	gcc $^ -o main 

%.o : %.c
	gcc -c $< -o $@ -I ../include/

clean :
	rm *.o main
