#include "K155ID1.h"


extern _calendar_obj calendar;
Nixie Nixie_One =	{ONE, 0, ON};
Nixie Nixie_Two = {TWO, 0, ON};
Nixie Nixie_Three = {THREE, 0, ON};
Nixie Nixie_Four = {FOUR, 0, ON};

void Nixie_Display_Set(Nixie_Which i, Nixie_Status status)
{
	switch(i)
	{
		case ONE :
		{
			if(status == OFF)
			{
				HAL_GPIO_WritePin(GPIOA, CS1_1_Pin|CS1_2_Pin|CS1_3_Pin|CS1_4_Pin, GPIO_PIN_SET);
				Nixie_One.Sta = OFF;
			}
			else if(status == ON)
			{
				Nixie_Num_Set (i, calendar.hour);
				Nixie_One.num = calendar.hour/10;
			}
			break;
		}
		case TWO :
		{
			if(status == OFF)
			{
				HAL_GPIO_WritePin(GPIOA, CS2_1_Pin|CS2_2_Pin|CS2_3_Pin|CS2_4_Pin, GPIO_PIN_SET);
				Nixie_Two.Sta = OFF;
			}
			else if(status == ON)
			{
				Nixie_Two.num = calendar.hour%10;
				Nixie_Num_Set (i, calendar.hour);
			}
			break;
		}
		case THREE :
		{
			if(status == OFF)
			{
				HAL_GPIO_WritePin(GPIOA, CS3_1_Pin|CS3_2_Pin|CS3_3_Pin|CS3_4_Pin, GPIO_PIN_SET);
				Nixie_Three.Sta = OFF;
			}
			else if(status == ON)
			{
				Nixie_Num_Set (i, calendar.hour);
				Nixie_Three.num = calendar.min/10;
			}
				
			break;
		}
		case FOUR :
		{
			if(status == OFF)
			{
				Nixie_Four.Sta = OFF;
				HAL_GPIO_WritePin(GPIOB, CS4_1_Pin|CS4_2_Pin|CS4_3_Pin|CS4_4_Pin, GPIO_PIN_SET);
			}
			else if(status == ON)
			{
				Nixie_Num_Set (i, calendar.min);
				Nixie_Four.num = calendar.min%10;
			}
			break;
		}
		case ALL :
		{
			if(status == OFF)
			{
				/*结构体灯管状态设置*/
				Nixie_One.Sta = OFF;
				Nixie_Two.Sta = OFF;
				Nixie_Three.Sta = OFF;
				Nixie_Four.Sta = OFF;
				/*灯管控制*/
				HAL_GPIO_WritePin(GPIOA, CS1_1_Pin|CS1_2_Pin|CS1_3_Pin|CS1_4_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, CS2_1_Pin|CS2_2_Pin|CS2_3_Pin|CS2_4_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, CS3_1_Pin|CS3_2_Pin|CS3_3_Pin|CS3_4_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOB, CS4_1_Pin|CS4_2_Pin|CS4_3_Pin|CS4_4_Pin, GPIO_PIN_SET);
			}
			else if(status == ON)
			{
				Nixie_One.Sta = ON;
				Nixie_Two.Sta = ON;
				Nixie_Three.Sta = ON;
				Nixie_Four.Sta = ON;
				Nixie_Num_Set (ALL,ALL_CURR);
			}	
			break;
		}
	}
}
void Nixie_Num_Set (Nixie_Which i,int Num)
{
	switch(i)
	{
		case ONE :
		{
			switch(Num)
			{
				case 0 :
				{
					HAL_GPIO_WritePin(GPIOA, CS1_1_Pin|CS1_2_Pin|CS1_3_Pin|CS1_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 1 :
				{
					HAL_GPIO_WritePin(GPIOA, CS1_2_Pin|CS1_3_Pin|CS1_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS1_1_Pin, GPIO_PIN_SET);
					break;
				}
				case 2 :
				{
					HAL_GPIO_WritePin(GPIOA, CS1_1_Pin|CS1_3_Pin|CS1_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS1_2_Pin, GPIO_PIN_SET);
					break;
				}
				case 3 :
				{
					HAL_GPIO_WritePin(GPIOA, CS1_1_Pin|CS1_2_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS1_3_Pin|CS1_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 4 :
				{
					HAL_GPIO_WritePin(GPIOA, CS1_1_Pin|CS1_2_Pin|CS1_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS1_3_Pin, GPIO_PIN_SET);
					break;
				}
				case 5 :
				{
					HAL_GPIO_WritePin(GPIOA, CS1_1_Pin|CS1_3_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS1_2_Pin|CS1_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 6 :
				{
					HAL_GPIO_WritePin(GPIOA, CS1_1_Pin|CS1_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS1_2_Pin|CS1_3_Pin, GPIO_PIN_SET);
					break;
				}
				case 7 :
				{
					HAL_GPIO_WritePin(GPIOA, CS1_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS1_2_Pin|CS1_3_Pin|CS1_1_Pin, GPIO_PIN_SET);
					break;
				}
				case 8 :
				{
					HAL_GPIO_WritePin(GPIOA, CS1_4_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS1_2_Pin|CS1_3_Pin|CS1_1_Pin, GPIO_PIN_RESET);
					break;
				}
				case 9 :
				{
					HAL_GPIO_WritePin(GPIOA, CS1_1_Pin|CS1_4_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS1_2_Pin|CS1_3_Pin, GPIO_PIN_RESET);
					break;
				}
			}
			break;
		}
		case TWO :
		{
			switch(Num)
			{
				case 0 :
				{
					HAL_GPIO_WritePin(GPIOA, CS2_1_Pin|CS2_2_Pin|CS2_3_Pin|CS2_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 1 :
				{
					HAL_GPIO_WritePin(GPIOA, CS2_2_Pin|CS2_3_Pin|CS2_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS2_1_Pin, GPIO_PIN_SET);
					break;
				}
				case 2 :
				{
					HAL_GPIO_WritePin(GPIOA, CS2_1_Pin|CS2_3_Pin|CS2_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS2_2_Pin, GPIO_PIN_SET);
					break;
				}
				case 3 :
				{
					HAL_GPIO_WritePin(GPIOA, CS2_1_Pin|CS2_2_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS2_3_Pin|CS2_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 4 :
				{
					HAL_GPIO_WritePin(GPIOA, CS2_1_Pin|CS2_2_Pin|CS2_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS2_3_Pin, GPIO_PIN_SET);
					break;
				}
				case 5 :
				{
					HAL_GPIO_WritePin(GPIOA, CS2_1_Pin|CS2_3_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS2_2_Pin|CS2_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 6 :
				{
					HAL_GPIO_WritePin(GPIOA, CS2_1_Pin|CS2_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS2_2_Pin|CS2_3_Pin, GPIO_PIN_SET);
					break;
				}
				case 7 :
				{
					HAL_GPIO_WritePin(GPIOA, CS2_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS2_2_Pin|CS2_3_Pin|CS2_1_Pin, GPIO_PIN_SET);
					break;
				}
				case 8 :
				{
					HAL_GPIO_WritePin(GPIOA, CS2_4_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS2_2_Pin|CS2_3_Pin|CS2_1_Pin, GPIO_PIN_RESET);
					break;
				}
				case 9 :
				{
					HAL_GPIO_WritePin(GPIOA, CS2_1_Pin|CS2_4_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS2_2_Pin|CS2_3_Pin, GPIO_PIN_RESET);
					break;
				}
			}
			break;
		}
		case THREE :
		{
			switch(Num)
			{
				case 0 :
				{
					HAL_GPIO_WritePin(GPIOA, CS3_1_Pin|CS3_2_Pin|CS3_3_Pin|CS3_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 1 :
				{
					HAL_GPIO_WritePin(GPIOA, CS3_2_Pin|CS3_3_Pin|CS3_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS3_1_Pin, GPIO_PIN_SET);
					break;
				}
				case 2 :
				{
					HAL_GPIO_WritePin(GPIOA, CS3_1_Pin|CS3_3_Pin|CS3_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS3_2_Pin, GPIO_PIN_SET);
					break;
				}
				case 3 :
				{
					HAL_GPIO_WritePin(GPIOA, CS3_1_Pin|CS3_2_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS3_3_Pin|CS3_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 4 :
				{
					HAL_GPIO_WritePin(GPIOA, CS3_1_Pin|CS3_2_Pin|CS3_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS3_3_Pin, GPIO_PIN_SET);
					break;
				}
				case 5 :
				{
					HAL_GPIO_WritePin(GPIOA, CS3_1_Pin|CS3_3_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS3_2_Pin|CS3_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 6 :
				{
					HAL_GPIO_WritePin(GPIOA, CS3_1_Pin|CS3_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS3_2_Pin|CS3_3_Pin, GPIO_PIN_SET);
					break;
				}
				case 7 :
				{
					HAL_GPIO_WritePin(GPIOA, CS3_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA, CS3_2_Pin|CS3_3_Pin|CS3_1_Pin, GPIO_PIN_SET);
					break;
				}
				case 8 :
				{
					HAL_GPIO_WritePin(GPIOA, CS3_4_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS3_2_Pin|CS3_3_Pin|CS3_1_Pin, GPIO_PIN_RESET);
					break;
				}
				case 9 :
				{
					HAL_GPIO_WritePin(GPIOA, CS3_1_Pin|CS3_4_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOA, CS3_2_Pin|CS3_3_Pin, GPIO_PIN_RESET);
					break;
				}
			}
			break;
		}
		case FOUR :
		{
			switch(Num)
			{
				case 0 :
				{
					HAL_GPIO_WritePin(GPIOB, CS4_1_Pin|CS4_2_Pin|CS4_3_Pin|CS4_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 1 :
				{
					HAL_GPIO_WritePin(GPIOB, CS4_2_Pin|CS4_3_Pin|CS4_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, CS4_1_Pin, GPIO_PIN_SET);
					break;
				}
				case 2 :
				{
					HAL_GPIO_WritePin(GPIOB, CS4_1_Pin|CS4_3_Pin|CS4_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, CS4_2_Pin, GPIO_PIN_SET);
					break;
				}
				case 3 :
				{
					HAL_GPIO_WritePin(GPIOB, CS4_1_Pin|CS4_2_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB, CS4_3_Pin|CS4_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 4 :
				{
					HAL_GPIO_WritePin(GPIOB, CS4_1_Pin|CS4_4_Pin|CS4_2_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, CS4_3_Pin, GPIO_PIN_SET);
					break;
				}
				case 5 :
				{
					HAL_GPIO_WritePin(GPIOB, CS4_1_Pin|CS4_3_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB, CS4_2_Pin|CS4_4_Pin, GPIO_PIN_RESET);
					break;
				}
				case 6 :
				{
					HAL_GPIO_WritePin(GPIOB, CS4_1_Pin|CS4_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, CS4_2_Pin|CS4_3_Pin, GPIO_PIN_SET);
					break;
				}
				case 7 :
				{
					HAL_GPIO_WritePin(GPIOB, CS4_4_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB, CS4_2_Pin|CS4_3_Pin|CS4_1_Pin, GPIO_PIN_SET);
					break;
				}
				case 8 :
				{
					HAL_GPIO_WritePin(GPIOB, CS4_4_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB, CS4_2_Pin|CS4_3_Pin|CS4_1_Pin, GPIO_PIN_RESET);
					break;
				}
				case 9 :
				{
					HAL_GPIO_WritePin(GPIOB, CS4_1_Pin|CS4_4_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB, CS4_2_Pin|CS4_3_Pin, GPIO_PIN_RESET);
					break;
				}
			}
			break;
		}
		case ALL :
		{
			if(Num == ALL_CURR)
			{
				Nixie_Num_Set(ONE,calendar.hour/10);
				Nixie_Num_Set(TWO,calendar.hour%10);
				Nixie_Num_Set(THREE,calendar.min/10);
				Nixie_Num_Set(FOUR,calendar.min%10);
			}
			else
			{
				switch(Num)
				{
					case 0 :
					{
						Nixie_Num_Set(ONE,0);
						Nixie_Num_Set(TWO,0);
						Nixie_Num_Set(THREE,0);
						Nixie_Num_Set(FOUR,0);
						break;
					}
					case 1 :
					{
						Nixie_Num_Set(ONE,1);
						Nixie_Num_Set(TWO,1);
						Nixie_Num_Set(THREE,1);
						Nixie_Num_Set(FOUR,1);
						break;
					}
					case 2 :
					{
						Nixie_Num_Set(ONE,2);
						Nixie_Num_Set(TWO,2);
						Nixie_Num_Set(THREE,2);
						Nixie_Num_Set(FOUR,2);
						break;
					}
					case 3 :
					{
						Nixie_Num_Set(ONE,3);
						Nixie_Num_Set(TWO,3);
						Nixie_Num_Set(THREE,3);
						Nixie_Num_Set(FOUR,3);
						break;
					}
					case 4 :
					{
						Nixie_Num_Set(ONE,4);
						Nixie_Num_Set(TWO,4);
						Nixie_Num_Set(THREE,4);
						Nixie_Num_Set(FOUR,4);
						break;
					}
					case 5 :
					{
						Nixie_Num_Set(ONE,5);
						Nixie_Num_Set(TWO,5);
						Nixie_Num_Set(THREE,5);
						Nixie_Num_Set(FOUR,5);
						break;
					}
					case 6 :
					{
						Nixie_Num_Set(ONE,6);
						Nixie_Num_Set(TWO,6);
						Nixie_Num_Set(THREE,6);
						Nixie_Num_Set(FOUR,6);
						break;
					}
					case 7 :
					{
						Nixie_Num_Set(ONE,7);
						Nixie_Num_Set(TWO,7);
						Nixie_Num_Set(THREE,7);
						Nixie_Num_Set(FOUR,7);
						break;
					}
					case 8 :
					{
						Nixie_Num_Set(ONE,8);
						Nixie_Num_Set(TWO,8);
						Nixie_Num_Set(THREE,8);
						Nixie_Num_Set(FOUR,8);
						break;
					}
					case 9 :
					{
						Nixie_Num_Set(ONE,9);
						Nixie_Num_Set(TWO,9);
						Nixie_Num_Set(THREE,9);
						Nixie_Num_Set(FOUR,9);
						break;
					}
				}
			break;
		}
	 }
	}
}

void Nixie_Self_Chk(void)
{
	int i;
	for(i = 0;i<10;i++)
	{
		Nixie_Num_Set(ALL,i);
		HAL_Delay(500);
	}
}
