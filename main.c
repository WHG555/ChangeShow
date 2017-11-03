/*************************************************************************
 * 文件名称：main.c
 * 作    者：whg
 * 创建时间：2017年10月17日 星期二 00时23分19秒
 * 模块名称：
 * 主要函数：
 * 版    本：
 * 修改记录：
 ************************************************************************/

#include <stdio.h>
#include "datatypedef.h"
#include "datashow.h"
#include <execinfo.h>

int hello (int i)
{
	i += 4;
	printf("hello %d \n", i);
	return 1;
}

void main (void)
{
	uint8 buf[64];
	printf("show data\n");
	printf("long is %ld\n", sizeof(long));
	ShowData(buf, 16, 64);
	ShowDataAddr(buf, 10, 64);
	ShowFunctionName(hello);
}
