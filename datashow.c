/*************************************************************************
 * 文件名称：datashow.c
 * 作    者：whg
 * 创建时间：2017年10月17日 星期二 11时28分21秒
 * 模块名称：
 * 主要函数：
 * 版    本：
 * 修改记录：
 ************************************************************************/

#include "datashow.h"
//显示内存数据   前面会有地址显示：地址    每行显示多少个   一共显示多少个
void ShowDataAddr (uint8 *ucbuf, uint8 kuan, uint32 uilong)
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
//显示内存数据   地址    每行显示多少个   一共显示多少个
void ShowData(uint8 *ucbuf, uint8 kuan, uint32 uilong)
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


//显示函数地址，函数不能有入参
void ShowFunctionName(void *func)
{
	void *funcname = &func;
	backtrace_symbols_fd(&func, 1, 1);
}
