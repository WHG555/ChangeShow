/*************************************************************************
 * 文件名称：main.c
 * 作    者：whg
 * 创建时间：2017年12月26日 星期二 17时11分04秒
 * 模块名称：
 * 主要函数：
 * 版    本：
 * 修改记录：
 ************************************************************************/

#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

int main (void)
{
	sqlite3 *conn;
	if(sqlite3_open("switch.db", &conn)!=SQLITE_OK) {
		printf("打开失败%s \n",sqlite3_errmsg(conn));
	}

	char **dbresult;

	int rows,cols;
	int i,j;
	sqlite3_get_table(conn, "select * from whg", &dbresult, &rows, &cols, NULL);

	for(i=0; i<rows+1; i++) {
		for(j=0; j<cols; j++) {
			printf("%s\t", dbresult[i*cols+j]);
		}
		printf("\n");
	}
	sqlite3_get_table(conn, "insert into whg (procid, procname, protid, sigid, node) values (0, ' ', 2, 5, 'serial')", &dbresult, &rows, &cols, NULL);
	for(i=0; i<rows+1; i++) {
		for(j=0; j<cols; j++) {
			printf("%s\t", dbresult[i*cols+j]);
		}
		printf("\n");
	}

	sqlite3_free_table(dbresult);
	sqlite3_close(conn);


}
