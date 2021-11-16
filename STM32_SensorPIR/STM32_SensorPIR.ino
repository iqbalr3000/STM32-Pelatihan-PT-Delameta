//inisialisasi variable sensor
int sensorPIR = PA2;

void setup() {
  //setup port
  Serial.begin(9600);

  //setup pin mode input output
  pinMode(sensorPIR,INPUT);
}

void loop() {
  //baca data
  int readSensorPIR = digitalRead(sensorPIR);

  //print data
  Serial.print("Nilai Data : ");
  Serial.print(readSensorPIR);
  Serial.println();

  delay(500);
}
