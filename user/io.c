#include <esp8266.h>

void ICACHE_FLASH_ATTR ioLed(int ena) {
	os_printf("ioLed %d\n", ena);
	GPIO_OUTPUT_SET(5, ena ? 1 : 0);
}

void ioInit() {
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO5_U, FUNC_GPIO5);
	GPIO_OUTPUT_SET(5, 0);
}

