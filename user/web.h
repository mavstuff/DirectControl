#ifndef USER_WEB_H_
#define USER_WEB_H_

extern "C" {
#include "io.h"
}
void ICACHE_FLASH_ATTR WebInit();
extern bool g_bSettingsOk;
extern bool g_bSettingsApplied;

#endif /* USER_WEB_H_ */
