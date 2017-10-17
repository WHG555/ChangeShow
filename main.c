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


void ShowDataAddr (uint8 *ucbuf, uint32 uilong, uint8 kuan)
{
	uint32 ulong,i;
	ulong = uilong;
	printf("%p: ",ucbuf);
	for(i=0;i<uilong;i++)
	{
		printf("%02x ",ucbuf[i]);
		if(i%kuan == kuan-1)
		{
			printf("\n");
			printf("%p: ",ucbuf+i);
		}
		if(i == uilong-1)   
		{
			printf("\n");
			return;
		}
	}

}
void ShowData(uint8 *ucbuf, uint32 uilong, uint8 kuan)
{
	uint32 ulong,i;
	ulong = uilong;
	for(i=0;i<uilong;i++)
	{
		printf("%02x ",ucbuf[i]);
		if(i%kuan == kuan-1)
		{
			printf("\n");
		}
		if(i == uilong-1)   
		{
			printf("\n");
			return;
		}
	}

}
void main (void)
{
	uint8 buf[64];
	printf("show data\n");
	printf("long is %ld\n", sizeof(long));
	ShowData(buf, 64, 15);
}
