//inisialisasi sensor
int sensorInfrared = PA2;
int sensorLDR = PA3 ;

//inisialisasi LED
int R = PA0;
int Y = PA1;
//int G = ;

//inisialisasi tambahan
int keyR = 0;

void setup() {
  //setup port
  Serial.begin(9600);

  //setup pin mode input atau output
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(sensorInfrared,INPUT);
  pinMode(sensorLDR,INPUT);

}

void loop() {
  //baca data
  int readSensorInfrared = digitalRead(sensorInfrared);
  int readSensorLDR = analogRead(sensorLDR);
  readSensorLDR = map(readSensorLDR,4095,50,255,0);

  //print serial
  Serial.print("Nilai Sensor IR : ");
  Serial.print(readSensorInfrared);
  Serial.print(" | Nilai Sensor LDR : ");
  Serial.print(readSensorLDR);
  Serial.println();
  delay(1000);

  //logic infrared sensor
  if(readSensorInfrared == 0 && keyR == 0){
    digitalWrite(R,HIGH);
    delay(1000);
    keyR = 1;
  }else if(readSensorInfrared == 0 && keyR == 1){
    digitalWrite(R,LOW);
    delay(1000);
    keyR = 0;
  }

  //logic ldr sensor
  if(readSensorLDR <= 100){
    analogWrite(Y,0);
  }else if(readSensorLDR > 100 && readSensorLDR <= 200){
    analogWrite(Y,100);
  }else{
    analogWrite(Y,255);
  }

}
