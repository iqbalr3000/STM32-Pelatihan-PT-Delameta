//inisialisasi variable traffic ligh
int R = PA4;
int Y = PA3;
int G = PA2;

//inisialisasi variable button
int buttonR = PA5;
int buttonY = PA6;
int buttonG = PA7;

//inisialisasi variable kunci
int keyR = 0;
int keyY = 0;
int keyG = 0;

void setup() {
  //mengatur port
  Serial.begin(9600);
  
  //mengatur pin mode output atau input
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  
  pinMode(buttonR,INPUT);
  pinMode(buttonY,INPUT);
  pinMode(buttonG,INPUT);
}

void loop() {
  //membaca data button
  int readButtonR = digitalRead(buttonR);
  int readButtonY = digitalRead(buttonY);
  int readButtonG = digitalRead(buttonG);

  //print serial
  Serial.print("Button Merah : ");
  Serial.print(readButonR);
  Serial.print(" | Button Kunig : ");
  Serial.print(readButonY);
  Serial.print(" | Button Hijau : ");
  Serial.print(readButonG);
  Serial.println();
  
  //logica
  if(readButtonR == 1 && keyR == 0){
    digitalWrite(R,HIGH);
    delay(500);
    keyR = 1;
  }else if(readButtonR == 1 && keyR == 1){
    digitalWrite(R,LOW);
    delay(500);
    keyR = 0;
  }
  
  if(readButtonY == 1 && keyY == 0){
    digitalWrite(Y,HIGH);
    delay(500);
    keyY = 1;
  }else if(readButtonY == 1 && keyY == 1){
    digitalWrite(Y,LOW);
    delay(500);
    keyY = 0;
  }
  
  if(readButtonG == 1 && keyG == 0){
    digitalWrite(G,HIGH);
    delay(500);
    keyG = 1;
  }else if(readButtonG == 1 && keyG == 1){
    digitalWrite(G,LOW);
    delay(500);
    keyG = 0;
  }
  
}
