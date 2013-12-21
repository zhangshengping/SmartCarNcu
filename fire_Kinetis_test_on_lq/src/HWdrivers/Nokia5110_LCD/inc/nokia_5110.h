/*
2007-2-1 12:06
nokia 5110 driver program for 51 mcu
by zl0801

zhaoliang0801@gmail.com

*/



#ifndef __NOKIA_5110_H__
#define __NOKIA_5110_H__


/*========不常用的函数编译控制=========*/
// #define __DELAY__
// #define __PICTURE__
// #define __BMP__
// #define __CHINESE__
// #define __TEST_LCD__

#include "common.h"
#include "gpio.h"

// pin define for n5110lcd_8key board
// change this if your hardware changed!
//Nokia5110 引脚配置文件

#define   PortSCLK        PORTD
#define   PortSDIN        PORTD
#define   PortLCD_DC      PORTD
#define   PortLCD_CE      PORTD
#define   PortLCD_RST     PORTD 

//如果nokia5110lcd使用的是同一组IO口使用方便，否则要修改 nokia_5110.c中LCD_pin_config()
//gpio_init()的端口组号

#define   PortLCD         PORTD        

#define   SCLK            (PTD0_OUT)		
#define   SDIN            (PTD1_OUT)		
#define   LCD_DC          (PTD2_OUT)		
#define   LCD_CE          (PTD3_OUT)		
#define   LCD_RST         (PTD4_OUT)	



//初始化gpio口时需要用到的枚举变量，引脚号
enum LCD_Pin
{
   SCLK_Pin     = 0,		
   SDIN_Pin     = 1,		
   LCD_DC_Pin   = 2,		
   LCD_CE_Pin   = 3,		
   LCD_RST_Pin  = 4
};


void LCD_pin_config();
void LCD_init(void);
void LCD_clear(void);
//void LCD_move_chinese_string(unsigned char X, unsigned char Y, unsigned char T); 
void LCD_write_english_string(unsigned char X,unsigned char Y,char *s);



//void chinese_string(unsigned char X, unsigned char Y, unsigned char T);                 
void LCD_write_char(unsigned char c);
void LCD_write_byte(unsigned char dat, unsigned char dc);
void LCD_set_XY(unsigned char X, unsigned char Y);
void delay_1us(void);
void delay(void);
void LCD_draw_pixel(void *image, unsigned char line, unsigned char row,
                    unsigned char threshold,unsigned char X, unsigned char Y);

#ifdef __BMP__
void LCD_draw_bmp_pixel(unsigned char X,unsigned char Y,unsigned char *map,
                  unsigned char Pix_x,unsigned char Pix_y);
#endif

#ifdef __DELAY__
void delay_1ms(void);
#endif

#ifdef __TEST_LCD__
void LCD_draw_whole(unsigned char *map);
#endif

 #ifdef __CHINESE__
void LCD_write_chinese_string(unsigned char X, unsigned char Y,
                   unsigned char ch_with,unsigned char num,
                   unsigned char line,unsigned char row);
#endif

#ifdef __PICTURE__
void LCD_draw_picture(unsigned char start_x, unsigned char start_y, 
                      unsigned char *map, unsigned char line, unsigned row);
#endif
#endif