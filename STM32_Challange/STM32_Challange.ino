//inisialisasi variable sensor
int sIR = PA0;
int sLDR = PA1;

//inisialisasi variable lampu
int R = PA2;
int Y = PA3;
int G = PA4;

//inisialisasi variable tambahan
int key = 0;

void setup() {
  //setup port
  Serial.begin(9600);

  //setup pin mode input output
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(sIR, INPUT);
  pinMode(sLDR, INPUT);

}

void loop() {
  //baca data
  int readsIR = digitalRead(sIR);
  int readsLDR = analogRead(sLDR);
  readsLDR = map(readsLDR, 4090, 80, 0, 255);

  //print serial
  Serial.print("Nilai sensor : ");
  Serial.print(readsIR);
  Serial.print(" | Nilai sensor : ");
  Serial.print(readsLDR);
  Serial.println();
  delay(500);

  //logika sensor Infrared
  if (readsIR == 0 && key == 0) {
    key = 1;
  } else if (readsIR == 0 && key == 1) {
    key = 0;
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
  }

  //logika sensor LDR
  if (readsLDR <= 100 && key == 1) {
    digitalWrite(R, HIGH);
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
  } else if (readsLDR > 100 && readsLDR <= 200 && key == 1) {
    digitalWrite(R, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(G, LOW);
  } else if (readsLDR > 200 && key == 1) {
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(G, HIGH);
  }

}
