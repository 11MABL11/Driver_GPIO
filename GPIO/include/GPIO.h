/*****************************************************************************
 * GPIO.h
 * Descripción: Archivo de encabezado para el manejo de GPIO en ESP32.
 *
 * Este archivo define enumeraciones y estructuras relacionadas con el
 * manejo de pines GPIO en la plataforma ESP32. También incluye las
 * declaraciones de funciones para el control de los pines GPIO, como
 * la configuración del modo, escritura, lectura y configuración de resistencias.
 *
 * Autor: mabl
 ****************************************************************************/
#ifndef COMPONENTS_GPIO_INCLUDE_GPIO_H_
#define COMPONENTS_GPIO_INCLUDE_GPIO_H_

#include "Config.h"

// Modos de operación para los pines
typedef enum {
    INPUT,		// Modo de entrada
    OUTPUT		// Modo de salida
} PinMode;

// Estructura para representar la configuración de un pin
typedef struct {
    uint8_t pinNumber;		// Número del pin GPIO
    PinMode mode;			// Modo de operación del pin (INPUT o OUTPUT)
} PinConfig;

// Modos de resistencia pull-up/pull-down para los pines
typedef enum {
    PULL_UP,		// Resistencia pull-up
    PULL_DOWN,		// Resistencia pull-down
    PULL_NONE		// Sin resistencia pull
} PullMode;

// Funciones para el manejo de GPIO
// Configura el modo de operación (entrada/salida) de un pin GPIO.
extern void pinMode(uint8_t pin, PinMode mode);
// Establece el valor (alto/bajo) de un pin GPIO.
extern void digitalWrite(uint8_t pin, uint8_t value);
// Lee el valor actual (alto/bajo) de un pin GPIO.
extern uint8_t digitalRead(uint8_t pin);
// Configura la resistencia pull-up/pull-down de un pin GPIO.
extern void setPullMode(uint8_t pin, PullMode mode);

#endif /* COMPONENTS_GPIO_INCLUDE_GPIO_H_ */
