/*************************************************************************
 * 文件名称：datashow.h
 * 作    者：whg
 * 创建时间：2017年10月17日 星期二 11时28分42秒
 * 模块名称：
 * 主要函数：
 * 功    能：
 * 版    本：
 * 与其他文件的关系：
 * 修改记录：
 ************************************************************************/
#ifndef __DATASHOW_H__
#define __DATASHOW_H__

#include <stdio.h>
#include <execinfo.h>
#include "../include/datatypedef.h"


void ShowDataAddr (uint8 *ucbuf, uint8 kuan, uint32 uilong);
void ShowData(uint8 *ucbuf, uint8 kuan, uint32 uilong);
void ShowFunctionName(void *func);

#endif

