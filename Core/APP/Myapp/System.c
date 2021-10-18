/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void Run(void); 
static void Error_handler(void);
static void Assert_Failed(void);
	
/* Public variables-----------------------------------------------------------*/
System_t System = 
{
	Run,
	Error_handler,
	Assert_Failed
};

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   Run
	* @brief  系统运行
	* @param  None
	* @retval None      
*/
static void Run()
{
    char Temp[5]="0";
    char a[15]="0",g[15]="0";
    char Angle[10]="0";
    MPU6050_Read_All(&hi2c1,&MPU6050);
    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_unifont_tr);
    sprintf(Temp,"%.1f",MPU6050.Temperature);
    sprintf(a,"x%.1f y%.1f z%.1f",MPU6050.Ax,MPU6050.Ay,MPU6050.Az);
    sprintf(g,"x%.1f y%.1f z%.1f",MPU6050.Gx,MPU6050.Gy,MPU6050.Gz);
    sprintf(Angle,"X%.1f Y%.1f",MPU6050.KalmanAngleX,MPU6050.KalmanAngleY);
    u8g2_DrawStr(&u8g2,2,10,Temp);
    u8g2_DrawStr(&u8g2,40,10,Angle);
    u8g2_DrawStr(&u8g2,2,30,a);
    u8g2_DrawStr(&u8g2,2,50,g);
    u8g2_SendBuffer(&u8g2);
//    HAL_Delay(100);
}

/*
	* @name   Error_Handler
	* @brief  系统错误处理
	* @param  None
	* @retval None      
*/
static void Error_handler()
{
	/* User can add his own implementation to report the HAL error return state */
}

/*
	* @name   Assert_Failed
	* @brief  函数参数错误处理
	* @param  None
	* @retval None      
*/
static void Assert_Failed()
{
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
/********************************************************
  End Of File
********************************************************/
