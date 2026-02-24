#include "bme.h"
#include "esp_log.h"
#include "freertos/idf_additions.h"
#include "freertos/projdefs.h"
#include "i2c.h"
#include <stdbool.h>
#include <unistd.h>


void app_main(void) {
	i2c_init();
	BME280_Init();

	BME280_Data_t bmeData = {.humidity = 0, .pressure = 0, .temperature = 0};
	while (true) {
		bmeData = BME280_ReadData();
		ESP_LOGI("main", "Temperature: %.2f C", bmeData.temperature);
		ESP_LOGI("main", "Humidity: %.2f %%", bmeData.humidity);
		ESP_LOGI("main", "Pressure: %.2f hPa", bmeData.pressure);
		vTaskDelay(pdMS_TO_TICKS(2000));
	}
}