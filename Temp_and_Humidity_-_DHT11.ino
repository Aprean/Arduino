// installovat DHT sensor library
#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11 používám
#define DHTPIN 2  //digi pin senzoru

DHT dht(DHTPIN, DHTTYPE); //inicializace parametru senzoru do knihovny

void  setup()
{
  Serial.begin(9600);
  dht.begin(); //spuštění knihovny asi
}

void loop()
{
  float humid = dht.readHumidity(); //float aby desetina čárka
  float temp = dht.readTemperature(); //číst celsiu by default
  
  Serial.print("Humidity (%): ");
  Serial.println(humid);

  Serial.print("Temperature  (C): ");
  Serial.println(temp);

  delay(1000);
}
