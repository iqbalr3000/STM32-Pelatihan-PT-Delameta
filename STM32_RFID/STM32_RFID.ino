//menggunakan library
#include<SPI.h>
#include<MFRC522.h>
#include<LiquidCrystal_I2C.h>

//inisialisasi variable rfid
#define SS_PIN PB9
#define RST_PIN PB0

MFRC522 mfrc522(SS_PIN, RST_PIN);

//inisialisasi variable lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

//inisialisasi variable infrared
int infrared = PA1;

//inisialisasi variable tambahan
String uidString;
int kunci = 0;

void setup() {
  // setup baudrate
  Serial.begin(9600);
  
  //initiate spi bus
  SPI.begin();
  
  //initiate mfrc522
  mfrc522.PCD_Init();

  //setup pin mode input atau output
  pinMode(infrared,INPUT);

  //initiate lcd
  lcd.begin();

  //print serial
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tempelkan Kartu!");
  delay(500);
}

void loop() {
  //baca data  
  if(mfrc522.PICC_IsNewCardPresent() && kunci == 0){
    readRFID();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tag UID : ");
    lcd.setCursor(0,1);
    lcd.print(uidString);
    delay(500);

    if(uidString == "A-A8-90-15"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("BERHASIL!");
      delay(500);
      lcd.setCursor(0,1);
      lcd.print("Gerbang dibuka");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Silakan Masuk");
      kunci = 1;
    }else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("GAGAL!");
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tempelkan Kartu!");
      delay(500);
    }
  }

  infraredNyala();

}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  uidString = String(mfrc522.uid.uidByte[0], HEX) + "-" +
              String(mfrc522.uid.uidByte[1], HEX) + "-" +
              String(mfrc522.uid.uidByte[2], HEX) + "-" +
              String(mfrc522.uid.uidByte[3], HEX);
              uidString.toUpperCase();
}

void infraredNyala(){
  //baca data
  int readInfrared = digitalRead(infrared);

  if(readInfrared == 0 && kunci == 1){
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gerbang ditutup");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tempelkan Kartu!");
    kunci = 0;
  }

}
