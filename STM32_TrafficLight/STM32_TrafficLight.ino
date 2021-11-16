//inisialisasi variable traffic ligh
int R = PA4;
int Y = PA3;
int G = PA2;
//inisialisasi variable button
int buttonR = PA5;
int buttonY = PA6;
int buttonG = PA7;
//inisialisasi variable tambahan

void setup() {
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

  //logica
  if(readButtonR == 1){
    digitalWrite(R,HIGH);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
  }else if(readButtonY == 1){
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    digitalWrite(G,LOW);
  }else if(readButtonG == 1){
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH);
  }else{
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
  }
  
}
