#include <string.h>
#include "audio_error.h"
#include "audio_mem.h"
#include "board.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG = "ESPHOME_BOARD";

esp_err_t get_i2c_pins(i2c_port_t port, i2c_config_t *i2c_config) {
  AUDIO_NULL_CHECK(TAG, i2c_config, return ESP_FAIL);
  ESP_LOGE(TAG, "Not implemented");
  i2c_config->sda_io_num = -1;
  i2c_config->scl_io_num = -1;
  return ESP_FAIL;
}

esp_err_t get_i2s_pins(i2s_port_t port, i2s_pin_config_t *i2s_config) {
  AUDIO_NULL_CHECK(TAG, i2s_config, return ESP_FAIL);
  memset(i2s_config, -1, sizeof(i2s_pin_config_t));
  ESP_LOGE(TAG, "Not implemented");
  return ESP_FAIL;
}

esp_err_t get_spi_pins(spi_bus_config_t *spi_config, spi_device_interface_config_t *spi_device_interface_config) {
  AUDIO_NULL_CHECK(TAG, spi_config, return ESP_FAIL);
  AUDIO_NULL_CHECK(TAG, spi_device_interface_config, return ESP_FAIL);

  spi_config->mosi_io_num = -1;
  spi_config->miso_io_num = -1;
  spi_config->sclk_io_num = -1;
  spi_config->quadwp_io_num = -1;
  spi_config->quadhd_io_num = -1;

  spi_device_interface_config->spics_io_num = -1;

  ESP_LOGW(TAG, "SPI interface is not supported");
  return ESP_OK;
}

esp_err_t i2s_mclk_gpio_select(i2s_port_t i2s_num, gpio_num_t gpio_num) {
  if (i2s_num >= I2S_NUM_MAX) {
    ESP_LOGE(TAG, "Does not support i2s number(%d)", i2s_num);
    return ESP_ERR_INVALID_ARG;
  }
  ESP_LOGI(TAG, "I2S%d, MCLK output by GPIO%d", i2s_num, gpio_num);
  return ESP_OK;
}
