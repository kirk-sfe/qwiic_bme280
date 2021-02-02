/**
 * Copyright (c) 2020 SparkFun Electronics
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"
#include "qwiic_bme280.h"


BME280 mySensor;

int main() {

	const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
	gpio_put(LED_PIN, 1);


    // setup uart in pico sdk
	//setup_default_uart();
    stdio_init_all();

	printf("Starting BME280 Test\n\n");

    // Init the system 

    if(!mySensor.begin()){
    	printf("Error starting the sensor/i2c detection of sensor. Aboarting\n");
  		return 0;
    }

    while (1) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);

        printf("LOOP \n");
        
        printf("Humidity: %f\n", mySensor.readFloatHumidity());

  		printf(" Pressure: %f\n", mySensor.readFloatPressure());

  		printf(" Alt: %f\n", mySensor.readFloatAltitudeFeet());

  		printf(" Temp: %f\n", mySensor.readTempF());

    	gpio_put(LED_PIN, 0);
        sleep_ms(2000);

    }

    return 0;
}
