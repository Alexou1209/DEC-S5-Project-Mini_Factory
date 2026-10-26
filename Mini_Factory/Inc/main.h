/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//PROGRAMME: 247-637 S-0009
//DESCRIPTION: programme qui va de pair avec S-0008
//HISTORIQUE:
// 2019-10-27, Yves Roy: creation
#include "stm32f4xx_hal.h"


/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CS_I2C_SPI_Pin GPIO_PIN_3
#define CS_I2C_SPI_GPIO_Port GPIOE
#define TRIAC_WRITE_Pin GPIO_PIN_4
#define TRIAC_WRITE_GPIO_Port GPIOE
#define PE6_Pin GPIO_PIN_6
#define PE6_GPIO_Port GPIOE
#define PC13_Pin GPIO_PIN_13
#define PC13_GPIO_Port GPIOC
#define PC14_OSC32_IN_Pin GPIO_PIN_14
#define PC14_OSC32_IN_GPIO_Port GPIOC
#define PC15_OSC32_OUT_Pin GPIO_PIN_15
#define PC15_OSC32_OUT_GPIO_Port GPIOC
#define PH0_OSC_IN_Pin GPIO_PIN_0
#define PH0_OSC_IN_GPIO_Port GPIOH
#define PH1_OSC_OUT_Pin GPIO_PIN_1
#define PH1_OSC_OUT_GPIO_Port GPIOH
#define OTG_FS_PowerSwitchOn_Pin GPIO_PIN_0
#define OTG_FS_PowerSwitchOn_GPIO_Port GPIOC
#define PDM_OUT_Pin GPIO_PIN_3
#define PDM_OUT_GPIO_Port GPIOC
#define B1_Pin GPIO_PIN_0
#define B1_GPIO_Port GPIOA
#define I2S3_WS_Pin GPIO_PIN_4
#define I2S3_WS_GPIO_Port GPIOA
#define PA5_Pin GPIO_PIN_5
#define PA5_GPIO_Port GPIOA
#define PA6_Pin GPIO_PIN_6
#define PA6_GPIO_Port GPIOA
#define PA7_Pin GPIO_PIN_7
#define PA7_GPIO_Port GPIOA
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define Pin1Moteur_Pin GPIO_PIN_8
#define Pin1Moteur_GPIO_Port GPIOE
#define Pin2Moteur_Pin GPIO_PIN_9
#define Pin2Moteur_GPIO_Port GPIOE
#define Pin3Moteur_Pin GPIO_PIN_10
#define Pin3Moteur_GPIO_Port GPIOE
#define Pin4Moteur_Pin GPIO_PIN_11
#define Pin4Moteur_GPIO_Port GPIOE
#define CLK_IN_Pin GPIO_PIN_10
#define CLK_IN_GPIO_Port GPIOB
#define LD4_Pin GPIO_PIN_12
#define LD4_GPIO_Port GPIOD
#define LD3_Pin GPIO_PIN_13
#define LD3_GPIO_Port GPIOD
#define LD5_Pin GPIO_PIN_14
#define LD5_GPIO_Port GPIOD
#define LD6_Pin GPIO_PIN_15
#define LD6_GPIO_Port GPIOD
#define I2S3_MCK_Pin GPIO_PIN_7
#define I2S3_MCK_GPIO_Port GPIOC
#define VBUS_FS_Pin GPIO_PIN_9
#define VBUS_FS_GPIO_Port GPIOA
#define OTG_FS_ID_Pin GPIO_PIN_10
#define OTG_FS_ID_GPIO_Port GPIOA
#define OTG_FS_DM_Pin GPIO_PIN_11
#define OTG_FS_DM_GPIO_Port GPIOA
#define OTG_FS_DP_Pin GPIO_PIN_12
#define OTG_FS_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define I2S3_SCK_Pin GPIO_PIN_10
#define I2S3_SCK_GPIO_Port GPIOC
#define I2S3_SD_Pin GPIO_PIN_12
#define I2S3_SD_GPIO_Port GPIOC
#define Audio_RST_Pin GPIO_PIN_4
#define Audio_RST_GPIO_Port GPIOD
#define OTG_FS_OverCurrent_Pin GPIO_PIN_5
#define OTG_FS_OverCurrent_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define PE0_Pin GPIO_PIN_0
#define PE0_GPIO_Port GPIOE
#define MEMS_INT2_Pin GPIO_PIN_1
#define MEMS_INT2_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

//DEFINITIONS REQUISES PAR LE PROGRAMME:
//Dependances materielles:
#define FREQUENCE_D_OSCILLATEUR_EN_KHZ  84000.0

//Dependances logicielles:
#define FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ 2000.0
#define PILOTETIMER1MODE2_TAUX_DE_BITS 19200.0
#define PILOTETIMER6UP_COMPTE_MAXIMAL  (\
  (unsigned int)((FREQUENCE_D_OSCILLATEUR_EN_KHZ \
  /FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ * 1000.0)-1.0))

#define PILOTECAN1_IDENTIFICATION_EN_TRANSMISSION  (0x245<<5)
#define PILOTECAN1_2IDENTIFICATION_EN_RECEPTION  (0x034<<5) //0x246
#define PILOTECAN1_3IDENTIFICATION_EN_RECEPTION  (0x032<<5) //0x246 
#define PILOTECAN1_IDENTIFICATION_EN_RECEPTION  (0x001<<5) //0x246
#define PILOTECAN1_MASQUE_11_BITS_EN_RECEPTION  (0xFFF) //0xfff
#define SERVICEPROTOCOLE637_FREQUENCE_MAXIMALE_DES_TRANSMISSIONS_EN_HZ 500.0
#define SERVICEPROTOCOLE637_NOMBRE_DE_DONNEES_MAXIMUM  16
#define SERVICEPROTOCOLE637_DEBUT_DE_TRAME  '$'    //0x24
#define SERVICEPROTOCOLE637_INSERTION 0x00
#define SERVICEPROTOCOLE637_TEMPS_D_ATTENTE_MAXIMAL_EN_MS 4
#define SERVICEPROTOCOLE637_FREQUENCE_MAXIMALE_DES_LECTURES_EN_HZ 2000.0

#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES  12
#define SERVICEPROTOCOLE637_PHASE_RECEPTION 0
#define SERVICEPROTOCOLE637_PHASE_TRANSMISSION 1
#define INTERFACES0008_PHASE_RECEPTION 2
#define INTERFACES0008_PHASE_TRANSMISSION 3
#define PROCESSUSPASSERELLECAN637_CAN_TO_637 4
#define PROCESSUSPASSERELLECAN637_637_TO_CAN 5
#define PROCESSUSASCENCEUR_EN_FONCTION 6
#define PROCESSUSCENTREDETRI_EN_FONCTION 7
#define PROCESSUS_CLIGNOTE 8
#define PROCESSUSCAN_RECEIVE 9
#define PROCESSUSCAN_SEND 10
#define PROCESSUSTRIAC_EN_FONCTION 11



//INFORMATION PUBLIQUE:
//Definitions publiques:
#define INFORMATION_DISPONIBLE  1
#define INFORMATION_TRAITEE  0
#define REQUETE_ACTIVE  1
#define REQUETE_TRAITEE 0
#define MODULE_EN_FONCTION 1
#define MODULE_PAS_EN_FONCTION 0

//Fonctions publiques:
void neFaitRien(void);

//Variables publiques:
//copiez et adaptes les lignes qui suivent dans les fichiers .h des modules
//qui utilisent ces variables qui sont definies par htim6
//extern TIM_HandleTypeDef htim6;
//extern UART_HandleTypeDef huart2;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
