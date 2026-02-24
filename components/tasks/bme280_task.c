/*
 * bme280_task.c
 *
 *  Created on: 24 Feb 2026
 *      Author: Wojciech Niewiadomski
 */

 #include "bme.h"
 #include "freertos/FreeRTOS.h"
 #include "freertos/task.h"
 #include "esp_log.h"

 static const char *TAG = "bme_task";

 static void BME280_Task(void *arg)
 {
	 BME280_Init();
	 BME280_Data_t bmeData = {.humidity = 0, .pressure = 0, .temperature = 0};
     while (1)
     {
         bmeData = BME280_ReadData();

		 ESP_LOGI(TAG, "Temperature: %.2f C", bmeData.temperature);
		 ESP_LOGI(TAG, "Humidity: %.2f %%", bmeData.humidity);
		 ESP_LOGI(TAG, "Pressure: %.2f hPa", bmeData.pressure);

         vTaskDelay(pdMS_TO_TICKS(2000));
     }
 }

 void BME280_task_start(void)
 {
     xTaskCreatePinnedToCore(BME280_Task,
         "bme280_task",
         4096,
         NULL,
         3,
         NULL,
         tskNO_AFFINITY
     );
 }