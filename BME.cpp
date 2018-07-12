#include <Adafruit_BME280.h>

BME::BME()
{
}

uint8_t BMP::begin(uint8_t ADR_)
{
	ADR = ADR_;
	bmp.begin(ADR, 0x58);
}

float BME::GetPressure() //Get pressure in mBar 
{
	return Sensor.readPressure()*0.01; //Convert to mBar
}

float BME::GetHumidity()  //Return humidity in % (realtive)
{
	return Sensor.readHumidity()
}

float BME::GetTemperature()  //Return temp in C
{
	return Sensor.readTemperature();
}

String BME::GetHeader()
{
	return "Pressure Atmos [mBar], Humidity [%], Temp Atmos [C]";
}

String BME::GetString()
{
	return String(GetPressure()) + "," + String(GetHumidity()) + "," + String(GetTemperature());
}