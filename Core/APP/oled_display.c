#include "MyApplication.h"

u8g2_t u8g2;
void oled_init(I2C_HandleTypeDef *oledi2c)
{
    u8g2Init(&u8g2,*oledi2c);
    u8g2_ClearBuffer(&u8g2);
}

