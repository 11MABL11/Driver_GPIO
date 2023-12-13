#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../components/GPIO/include/GPIO.h"

//Uso de dos botones: btn1 entre pin 23 y vcc
//					  btn2 entre pin 14 y tierra
void app_main(void)
{
	//Establecer el pin 23 Y 14 como entrada
	pinMode(PIN_23, INPUT);
	pinMode(PIN_14, INPUT);
	//Establecer valores de pull
	setPullMode(PIN_14,PULL_UP);
	setPullMode(PIN_23,PULL_DOWN);
	printf("Ejemplo de entradas con pull-up y pull-down\n");
    while (true) {
    	// Imprime el valor del pin
    	printf("Pin 14 state: %d\n", digitalRead(PIN_14));
    	printf("Pin 23 state: %d\n", digitalRead(PIN_23));
    	// Espera 5 segundos
    	sleep(5);
    }
}
