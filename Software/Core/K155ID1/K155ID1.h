#ifndef __K155ID1_H
#define __K155ID1_H

#include "DS3231_IIC.h"

#define ALL_CURR 114514

typedef enum 
{
	ON,
	OFF,
}Nixie_Status;

typedef enum
{
	ONE,
	TWO,
	THREE,
	FOUR,
	ALL
}Nixie_Which;

typedef struct
{
	Nixie_Which me;
	int num;
	Nixie_Status Sta;
}Nixie;

extern _calendar_obj calendar;


void Nixie_Display_Set(Nixie_Which i, Nixie_Status status);
void Nixie_Num_Set (Nixie_Which i,int Num);
void Nixie_Self_Chk(void);




#endif
