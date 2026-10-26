#include "I2C_Pilote.h"

uint8_t readDigitalInputsI2C(unsigned char ucAddresse, I2C_HandleTypeDef *I2C) 
{
    uint8_t inputs = 0;
    HAL_I2C_Master_Receive(I2C, ucAddresse << 1, &inputs, 1, HAL_MAX_DELAY);
    return inputs;
}

void writeDigitalInputsI2C(unsigned char ucAddresse, I2C_HandleTypeDef *I2C, uint8_t *Data) 
{
    HAL_I2C_Master_Transmit(I2C, ucAddresse << 1, Data, 1, HAL_MAX_DELAY);
}