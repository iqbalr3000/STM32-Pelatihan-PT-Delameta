//menggunakan library NewPing untuk sensor ultrasonic
#include<NewPing.h>;

//inisialisasi variable sensor ultrasonic
int trigger = PA3;
int echo = PA2;
int batas = 400;

NewPing cm(trigger,echo,batas);

//inisialisasi variable sensor PIR
int sensorPIR = PA0;

//inisialisasi variable sensor Flame
int sensorFlame = PA1;

//inisialisasi variable tambahan
int R = PA4;
int Y = PA5;
int G = PA6;

//int kunci = ;

void setup() {
  Serial.begin(9600);

  //mengatur pin mode input atau output
  pinMode(sensorPIR,INPUT);
  pinMode(sensorFlame, INPUT);

  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  
}

void loop() {
  //baca data
  int readSpace = cm.ping_cm();
//  int readSensorFlame = analogRead(sensorFlame);
//  readSensorFlame = map(readSensorFlame,4095,200,0,100);
  int readSensorFlame = digitalRead(sensorFlame);
  int readSensorPIR = digitalRead(sensorPIR);

  //print serial
  Serial.print("Jarak : ");
  Serial.print(readSpace);
  Serial.print(" | Api : ");
  Serial.print(readSensorFlame);
  Serial.print(" | Motion : ");
  Serial.print(readSensorPIR);
  Serial.println();

  //logic : jika ada api dan jaraknya kurang dari 100 cm maka danger, jika kurang dari 200 dan lebih dari 100 maka warning , lebih dari 200 maka safe zone
  if(readSensorFlame == 0 && readSpace <= 100 && readSpace != 0){
    Serial.println("Danger!!!");
    digitalWrite(R,HIGH);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
  }else if(readSensorFlame == 0 && readSpace > 100 && readSpace <= 200 && readSpace != 0){
    Serial.println("Warning");
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    digitalWrite(G,LOW);
  }else{
    Serial.println("Safe zone");
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH);
  }

   delay(1000);
  
}
