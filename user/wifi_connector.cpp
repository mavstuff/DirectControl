extern "C"
{
	#include "user_interface.h"
}
#include "wifi_connector.h"
#include "espmissingincludes.h"
#include "cpp_req.h"
#include "captdns.h"



void ICACHE_FLASH_ATTR WifiConnectorInit()
{
	#ifdef PLATFORM_DEBUG
	os_printf("WifiConnectorInit\r\n");
	#endif

	WifiEnterWorkMode();
	captdnsInit();
	WebInit();
}


void ICACHE_FLASH_ATTR WifiEnterWorkMode()
{

	#ifdef PLATFORM_DEBUG
	os_printf("WifiEnterWorkMode\r\n");
	#endif
	wifi_set_opmode(SOFTAP_MODE);
		struct softap_config apconfig;
		if(wifi_softap_get_config(&apconfig))
		{
			wifi_softap_dhcps_stop();
			os_memset(apconfig.ssid, 0, sizeof(apconfig.ssid));
			os_memset(apconfig.password, 0, sizeof(apconfig.password));
			os_sprintf((char*)apconfig.ssid, "hub%ld", (long int)56);
			apconfig.ssid_len = os_strlen((char*)apconfig.ssid);
			apconfig.authmode = AUTH_OPEN;
			apconfig.ssid_hidden = 0;
			apconfig.channel = 9;
			apconfig.max_connection = 4;
			apconfig.beacon_interval = 100;
			if(!wifi_softap_set_config(&apconfig))
			{
			#ifdef PLATFORM_DEBUG
				os_printf("%s", "ESP8266 not set AP config!\r\n");
				#endif
			};
			struct ip_info ipinfo;
			wifi_get_ip_info(SOFTAP_IF, &ipinfo);
			IP4_ADDR(&ipinfo.ip, 192, 168, 4, 1);
			IP4_ADDR(&ipinfo.gw, 192, 168, 4, 1);
			IP4_ADDR(&ipinfo.netmask, 255, 255, 255, 0);
			wifi_set_ip_info(SOFTAP_IF, &ipinfo);
			wifi_softap_dhcps_start();
		}
		wifi_set_broadcast_if(3);

	#ifdef PLATFORM_DEBUG
	os_printf("WifiEnterWorkMode end.\r\n");
	#endif
}


