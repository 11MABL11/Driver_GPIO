/*****************************************************************************
 * GPIO.c
 * Descripción: Implementación de funciones para el manejo de GPIO en ESP32.
 *
 * Autor: mabl
 ****************************************************************************/
#include <stdio.h>
#include "GPIO.h"
/**************************************************************************
* Function: pinMode
* Preconditions: -
* Overview: Configura el modo de un pin GPIO en entrada o salida.
* Input:
*     - uint8_t pin: Número del pin GPIO.
*     - PinMode mode: Modo de configuración (INPUT o OUTPUT).
* Output: -
***************************************************************************/
void pinMode(uint8_t pin, PinMode mode) {
    if (mode == INPUT) {
    	*GPIO_ENABLE_REG &= ~(1 << pin);  // Limpia el bit para deshabilitar la salida
    } else if (mode == OUTPUT) {
        // Configurar el pin como salida
        *GPIO_ENABLE_REG |= (1 << pin);
    }

}

/**************************************************************************
* Function: digitalWrite
* Preconditions: La función pinMode debe haber sido llamada para configurar el pin.
* Overview: Establece el valor de un pin GPIO en alto o bajo.
* Input:
*     - uint8_t pin: Número del pin GPIO.
*     - uint8_t value: Valor a establecer (HIGH o LOW).
* Output: -
***************************************************************************/
void digitalWrite(uint8_t pin, uint8_t value) {
    if (value == HIGH) {
        // Establecer el bit correspondiente a pin en GPIO_OUT_REG para poner el pin en alto
        *GPIO_OUT_REG |= (1 << pin);
    } else {
        // Limpiar el bit correspondiente a pin en GPIO_OUT_REG para poner el pin en bajo
        *GPIO_OUT_REG &= ~(1 << pin);
    }
    // Puedes agregar más lógica según sea necesario
}

/**************************************************************************
* Function: digitalRead
* Preconditions: La función pinMode debe haber sido llamada para configurar el pin.
* Overview: Lee el valor de un pin GPIO.
* Input:
*     - uint8_t pin: Número del pin GPIO.
* Output:
*     - uint8_t: Valor leído (HIGH o LOW).
***************************************************************************/
uint8_t digitalRead(uint8_t pin) {
    // Lee el valor del pin
    return ((*GPIO_IN_REG >> pin) & 0x1);
}

/**************************************************************************
* Function: setPullMode
* Preconditions: La función pinMode debe haber sido llamada para configurar el pin.
* Overview: Configura la resistencia pull-up o pull-down de un pin GPIO.
* Input:
*     - uint8_t pin: Número del pin GPIO.
*     - PullMode mode: Modo de resistencia pull-up/pull-down (PULL_UP, PULL_DOWN o PULL_NONE).
* Output: -
***************************************************************************/
void setPullMode(uint8_t pin, PullMode mode) {
    // Calcula la dirección del registro GPIO_PINn_REG para el pin dado
    volatile uint32_t* pinReg = (volatile uint32_t*)(GPIO_PIN_REG_BASE + (4 * pin));

    // Configura la resistencia pull-up/pull-down según el modo especificado
    switch (mode) {
        case PULL_UP:
            *pinReg |= (1 << 0);  // Configura el bit 0 para habilitar pull-up
            *pinReg &= ~(1 << 4); // Limpia el bit 4 para deshabilitar pull-down
            break;
        case PULL_DOWN:
            *pinReg &= ~(1 << 0); // Limpia el bit 0 para deshabilitar pull-up
            *pinReg |= (1 << 4);  // Configura el bit 4 para habilitar pull-down
            break;
        case PULL_NONE:
            *pinReg &= ~(1 << 0); // Limpia el bit 0 para deshabilitar pull-up
            *pinReg &= ~(1 << 4); // Limpia el bit 4 para deshabilitar pull-down
            break;
        default:
            // Manejo de error si se proporciona un modo no válido
            break;
    }
}


