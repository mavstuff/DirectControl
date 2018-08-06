#############################################################
#
# Root Level Makefile
#
# (c) by CHERTS <sleuthhound@gmail.com>
#
#############################################################

# Main settings includes
include	c:\Espressif\examples\ESP8266\settings.mk

# Individual project settings (Optional)
#BOOT		= new
#APP		= 1
#SPI_SPEED	= 40
#SPI_MODE	= QIO
#SPI_SIZE_MAP	= 2
ESPPORT		= COM3
#ESPBAUD		= 115200
ESPBAUD		= 57600

# Basic project settings
MODULES	= user
LIBS	= c gcc hal phy pp net80211 lwip wpa main crypto

# Root includes
include	c:\Espressif\examples\ESP8266\common_cpp.mk