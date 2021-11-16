//inisialisasi variable sensor
int sensorInfrared = PA2;
int sensorLDR = PA3 ;

//inisialisasi variable LED
int R = PA0;
int Y = PA1;

//inisialisasi variabel tambahan
int key = 0;

void setup() {
  //setup port
  Serial.begin(9600);

  //setup pin mode input atau output
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(sensorInfrared, INPUT);
  pinMode(sensorLDR, INPUT);

}

void loop() {
  //baca data
  int readSensorInfrared = digitalRead(sensorInfrared);
  int readSensorLDR = analogRead(sensorLDR);
  readSensorLDR = map(readSensorLDR, 4095, 50, 255, 0);

  //print serial
  Serial.print("Nilai Sensor IR : ");
  Serial.print(readSensorInfrared);
  Serial.print(" | Nilai Sensor LDR : ");
  Serial.print(readSensorLDR);
  Serial.println();
  delay(500);

  if(readSensorInfrared == 0 && key == 0) {
    if(readSensorLDR <= 100) {
      analogWrite(Y, 0);
      key = 1;
    }else if(readSensorLDR > 100 && readSensorLDR <= 200) {
      analogWrite(Y, 100);
      key = 1;
    }else{
      analogWrite(Y, 255);
      key = 1;
    }
  }else if(readSensorInfrared == 0 && key == 1){
    analogWrite(Y, 0);
    key = 0;
  }

}
