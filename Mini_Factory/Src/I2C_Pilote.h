#ifndef I2C_PILOTE_H
#define I2C_PILOTE_H

#include "main.h"

uint8_t readDigitalInputsI2C(unsigned char ucAddresse, I2C_HandleTypeDef *I2C);
void writeDigitalInputsI2C(unsigned char ucAddresse, I2C_HandleTypeDef *I2C, uint8_t *Data);
#endif