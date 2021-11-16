//memanggil library
#include<SPI.h>
#include<MFRC522.h>
#include<LiquidCrystal_I2C.h>
#include<Servo.h>

//inisialisasi variable mfrc522
#define SS_PIN PB9
#define RST_PIN PB0

MFRC522 mfrc522(SS_PIN, RST_PIN);

//inisialisasi lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

//inisialisasi servo
int outServo = PA0;

Servo myServo;

//inisialisasi infrared
int infrared = PA1;

//inisialisasi variable tambahan
String uidString;
int key = 0;
int buzzer = PA2;

void setup() {
  //setup baudrate
  Serial.begin(9600);

  //initiate spi
  SPI.begin();

  //initiate mfrc522
  mfrc522.PCD_Init();

  //initiate lcd
  lcd.begin();

  //attach servo
  myServo.attach(outServo);

  //setup pin mode input atau output
  pinMode(infrared, INPUT);
  pinMode(buzzer, OUTPUT);
  
  //keadaan pertama lcd
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tempelkan Kartu!");

  //keadaan awal servo
  myServo.write(90);
}

void loop() {
  if(mfrc522.PICC_IsNewCardPresent() && key == 0){
    readRFID();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tag ID : ");
    lcd.print(0,1);
    lcd.print(uidString);

    if(uidString == "8A-37-5A-1A"){
      buzzerBerhasil();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Berhasil!");
      delay(500);
      myServo.write(180);
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Silakan Masuk");
      key = 1;
    }else{
      buzzerGagal();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Gagal!");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tempelkan Kartu!");
    }

  }

  infraredON();

}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  uidString = String(mfrc522.uid.uidByte[0], HEX) + "-" +
              String(mfrc522.uid.uidByte[1], HEX) + "-" +
              String(mfrc522.uid.uidByte[2], HEX) + "-" +
              String(mfrc522.uid.uidByte[3], HEX);
              uidString.toUpperCase();
}

void infraredON(){
  int readInfrared = digitalRead(infrared);

  if(readInfrared == 0 && key == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gerbang di tutup");
    delay(500);
    myServo.write(90);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tempelkan Kartu!");
    key = 0;
  }
}

void buzzerBerhasil(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
}

void buzzerGagal(){
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
}
