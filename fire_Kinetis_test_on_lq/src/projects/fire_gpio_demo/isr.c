/******************** (C) COPYRIGHT 2011 Ұ��Ƕ��ʽ���������� ********************
 * �ļ���       ��isr.c
 * ����         ���жϴ�������
 *          
 * ʵ��ƽ̨     ��Ұ��kinetis������
 * ��汾       ��
 * Ƕ��ϵͳ     ��
 *
 * ����         ��Ұ��Ƕ��ʽ���������� 
 * �Ա���       ��http://firestm32.taobao.com
 * ����֧����̳ ��http://www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
**********************************************************************************/	



#include "common.h"
#include "include.h"

void USART1_IRQHandler(void)
{
    uint8 ch;

    DisableInterrupts;		    //�����ж�

    //����һ���ֽ����ݲ��ط�
    ch=uart_getchar (UART1);        //���յ�һ������
    uart_sendStr  (UART1,"\n�㷢�͵�����Ϊ��");
    uart_putchar (UART1,ch);        //�ͷ��ͳ�ȥ

    EnableInterrupts;		    //�����ж�
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

