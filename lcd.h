#ifndef __LCD_H__
#define __LCD_H__

void Initial_LY096BG30();
void Delay_50ms(unsigned int Del_50ms);
void Delay_1ms(unsigned int Del_1ms);
void fill_picture(unsigned char fill_Data);
void Picture_1();
void IIC_Start();
void IIC_Stop();
void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Byte(unsigned char IIC_Byte);
/********************************************/
typedef struct LCDControl
{
	unsigned char row;
	unsigned char col;
}LCDControl;

void LCD_init();
void LCD_clear();
char LCD_setXY(unsigned char X, unsigned char Y);
char LCD_drawPoint(unsigned char x , unsigned char y);
char LCD_drawCharAt( char ch , unsigned char col , unsigned char row);
char LCD_drawChar(char ch);
char LCD_drawStrAt( char * str , unsigned char len , unsigned char col ,unsigned char row);
char LCD_drawStr( char * str , unsigned char len);
char LCD_clearLine(unsigned char row);
#endif