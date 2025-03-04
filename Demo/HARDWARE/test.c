#include "test.h"

//---------------U8g2测试函数

//#define SEND_BUFFER_DISPLAY_MS(u8g2, ms)\
//  do {\
//    u8g2_SendBuffer(u8g2); \
//    HAL_Delay(ms);\
//  }while(0);


//进度条显示
void testDrawProcess(u8g2_t *u8g2)
{
	for(int i=10;i<=80;i=i+2)
	{
		u8g2_ClearBuffer(u8g2); 
			
		char buff[20];
		sprintf(buff,"%d%%",(int)(i/80.0*100));
		
		u8g2_SetFont(u8g2,u8g2_font_ncenB12_tf);
		u8g2_DrawStr(u8g2,16,32,"STM32 U8g2");//字符显示
		
		u8g2_SetFont(u8g2,u8g2_font_ncenB08_tf);
		u8g2_DrawStr(u8g2,100,49,buff);//当前进度显示
		
		u8g2_DrawRBox(u8g2,16,40,i,10,4);//圆角填充框矩形框
		u8g2_DrawRFrame(u8g2,16,40,80,10,4);//圆角矩形
		
		u8g2_SendBuffer(u8g2);
	}
	HAL_Delay(500);
}
//环形测试
void testDrawMulti(u8g2_t *u8g2)
{
	u8g2_ClearBuffer(u8g2);
  
	//实心矩形逐渐变大
    u8g2_ClearBuffer(u8g2);
	for(int i=30; i>0; i-=2)
	{
		u8g2_DrawBox(u8g2,i*2,i,128-i*4,64-2*i);
		u8g2_SendBuffer(u8g2);
	}

}


void u8g2DrawTest(u8g2_t *u8g2)
{
	testDrawProcess(u8g2);
	testDrawMulti(u8g2);
}
