//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//测试硬件：单片机STM32F103RCT6,正点原子MiniSTM32开发板,主频72MHZ，晶振12MHZ
//QDtech-OLED液晶驱动 for STM32
//xiao冯@ShenZhen QDtech co.,LTD
//公司网站:www.qdtft.com
//淘宝网站：http://qdtech.taobao.com
//wiki技术网站：http://www.lcdwiki.com
//我司提供技术支持，任何技术问题欢迎随时交流学习
//固话(传真) :+86 0755-23594567 
//手机:15989313508（冯工） 
//邮箱:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com
//技术支持QQ:3002773612  3002778157
//技术交流QQ群:324828016
//创建日期:2018/8/27
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 深圳市全动电子技术有限公司 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================电源接线================================================//
// OLED模块               STM32单片机
//   VCC         接       DC 5V/3.3V      //OLED屏电源正
//   GND         接          GND          //OLED屏电源地
//=======================================液晶屏数据线接线==========================================//
//本模块默认数据总线类型为4线制SPI
// OLED模块               STM32单片机
//   D1          接          PB15        //OLED屏SPI写信号
//=======================================液晶屏控制线接线==========================================//
// OLED模块               STM32单片机
//   CS          接          PB11        //OLED屏片选控制信号
//   RES         接          PB12        //OLED屏复位控制信号
//   DC          接          PB10        //OLED屏数据/命令选择控制信号
//   D0          接          PB13        //OLED屏SPI时钟信号
//=========================================触摸屏接线=========================================//
//本模块不带触摸功能，所以不需要触摸屏接线
****************************************************************************************************/	
/***************************************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
****************************************************************************************************/	
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "gui.h"
#include "test.h"
int main(void)
{	
	delay_init();	    	       //延时函数初始化	  
	NVIC_Configuration(); 	   //设置NVIC中断分组2:2位抢占优先级，2位响应优先级 	
	OLED_Init();			         //初始化OLED  
	OLED_Clear(0);             //清屏（全黑）
	OLED_WR_Byte(0x2E,OLED_CMD);        //关闭滚动
  OLED_WR_Byte(0x27,OLED_CMD);        //水平向左或者右滚动 26/27
  OLED_WR_Byte(0x00,OLED_CMD);        //虚拟字节
	OLED_WR_Byte(0x00,OLED_CMD);        //起始页 0
	OLED_WR_Byte(0x07,OLED_CMD);        //滚动时间间隔
	OLED_WR_Byte(0x07,OLED_CMD);        //终止页 7
	OLED_WR_Byte(0x00,OLED_CMD);        //虚拟字节
	OLED_WR_Byte(0xFF,OLED_CMD);        //虚拟字节
	TEST_MainPage();
	OLED_WR_Byte(0x2F,OLED_CMD);        //开启滚动
	while(1) 
	{	
		//TEST_MainPage();         //主界面显示测试
		

		//TEST_MainPage();
		/*OLED_Clear(0); 
		Test_Color();            //刷屏测试
		OLED_Clear(0); 
		Test_Rectangular();      //矩形绘制测试
		OLED_Clear(0); 
		Test_Circle();           //圆形绘制测试
		OLED_Clear(0); 
		Test_Triangle();         //三角形绘制测试
		OLED_Clear(0);  
		
		TEST_English();          //英文显示测试
		OLED_Clear(0);
		TEST_Number_Character(); //数字和符号显示测试
		OLED_Clear(0); 
		
		TEST_Chinese();          //中文显示测试
		OLED_Clear(0); 
		TEST_BMP();              //BMP单色图片显示测试
		OLED_Clear(0); 
		TEST_Menu1();            //菜单1显示测试
		OLED_Clear(0); 
		TEST_Menu2();            //菜单2显示测试
		OLED_Clear(0); */
	}
}
