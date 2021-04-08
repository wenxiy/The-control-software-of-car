#include <msp430g2553.h>
#include "mathfun.h"
#include "lcd.h"

//将 1 位的 int 型数据转换，返回‘字符’的子函数
char int2char(int input)
{
	return 0x30+input;
}

void drawint(unsigned int num,unsigned char col,unsigned char row)
{
	LCD_drawCharAt(int2char((num)%10),col+4,row);
	LCD_drawCharAt(int2char((num/10)%10),col+3,row);
	LCD_drawCharAt(int2char((num/100)%10),col+2,row);
	LCD_drawCharAt(int2char((num/1000)%10),col+1,row);
	LCD_drawCharAt(int2char((num/10000)%10),col+0,row);
}

void drawsignedint(int input,unsigned char col,unsigned char row)
{	
	int num;		  
	if(input<0){LCD_drawCharAt('-',col+0,row);num=-input;}else{LCD_drawCharAt('+',col+0,row);num=input;}
	LCD_drawCharAt(int2char((num)%10),col+5,row);
	LCD_drawCharAt(int2char((num/10)%10),col+4,row);
	LCD_drawCharAt(int2char((num/100)%10),col+3,row);
	LCD_drawCharAt(int2char((num/1000)%10),col+2,row);
	LCD_drawCharAt(int2char((num/10000)%10),col+1,row);
}

void drawlongint(unsigned long int num,unsigned char col,unsigned char row)
{
	LCD_drawCharAt(int2char((num)%10),col+9,row);
	LCD_drawCharAt(int2char((num/10)%10),col+8,row);
	LCD_drawCharAt(int2char((num/100)%10),col+7,row);
	LCD_drawCharAt(int2char((num/1000)%10),col+6,row);
	LCD_drawCharAt(int2char((num/10000)%10),col+5,row);
	LCD_drawCharAt(int2char((num/100000)%10),col+4,row);
	LCD_drawCharAt(int2char((num/1000000)%10),col+3,row);
	LCD_drawCharAt(int2char((num/10000000)%10),col+2,row);
	LCD_drawCharAt(int2char((num/100000000)%10),col+1,row);
	LCD_drawCharAt(int2char((num/1000000000)%10),col+0,row);
}

void drawsignedfloat2_2(float input,unsigned char col,unsigned char row)
{																	   
	float num;		  
	if(input<0){
		LCD_drawCharAt('-',col+0,row);
		num=-input;
	}else{
		LCD_drawCharAt('+',col+0,row);
		num=input;
	}
	LCD_drawCharAt(int2char((int)(num/10)%10),col+1,row);
	LCD_drawCharAt(int2char((int)(num/1)%10),col+2,row);
	LCD_drawCharAt('.',col+3,row);
	LCD_drawCharAt(int2char((int)((num-(int)num)*10)%10),col+4,row);
	LCD_drawCharAt(int2char((int)((num-(int)num)*100)%10),col+5,row);
}

void drawsignedfloat5_2(float input,unsigned char col,unsigned char row)
{																	   
	float num;		  
	if(input<0){
		LCD_drawCharAt('-',col+0,row);
		num=-input;
	}else{
		LCD_drawCharAt('+',col+0,row);
		num=input;
	}
	LCD_drawCharAt(int2char((int)(num/10000)%10),col+1,row);
	LCD_drawCharAt(int2char((int)(num/1000)%10),col+2,row);
	LCD_drawCharAt(int2char((int)(num/100)%10),col+3,row);
	LCD_drawCharAt(int2char((int)(num/10)%10),col+4,row);
	LCD_drawCharAt(int2char((int)(num)%10),col+5,row);
	LCD_drawCharAt('.',col+6,row);
	LCD_drawCharAt(int2char((int)((num-(int)num)*10)%10),col+7,row);
	LCD_drawCharAt(int2char((int)((num-(int)num)*100)%10),col+8,row);
}

