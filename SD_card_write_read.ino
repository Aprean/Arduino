//before cokoli, ověřit zapojení a kartu pomocí example>cardinfo
//>>nastavit na mód(pin/board) 10 (může být i 4)
//chce to externí napájení a připojit sd rovnou na to, ne přes arduino

#include <SD.h> //knihovna
const int chipSelect = 10; //select chipu (10)
File myFile; //file type variable (asi název souboru)

int num_to_write = 1;


void check_and_create_file()
{
  Serial.print("---Inicializace...."); //jestli karta existuje
  if (!SD.begin(chipSelect)) {
    Serial.println("---inicializace fucked!");//fucked
    while (1);
  }
  Serial.println("Inicializováno.");//nice
  if (SD.exists("data_log.txt"))//kontrola existence souboru
    Serial.println("---soubor existuje");
  else
  {
    Serial.println("---soubor neexistuje, vytvářím nový");
    myFile = SD.open("data_log.txt", FILE_WRITE);
    myFile.close(); //otevřít a zavřít soubor, tím se vytvoří

    if (SD.exists("data_log.txt"))//zkontrolovat jesti už existuje
      {}
    else
      Serial.println("---pořád neexistuje, fucked!");
  }
}


void read_write_sd_text()
{
  myFile = SD.open("data_log.txt", FILE_WRITE); //otevřít soubor pro zápis

  if (myFile) {  //jestli existuje, zápis:
    Serial.println("---zapisuji věci");
    myFile.println("Zápis dat 1");

    myFile.close(); //zavřít po zapsání
    Serial.println("---hotovo, zapsáno");
    
  } else {
    
    Serial.println("Write - soubor se neotevřel, fucked"); //soubor se neotevřel
  }

  myFile = SD.open("data_log.txt"); //otevřít soubor pro čtení
  if (myFile) {
    Serial.println("---čtení z: data_log.txt"); //jestli existuje, číst

    while (myFile.available()) { //číst dokovaď není co
      Serial.write(myFile.read());
    }
    myFile.close(); //zavřít
    Serial.println("---hotovo, přečteno");
    
  } else {
 
    Serial.println("---Read - soubor se neotevřel, fucked"); //soubor se neotevřel
  }
}


void setup() {
  Serial.begin(9600);
  while (!Serial); //počkat až se serial com otevře
  Serial.println();
  check_and_create_file();
}

void loop() { 
  read_write_sd_text();
  delay(10000);
}
