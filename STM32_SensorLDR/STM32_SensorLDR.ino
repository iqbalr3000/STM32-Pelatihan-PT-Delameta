//inisialisasi variable sensor
int sensorLDR = PA2;

void setup() {
  //setup port
  Serial.begin(9600);

  //setup pin mode input output
  pinMode(sensorLDR,INPUT);
}

void loop() {
  //baca data
  int readSensorLDR = analogRead(sensorLDR);
//  readSensorLDR = map(readSensorLDR,0,1024,0,255);

  //print serial
  Serial.print("Nilai Sensor : ");
  Serial.print(readSensorLDR);
  Serial.println();

  delay(1000);

}
