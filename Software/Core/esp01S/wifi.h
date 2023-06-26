#ifndef __WIFI_H
#define __WIFI_H

#include "usart.h"
#include "main.h"

#define SSID "Nixie"
#define Pwd "12345678"
#define WIFIPort "80"

#define TIME_TCP_ADDRESS "quan.suning.com"
#define TIME_TCP_PORT "80"
#define TIME_TCP_INFO  "GET http://quan.suning.com/getSysTime.do HTTP/1.1\r\nHost: quan.suning.com\r\n\r\n" 


#define WEATHER_TCP_ADDRESS "api.seniverse.com"
#define WEATHER_TCP_PORT		"80"
#define WEATHER_TCP_INFO 		"GET /v3/weather/now.json?key=STLLySYxJdYqO35LL&location=ip&language=en&unit=c"
#define BufSize 512

void Delay(__IO uint32_t nCount);

void WIFI_SendCommand(UART_HandleTypeDef *usarthandle ,uint8_t *str);//命令发送函数

void WIFI_Init(void);
void WIFI_isAlive(void);
void WIFI_WhatsmySSID(void);
void WIFI_Ping(void);
void WIFI_FWUpdate(void);
void WIFI_GetTime(void);
void WIFI_GetWeather(void);
#endif
