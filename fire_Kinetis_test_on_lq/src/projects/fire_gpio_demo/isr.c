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

void USART1_IRQHandler(void)
{
    uint8 ch;

    DisableInterrupts;		    //关总中断

    //接收一个字节数据并回发
    ch=uart_getchar (UART1);        //接收到一个数据
    uart_sendStr  (UART1,"\n你发送的数据为：");
    uart_putchar (UART1,ch);        //就发送出去

    EnableInterrupts;		    //开总中断
}
    
void PORTA_IRQHandler()
  {
    unsigned int  c,d;
    extern unsigned char a;
    if(PORTA_ISFR & 1<<26)
    {
      PORTA_ISFR |= 1<<26;
      LCD_clear();
      LCD_write_english_string(0, 0, "interrupt is ok");
                  for(d=0;d<50;d++)
              { c=500000;
                    while(c--);
              }
                              

    }
  }

