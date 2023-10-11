#include "board.h"

static const char *TAG = "AUDIO_BOARD";

static audio_board_handle_t board_handle = 0;

audio_board_handle_t audio_board_init(void) { return board_handle; }

audio_board_handle_t audio_board_get_handle(void) { return board_handle; }

esp_err_t audio_board_deinit(audio_board_handle_t audio_board) {
  esp_err_t ret = ESP_OK;
  audio_free(audio_board);
  board_handle = NULL;
  return ret;
}
