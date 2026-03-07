/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : curr_sense.h
  * @brief          : Header for curr sense driver
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include "stm32l4xx_hal.h"

uint32_t Curr_CalculateCurrentSense(uint32_t adc_value);
