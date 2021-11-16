//meggunakan library
#include<NewPing.h>

//inisialisasi variabel sensor ultrasonic
int trigger = PA3;
int echo = PA2;
int batas = 400;

NewPing cm(trigger, echo, batas);

//inisialisasi variable sensor flame
int sensorPIR = PA0;
int sensorFlame = PA1;

//inisialisasi variabel tambahan
int R = PA4;
int Y = PA5;
int G = PA6;
int kunci = 0;

void setup() {
  //mengatur baudrate
  Serial.begin(9600);

  //mengatur pin mode input output
//  pinMode(sensorPIR,INPUT);
  pinMode(sensorFlame,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

}

void loop() {
  //baca data
  int readSpace = cm.ping_cm();
  int readSensorFlame = digitalRead(sensorFlame);
//  int readSensorPIR = digitalRead(sensorPIR);

  //print serial
  Serial.print("Jarak : ");
  Serial.print(readSpace);
  Serial.print(" | Api : ");
  Serial.print(readSensorFlame);
//  Serial.print(" | Motion : ");
//  Serial.print(readSensorPIR);
  Serial.print(" | Kunci : ");
  Serial.print(kunci);
  Serial.println();
  delay(1000);

//  logic
  if(readSensorFlame == 0 && kunci == 0){
    kunci = 1;
  }else if(readSensorFlame == 0 && kunci == 1){
    kunci = 0;
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
  }

  if(readSpace >= 1 && readSpace <= 50 && readSpace != 0 && kunci == 1){
    blink2();
  }else if(readSpace > 50 && readSpace <= 100 && readSpace != 0 && kunci == 1){
    blink1();
  }else if(readSpace > 100 && readSpace <= 400 && readSpace != 0 && kunci == 1){
    flipflop();
  }
  
}

void flipflop(){
   digitalWrite(R,HIGH);
   digitalWrite(Y,LOW);
   digitalWrite(G,LOW);
   delay(1000);
   digitalWrite(R,LOW);
   digitalWrite(Y,HIGH);
   digitalWrite(G,LOW);
   delay(1000);
   digitalWrite(R,LOW);
   digitalWrite(Y,LOW);
   digitalWrite(G,HIGH);
   delay(1000);
   digitalWrite(R,LOW);
   digitalWrite(Y,HIGH);
   digitalWrite(G,LOW);
}

void blink1(){
  digitalWrite(R,HIGH);
  digitalWrite(Y,HIGH);
  digitalWrite(G,HIGH);
  delay(1000);
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
}

void blink2(){
  digitalWrite(R,HIGH);
  digitalWrite(Y,HIGH);
  digitalWrite(G,HIGH);
  delay(100);
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  delay(100);
}
