//inisialisasi sensor
int sensorInfrared = PA2;

//inisialisasi LED
int R = PA0;
int Y = PA1;

//inisialisasi tambahan
int keyR = 0;

void setup() {
  //setup port
  Serial.begin(9600);

  //setup pin mode input atau output
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(sensorInfrared,INPUT);

}

void loop() {
  //baca data
  int readSensorInfrared = digitalRead(sensorInfrared);
  int readSensorLDR = analogRead(sensorLDR);
  readSensorLDR = map(readSensorLDR,4095,50,0,255);

  //print serial
  Serial.print("Nilai Sensor IR : ");
  Serial.print(readSensorInfrared);
  Serial.println();
  delay(500);

  //logic infrared sensor
  if(readSensorInfrared == 0 && keyR == 0){
    digitalWrite(R,HIGH);
//    delay(500);
    keyR = 1;
  }else if(readSensorInfrared == 0 && keyR == 1){
    digitalWrite(R,LOW);
//    delay(500);
    keyR = 0;
  }

}
