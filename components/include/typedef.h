/*
 * typedef.h
 *
 *  Created on: 22 lut 2026
 *      Author: Wojtus
 */

#ifndef INCLUDE_TYPEDEF_H_
#define INCLUDE_TYPEDEF_H_

#pragma once

#include "stdint.h"

#define FALSE 0
#define TRUE 1

typedef uint8_t bool_t;

typedef enum Status_t
{
    STATUS_OK,
    STATUS_INVALID_PARAMS,
    STATUS_TIMEOUT_ERROR,
    STATUS_I2C_ERROR,
    STATUS_INVALID_READING,
    STATUS_ERROR
} Status_t;


#endif /* INCLUDE_TYPEDEF_H_ */
