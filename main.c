#include "msp430g2553.h"
#include "lcd.h"
#include "mathfun.h"
#define uint unsigned int


void int_gpio();
void pwm1();
void pwm2();
void changepwm1(int n);
void changepwm2(int n);
void addrightspeed(int left,int right);
void addleftspeed(int left,int right);
void stop();
void scan();
void cutrightspeed(int left,int right);
void cutleftspeed(int left,int right);
void volte(int left,int right);//大转弯
int io1=0;
int io2=0;
int io3=0;
int io4=0;
int io5=0;
int io11,io21,io31,io41,io51;
int cishu = 0; 
int zhan1 = 35; //控制左边占空比
int zhan2 = 35;//控制右边占空比
int flag =1;
int flag1 = 1;
int flag2 = 1;
int time = 10;
int angle = 0;
int flag3 = 0;


void delay(){
 uint i=100; 
  while(i--);
  
}
void delay1(){
  uint i=100000; 
  while(i--); 
}

/*******************************Main*******************************/
void main( void )
{
  
  WDTCTL=WDTPW+WDTHOLD;
  // Stop watchdog timer to prevent time out reset
  P1DIR |= BIT0;//设置P1.3为输出口
  P1OUT &=~BIT0;
  
  P2DIR |= BIT5;//设置P1.3为输出口
  P2OUT &=~BIT5;
  
  P2DIR |= BIT3;
  P2DIR |= BIT4;
  P2OUT |= BIT3;
  P2OUT |= BIT4; 
  delay1();
  LCD_init();
  int_gpio();
  pwm1();
  pwm2(); 
  LCD_drawStrAt("time:",12,0,0);
  LCD_drawStrAt("angle:",12,0,2);
  while(flag2)
  {
    drawint(time,6,0);
    drawint(angle,6,2);
    if(flag3 == 2 || flag3 > 2)
    {
      flag2 = 0;
    }
    
  }
//  if(time == 10)
//    {
//      drawint(10,4,0);
//      zhan1 = 
//        zhan2 = 
//    }
//    if(time == 15)
//    {
//      drawint(15,4,0);
//      zhan1 = 
//      zhan2 =
//    }
//    if(time == 20)
//    {
//      drawint(20,4,0);
//      zhan1 = 
//      zhan2 =
//    }
   
while(1)
{

  if(flag1 == 1)
  {
  scan();

  while(flag == 1)
  {
    scan();
    if((io1 == 0) && (io2 == 0) && (io3 == 0) && (io4 == 1) && (io5 == 0))
    {
      //允许控制电机
      changepwm1(zhan1); //控制右边的电机
      changepwm2(zhan2);//控制左边的电机
      flag = 0;
    }
  }
  
//  if((io1 && io2 && io3 || io4 || io5) == 1)      
//  { 
//    io1 = io11;
//    io2 = io21;
//    io3 = io31;
//    io4 = io41;
//    io5 = io51;
//   }
      
    if(io3 == 1)//小车往左边偏
    {
//      cutrightspeed(zhan1,zhan2);     
//      delay();
//      addrightspeed(zhan1,zhan2);
      P1OUT &=~BIT0;
      changepwm2(56);
      changepwm1(0);
      delay();
      changepwm2(20);
      changepwm1(20);
      delay();
      changepwm2(56);
      changepwm1(0);
        
    }
  
    if(io5 == 1)//小车往右边偏
    {
//      cutleftspeed(zhan1,zhan2);
//      delay();
//      addleftspeed(zhan1,zhan2);
      P1OUT &=~BIT0;
      changepwm2(0);
      changepwm1(50);
      delay();
      changepwm2(20);
      changepwm1(20);
      delay();
      changepwm2(0);
      changepwm1(50);
    }
  
    if((io1 || io2) == 1)  //小车开始大转弯
    {     

      P1OUT |= BIT0;
      changepwm2(85);
      changepwm1(72);
      
    }
    
  if(io4 == 1)
  {
    P1OUT &=~BIT0;
    changepwm2(zhan1);
    changepwm1(zhan2);    
  }
  
  scan();
  if(io1+io2+io3+io4+io5 >= 2)
  {
    if((io1+io2)!=2)
    {
    stop();
    flag1 = 0;
    P2OUT |= BIT5;
    Delay_50ms(100);
    P2OUT &=~BIT5;
    }
  }
    
//          for(i=0;i<128;i++){LCD_drawPoint(i,32);}
//          Delay_50ms(25);
//          LCD_drawCharAt('A',2,2);
//          LCD_drawCharAt('b',3,3);
//          Delay_50ms(25);
//          LCD_drawChar('C');
//          LCD_drawChar('d');
//          Delay_50ms(25);
//          LCD_drawStrAt("HelloWorld..",12,0,0);
//          LCD_drawStrAt("22222World..",12,0,1);
//          Delay_50ms(25);
//          LCD_drawStr("HelloKugou..",12);
//          LCD_drawStr("22222Kugou..",12);
//          Delay_50ms(25);
//          LCD_clear();
//          drawint(65535,0,0);
//          Delay_50ms(25);
//          drawsignedint(1234,8,0);
//          Delay_50ms(25);
//          drawlongint(987654321,0,1);
//          Delay_50ms(25);
//          drawsignedfloat2_2(3.14159,0,2);
//          Delay_50ms(25);
//          drawsignedfloat5_2(54321.12345,0,3);
//          Delay_50ms(25);
//          LCD_clearLine(0);
//          Delay_50ms(25);
//          LCD_clearLine(1);
//          Delay_50ms(25);
//          LCD_clearLine(2);
//          Delay_50ms(25);
//          LCD_clearLine(3);
//          Delay_50ms(25);
	}
//================================================
}
}

