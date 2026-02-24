#include "i2c.h"

#define I2C_MASTER_SCL_IO 22
#define I2C_MASTER_SDA_IO 21

i2c_master_bus_handle_t bus_handle;

void i2c_init(void) {
	i2c_master_bus_config_t bus_config = {
		.clk_source = I2C_CLK_SRC_DEFAULT,
		.i2c_port = I2C_NUM_0,
		.sda_io_num = 21,
		.scl_io_num = 22,
		.glitch_ignore_cnt = 7,
		.flags.enable_internal_pullup = true,
	};

	ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, &bus_handle));
}