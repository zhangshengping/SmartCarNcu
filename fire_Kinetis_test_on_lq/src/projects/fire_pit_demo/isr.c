/******************** (C) COPYRIGHT 2011 野火嵌入式开发工作室 ********************
 * 文件名       ：isr.c
 * 描述         ：中断处理例程
 *          
 * 实验平台     ：野火kinetis开发板
 * 库版本       ：
 * 嵌入系统     ：
 *
 * 作者         ：野火嵌入式开发工作室 
 * 淘宝店       ：http://firestm32.taobao.com
 * 技术支持论坛 ：http://www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
**********************************************************************************/	



#include "common.h"
#include "include.h"


/*************************************************************************
*                             野火嵌入式开发工作室
*  
*  函数名称：PIT0_IRQHandler
*  功能说明：PIT0 定时中断服务函数
*  参数说明：无   
*  函数返回：无
*  修改时间：2012-2-18    已测试
*  备    注：
*************************************************************************/
void PIT0_IRQHandler(void)
{
    LED_turn(LED0);             //LED0反转
    PIT_Flag_Clear(PIT0);       //清中断标志位
}