void int_gpio()
{
  //P1DIR |= BIT3;//设置P1.3为输出口
  P1DIR &=~BIT4;//设置P1.4为输入口
  P1DIR &=~BIT5;//设置P1.4为输入口
  P1DIR &=~BIT7;//设置P1.4为输入口
  P2DIR &=~BIT2;//设置P1.4为输入口
  P1DIR &=~BIT1;//设置P1.4为输入口
   
  P1OUT |=BIT3; // P1.3 pull Up.
  P1REN|=BIT3; // Enable P1.3 pull Up.
  P1IE|=BIT3;// P1.3 interrupt enabled
  P1IES |= BIT3;// P1.3 Hi/lo edge
  P1IFG&=~BIT3;// P1.3 IFG cleared
  
  P2OUT |= BIT0; // P1.3 pull Up.
  P2REN|= BIT0; // Enable P1.3 pull Up.
  P2IE|= BIT0;// P1.3 interrupt enabled
  P2IES |= BIT0;// P1.3 Hi/lo edge
  P2IFG&=~BIT0;// P1.3 IFG cleared

  
  
//  P1OUT=BIT3; // P1.3 pull Up.
//  P1REN|=BIT3; // Enable P1.3 pull Up.
//  P1IE|=BIT3;// P1.3 interrupt enabled
//  P1IES|=BIT3;// P1.3 Hi/lo edge
//  P1IFG&=~BIT3;// P1.3 IFG cleared
   _EINT();

}

void pwm1()
{
  
  TA1CTL |= TASSEL_2 + MC_1;  //选SMCLK，增计数
  P2SEL |= BIT1;
  P2DIR |= BIT1;//P2.1设为输出TA1.1
  P2OUT &=~ BIT1;
  TA1CCTL1 = OUTMOD_7;
  TA1CCR0 = 10000/200;
  TA1CCR1 = (10000/200)*0/100; //占空比：TACCR1/TACCR0
}

void pwm2()
{
  P1SEL |= BIT2 ;
  P1DIR |= BIT2 ;
  TACTL |= TASSEL_2 + MC_1 ; //选SMCLK(可以测出来)，增计数//若选ACLK,经示波器PWM时有时无
  CCTL1 = OUTMOD_7; //输出模式为复位/置位
  CCR0 = 10000/200; //SMCLK时钟频率为1.115MHZ，PWM(频率)：1.115MHZ/CCR0
  CCR1 = (10000/200) * 0/100; //占空比:CCR1/CCR0 ；
}


