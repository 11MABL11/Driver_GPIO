#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../components/GPIO/include/GPIO.h"

//Led conectado entre el pin 2 y tierra
void app_main(void)
{
	//Establecer el pin 2 como salida
	pinMode(PIN_2, OUTPUT);
	printf("Ejemplo de blink\n");
    while (true) {
    	// Escribir un valor en el pin (encender el LED)
        digitalWrite(PIN_2, HIGH);
		printf("Enciende\n");
		//Espera 1 segundo
		sleep(1);
		// Escribir un valor en el pin (apagar el LED)
		digitalWrite(PIN_2, LOW);
		printf("Apaga\n");
		//Espera 1 segundo
		sleep(1);
    }
}
