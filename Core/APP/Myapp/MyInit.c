/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"


/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void Peripheral_Set(void); 

/* Public variables-----------------------------------------------------------*/
MyInit_t MyInit = 
{
	Peripheral_Set
};

/* Private function prototypes------------------------------------------------*/      


/*
	* @name   Peripheral_Set
	* @brief  ��������
	* @param  None
	* @retval None      
*/
static void Peripheral_Set()
{
    oled_init(&hi2c2);
//    MPU6050_Init(&hi2c1);
}

/********************************************************
  End Of File
********************************************************/