void changepwm1(int n)
{
  TA1CCR1 = (10000/200)*n/100; //占空比：TACCR1/TACCR0
}

void changepwm2(int n)
{
  TA0CCR1 = (10000/200)*n/100; //占空比：TACCR1/TACCR0
}

void speed(int left,int right)
{
  left = left+10;
  right = right +10;
  changepwm1(left);
  changepwm2(right); 
}

void stop()
{
  P1OUT &=~(BIT0+BIT1);
 changepwm1(0);
 changepwm2(0);
}

void addleftspeed(int left,int right)
{
  left = left ;
  right = right;
  zhan1 = left;
  zhan2 = right;
  changepwm1(left);
  changepwm2(right);  
}

void addrightspeed(int left,int right)
{
  left =  left;
  right = right + 15;
  zhan1 = left;
  zhan2 = right;
  changepwm1(left);
  changepwm2(right);  
}


void scan()
{
   if(P1IN & BIT4)
    {
    io1 = 1; //若P1.5为低电平则P1.1输出高电平
//    LCD_drawStrAt("1",5,0,0); //若P1.3为低电平
    }
   else {io1 = 0;
//   LCD_drawStrAt("0",5,0,0);
   }
   
    if(P1IN & BIT5)
    {
    io2 = 1; //若P1.5为低电平则P1.1输出高电平
//    LCD_drawStrAt("1",5,2,0); //若P1.3为低电平
    }
    else {io2 = 0;
//    LCD_drawStrAt("0",5,2,0);
    }
   
    if(P1IN & BIT7)
    {
    io3 = 1; //若P1.5为低电平则P1.1输出高电平
//    LCD_drawStrAt("1",5,4,0); //若P1.3为低电平
    }
    else {io3 = 0;
//    LCD_drawStrAt("0",5,4,0);
    }
   
    if(P1IN & BIT1)
    {
    io4 = 1; //若P1.5为低电平则P1.1输出高电平
//    LCD_drawStrAt("1",5,6,0); //若P1.3为低电平
    }
    else {io4 = 0;
//    LCD_drawStrAt("0",5,6,0);
    }
   
    if(P2IN & BIT2)
    {
    io5 = 1;//若P1.5为低电平则P1.1输出高电平
//    LCD_drawStrAt("1",5,8,0); //若P1.3为低电平

    }
    else {io5 = 0;
//    LCD_drawStrAt("0",5,8,0);
    }
   
}

void volte(int left,int right) //大转弯
{
  P1OUT ^= (BIT0+BIT1);
  left = left + 50;
  right = right +45;
  changepwm1(left);
  changepwm2(right);  
}

void cutleftspeed(int left,int right)
{
  left = left - 25;
  right = right;
  zhan1 = left;
  zhan2 = right;
  changepwm1(left);
  changepwm2(right); 
}

void cutrightspeed(int left,int right)
{
  left = left;
  right = right - 15;
  zhan1 = left;
  zhan2 = right;
  changepwm1(left);
  changepwm2(right);
}

//Port1interruptserviceroutine

#pragma vector=PORT1_VECTOR

__interrupt void Port_1(void)
{
  
  if((P1IN&BIT3)==0)
  {
    if(flag3 == 0)
    {time = time + 5;}
    if(flag3 == 1)
    {angle = angle + 10;}        
  }
  
    while(1){
    if(P1IN&BIT3){
      delay();
      break;
    }
    else{}
  }
  
  P1IFG&=~BIT3;
  
}

#pragma vector=PORT2_VECTOR

__interrupt void Port_2(void)
{
  flag3 = flag3 + 1;
  
    while(1){
    if(P2IN&BIT0){
      delay();
      break;
    }
    else{}
  }
  P2IFG&=~BIT0;
}