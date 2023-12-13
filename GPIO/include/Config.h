/*
 * Config.h
 *
 * Archivo de configuración para el manejo de pines GPIO en ESP32.
 * Define pines, niveles lógicos, y direcciones de registros GPIO.
 *
 * Autor: mabl
 *
 */
#ifndef COMPONENTS_GPIO_INCLUDE_CONFIG_H_
#define COMPONENTS_GPIO_INCLUDE_CONFIG_H_

// Definiciones de pines
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_8 8
#define PIN_9 9
#define PIN_10 10
#define PIN_11 11
#define PIN_12 12
#define PIN_13 13
#define PIN_14 14
#define PIN_15 15
#define PIN_16 16
#define PIN_17 17
#define PIN_18 18
#define PIN_19 19
#define PIN_21 21
#define PIN_22 22
#define PIN_23 23
#define PIN_25 25
#define PIN_26 26
#define PIN_27 27
#define PIN_32 32
#define PIN_33 33
#define PIN_34 34
#define PIN_35 35
#define PIN_36 36
#define PIN_39 39

// Niveles lógicos para pines
#define HIGH 1
#define LOW  0

#define true 1
#define false 0

// Direcciones de los registros GPIO
#define GPIO_OUT_REG     ((volatile uint32_t*)0x3FF44004)
#define GPIO_ENABLE_REG  ((volatile uint32_t*)0x3FF44020)
#define GPIO_IN_REG     ((volatile uint32_t*)0x3FF4403C)
#define GPIO_PIN_REG_BASE 0x3FF44088


#endif /* COMPONENTS_GPIO_INCLUDE_CONFIG_H_ */
