#include "tasks.h"
#include "esp_log.h"
#include "freertos/idf_additions.h"
#include "freertos/projdefs.h"
#include "i2c.h"
#include <stdbool.h>
#include <unistd.h>


void app_main(void) {
	i2c_init();
	BME280_task_start();
}