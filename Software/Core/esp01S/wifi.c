#include "wifi.h"

#include <string.h>
#include <stdio.h>

#include "oled.h"
char Timejson[64];
char Weatherjson[];
char* SysTime2;
char* SysTime1;
extern uint8_t JSON_RCVD;
extern uint8_t IT_Status;
extern uint8_t RxBuf[BufSize];
extern uint8_t RxChar;

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}


void WIFI_SendCommand(UART_HandleTypeDef *usarthandle ,uint8_t *str)
{
	unsigned int k=0;
  do
  {
      HAL_UART_Transmit(usarthandle,(uint8_t *)(str + k) ,1,1000);
      k++;
  } while(*(str + k)!='\0');
	//HAL_UART_Transmit(usarthandle,(uint8_t *)"\r\n" ,2,1000);
}

void WIFI_Init(void)
{
	//WIFI_SendCommand(&huart3, (uint8_t *)"AT\r\n");
	
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CWMODE_DEF=1\r\n");//设置为AP模式

	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CWLAP\r\n");//查找附近wifi
	Delay(1000);
	char wificmd[40];
	sprintf(wificmd, "AT+CWJAP_DEF=\"%s\",\"%s\"\r\n", SSID, Pwd);//连接热点
	WIFI_SendCommand(&huart3,(uint8_t *)&wificmd);

}

void WIFI_isAlive(void)
{
	WIFI_SendCommand(&huart3, (uint8_t *)"AT\r\n");
}
void WIFI_WhatsmySSID(void)
{
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CWJAP?\r\n");
}

void WIFI_Ping(void)
{
	char wificmd[40];
	sprintf(wificmd,"AT+PING=\"www.baidu.com\"\r\n");
	WIFI_SendCommand(&huart3, (uint8_t *)wificmd);
}

void WIFI_FWUpdate(void)
{
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CIUPDATE\r\n");
}
extern uint8_t Get_STA;
void WIFI_GetTime(void)
{
	char cmd[256];
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CIPMUX=0\r\n");
	Delay(1000000);
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CIPMODE=1\r\n");
	Delay(1000000);
	sprintf(cmd,"AT+CIPSTART=\"TCP\",\"%s\",80\r\n",TIME_TCP_ADDRESS);
	WIFI_SendCommand(&huart3, (uint8_t *)cmd);
	Delay(9000000);
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CIPSEND\r\n");
	Delay(9000000);
	//Get_STA = 1;
	WIFI_SendCommand(&huart3, (uint8_t *)TIME_TCP_INFO);
	Delay(9000000);
	WIFI_SendCommand(&huart3, (uint8_t *)"+++");
	Delay(9000000);
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CIPCLOSE\r\n");
}
void WIFI_GetWeather()
{
	char cmd[256];
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CIPMUX=0\r\n");
	Delay(1000000);
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CIPMODE=1\r\n");
	Delay(1000000);
	sprintf(cmd,"AT+CIPSTART=\"TCP\",\"%s\",80\r\n",WEATHER_TCP_ADDRESS);
	WIFI_SendCommand(&huart3, (uint8_t *)cmd);
	Delay(9000000);
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CIPSEND\r\n");
	Delay(9000000);
	//Get_STA = 1;
	WIFI_SendCommand(&huart3, (uint8_t *)WEATHER_TCP_INFO);
	Delay(9000000);
	WIFI_SendCommand(&huart3, (uint8_t *)"+++");
	Delay(9000000);
	WIFI_SendCommand(&huart3, (uint8_t *)"AT+CIPCLOSE\r\n");
}




