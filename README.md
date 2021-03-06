mSdk
====

Multiplatform SDK for standalone applications

This SDK is intended to help the developers that he want to develop standalone applications that can be compiled for different platforms with minimum changes of source code.

At this moment is supported the next platforms:

1) TI AM335x (Code Composer Studio(GCC only)).

  <a href="http://beagleboard.org/bone">BeagleBone Board.</a>
  
  <a href="http://beagleboard.org/black">BeagleBone Black Board.</a>
  
  <a href="http://www.embest-tech.com/product/evaluation-boards/devkit8600-evaluation-board.html">DevKit8600 Board.</a>
  
2) TI OMAP4 (Code Composer Studio).

  <a href="http://pandaboard.org/content/pandaboard-es">PandaBoardEs Board.</a>
  
3) AVR32AP7000 (AVR32 Studio).

  <a href="http://www.atmel.com/tools/MATURENGW100NETWORKGATEWAYKIT.aspx">NGW100 Board.</a>
  
4) ATxmega (Atmel Studio).

  <a href="http://devboardshop.com/en/media-development-boards/9-xmegamediaplayer-v1.html">XmegaMediaPlayer Board.</a>
  
5) AT32UC3L (Atmel Studio).

  <a href="http://www.atmel.com/tools/UC3-L0XPLAINED.aspx">Xplained Board.</a>
  
6) STM32F0 (CoIDE).

  --

7) STM32F10x (CoIDE).

  Custom board (see example app for details).

8) STM32F3 (CoIDE).

  --

9) STM32F4xx (ODeV & CoIDE).

  <a href="http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/PF252419">Discovery Board.</a>
  
  <a href="http://www.mikroe.com/mikromedia/stm32-m4/">Mikromedia board.</a>
  
  <a href="https://www.olimex.com/Products/ARM/ST/STM32-H407/open-source-hardware">STM32-E407.</a>
  
I added the settings for all example projects to help beginners to understand how it works, is necessary to clone mSdk into "C:\GitHub\" directory.

<a href="http://forum.devboardshop.com/">Detalied description link.</a>

Done API's for every platform:

	AM335x:
		EDMA.
		GPIO.
		MMCSD:
			uSD.
			MMC.
			eMMC.
		Touchscreen:
			Internal AD touchscreen.
			FT5x06 capacitive touchscreen.
		LCD.
		SPI.
		RTC.
		TWI.
		UART.
		USB:
			DEV MSC.
			HOST MSC.
			HOST Mouse.
	AT32AP7000:
		GPIO.
		MMCSD.
		LCD.
		RTC.
		TWI.
		UART.
	AT32UC3L:
		ADC.
		GPIO.
		UART.
	ATXMEGA:
		GPIO.
		MMCSD using USART in SPI mode.
		SPI.
		TWI.
		USART.
	OMAP4:
		GPIO.
		TWI.
		UART.
	STM32F0:
		In development.
	STM32F1:
		GPIO.
		USART.
		TWI.
		ADC.
	STM32F3:
		In development.
	STM32F4:
		GPIO.
		USART
		TWI.
		ADC (not ready).

Supported devices (this drivers works on all platforms that has API's for used communicatiun busses):

	24c I2C EEProm device.
	ADXL345 I2C accelerometer device.
	AR1020 I2C touchscreen device.
	DS1307 I2C RTC device.
	FT5x06 I2C capacitive touchscreen device.
	MHC5883 I2C compass device.
	MPU60x0 I2C accelerometer, giroscope and temperature sensor device.
	MS5611 I2C pressure & temperature sensor device.
	SHT11 custom software interface humidity and temperature device.
	SRF02 I2C ultrasonic range finder device.
	SST25VF SPI flash memory device.
	TPS65217 I2C PMIC device.
	TPS65910 I2C PMIC device.
	DXL actuators from Dynamixel.
	BMP180 I2C barometer and temperature sensor device.
	MPU9150 I2C accelerometer, giroscope, compass(AK8975) and temperature sensor device.
	AK8975 I2C compass sensor device.
	HIH6130-HIH6131 I2C hidrometer and temperature sensor device(only STM32F4 controllers for now).
	Lepton FLIR termal image sensor SPI device.
