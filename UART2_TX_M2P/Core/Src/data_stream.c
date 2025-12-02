/*
 * data_stream.c
 *
 *  Created on: Dec 2, 2025
 *      Author: Lenovo
 */


#include <stdint.h>
uint8_t data_stream[]= "Hello amma, acha and Udit!! This project sends string data strored in SRAM1 to UART2 and displays it in serial terminal!!";

uint32_t data_len = sizeof(data_stream)/sizeof(uint8_t);
