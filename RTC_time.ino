//instalovat uRTCLib knihovnu
//čtení času přes I2C z RTC HW-111

#include "uRTCLib.h"

uRTCLib rtc(0x68); //volba I2C adresy asi
//pole s dnama týdne...
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  Serial.begin(9600);
  while (!Serial); //počkat až se serial con otevře
  
  URTCLIB_WIRE.begin(); //"zapne" modul

    //nastavení času: (zakomentovat po nastavení)
    //example: January 13 2022 at 12:56 is:
  rtc.set(0, 34, 21, 4, 3, 5, 23);
    // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
    // set day of week (1=Sunday, 7=Saturday)
}

void loop() {
  rtc.refresh(); //"načtení" dat z RTC

  Serial.print("Current Date & Time: ");
  Serial.print(rtc.year());
  Serial.print('/');
  Serial.print(rtc.month());
  Serial.print('/');
  Serial.print(rtc.day());

  Serial.print(" ("); //převedení dne týdne z čísla na slovo
  Serial.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
  Serial.print(") ");

  Serial.print(rtc.hour());
  Serial.print(':');
  Serial.print(rtc.minute());
  Serial.print(':');
  Serial.println(rtc.second());
  
  delay(1000);
}
