typedef unsigned long ulong;
typedef unsigned int uint;

#include <mysql.h>
#include <my_global.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){
	if(argc != 2){
		fprintf(stderr, "usage: c-demo <name>");
		exit(-1);
	}

	printf("pam:  %s %s \n", argv[0], argv[1]);
	
	// 	创建 MYSQL 结构
	// 	MYSQL *mysql_init(
	// 		MYSQL *mysql		// 创建给NULL
	// 	)
	//
	// 	功能: 	获取或初始化MYSQL结构/句柄
	// 	参数:	创建给NULL
	// 			重新初始化给句柄指针
	// 	返回值:	MYSQL 操作句柄
	MYSQL *con = mysql_init(NULL);
	if(con == NULL){
		printf("Create MYSQL structure Failure!\n");
		exit(-1);
	}

	//	连接 MYSQL 数据库
	//	MYSQL *mysql_real_connect(
	//		MYSQL *mysql, 			MYSQL 句柄
	//		const char *host, 		主机名(IP地址或者localhost)
	//		const char *user,		用户名 
	//		const char *passwd, 	密码(不需要用户手动加密，这个借口会为你自动完成)
	//		const char *db, 		指定数据库名称
	//		unsigned int port, 		指定端口
	//		const char *unix_socket,	给NULL
	//		unsigned long client_flag	给0
	//	)
	//	功能:	连接到MySQL
	//	返回值: 成功 MYSQL的操作句柄 与 第一个参数一样
	//			NULL 失败
	if(NULL == mysql_real_connect(con, "localhost", "root", "*******", "scott", 0, NULL, 0)){
		printf("Connect MySQL Database  Failure \n");
		exit(-1);
	}

	//	设置
	//	int mysql_set_character_set(
	//		MYSQL *mysql, 			// MYSQL 操作句柄
	//		const char *csname		// 字符集名称
	//	)
	//	功能: 	设置字符集为指定的字符集
	//	返回值: 成功	0
	//			失败	非零
	if(mysql_set_character_set(con,"utf8") != 0){
		printf("Set Charactor Set Failure\n");
		exit(-1);
	}

	// 	查询数据
	// 	int mysql_query(
	// 		MYSQL *mysql, 			MYSQL 句柄
	// 		const char *stmt_str	查询字符串
	// 	)
	//	功能:	执行MYSQL语句
	//	返回值: 成功	0
	//			失败	非零
	char query[1024] = {0};
	sprintf(query, "SELECT * FROM emp WHERE ename = '%s';", argv[1]);
	printf("[%s]\n", query);

	if(mysql_query(con, query) != 0){
		printf("Query Failure\n %s", mysql_error(con));
		exit(-1);
	}
	
	// 	获取查询结果
	// 	MYSQL_RES *mysql_store_result(
	// 		MYSQL *mysql		MYSQL 句柄
	// 	)
	// 	功能:	获取mysql_query之后的结果
	// 	返回值: 成功	一个MYSQL_RES 结构
	// 			失败	NULL
	MYSQL_RES *res = mysql_store_result(con);
	if(res == NULL){
		printf("Get Query Result Failure \n");
		exit(-1);
	}
	// 	unsigned int mysql_num_fields(
	// 		MYSQL_RES *result		MYSQL_RES 结构
	// 	)
	//	功能:	获取 MYSQL_RES 中有多少行数据
	//	返回值: 结构集中数据的行数
	unsigned int num_col = mysql_num_fields(res);
	printf("Total col = %d\n", num_col);
	
	MYSQL_ROW row;		// 结果集中的一行数据

	//	获取结果集中的一行数据
	// 	MYSQL_ROW mysql_fetch_row(
	// 		MYSQL_RES *result		MYSQL_RES 结果集
	// 	)
	while((row = mysql_fetch_row(res))){
		// 	unsigned long *mysql_fetch_lengths(
		// 		MYSQL_RES *result
		// 	)
		// 	功能:	获取当前行列的长度
		unsigned long *num_row = mysql_fetch_lengths(res);
		for(int i = 0 ; i < num_col; i++){
			printf("[%.*s]", (int)num_row[i], row[i] == NULL ? NULL : row[i]);
		}
		printf("\n");
	}

	mysql_free_result(res);

	mysql_close(con);
}


