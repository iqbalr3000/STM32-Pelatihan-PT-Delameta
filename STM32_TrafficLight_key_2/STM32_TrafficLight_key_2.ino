//inisialisasi variable lampu
int R = PA0;
int Y = PA1;
int G = PA2;

//inisialisi variable button
int buttonR = PA3;
int buttonY = PA4;
int buttonG = PA5;

//inisialisasi variable kunci
int keyR = 0;
int keyY = 0;
int keyG = 0;

void setup() {
  //mengatur port
  Serial.begin(9600);

  //mengatur pin mode input atau output
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

  pinMode(buttonR,INPUT);
  pinMode(buttonY,INPUT);
  pinMode(buttonG,INPUT);
}

void loop() {
  //baca data button
  int readButtonR = digitalRead(buttonR);
  int readButtonY = digitalRead(buttonY);
  int readButtonG = digitalRead(buttonG);

  //print serial
  Serial.print("Button Merah : ");
  Serial.print(readButtonR);
  Serial.print(" | Button Kuning : ");
  Serial.print(readButtonY);
  Serial.print(" | Button Hijau : ");
  Serial.print(readButtonG);
  Serial.println();

  //logic red button
  if(readButtonR == 1 && keyR == 0){
    digitalWrite(R,HIGH);
    delay(500);
    keyR = 1;
  }else if(readButtonR == 1 && keyR == 1){
    digitalWrite(R,LOW);
    delay(500);
    keyR = 0;
  }
  //end

  //logic yellow button
  if(readButtonY == 1 && keyY == 0){
    digitalWrite(Y,HIGH);
    delay(500);
    keyY = 1;
  }else if(readButtonY == 1 && keyY == 1){
    digitalWrite(Y,LOW);
    delay(500);
    keyY = 0;
  }
  //end

  //logic green button
  if(readButtonG == 1 && keyG == 0){
    digitalWrite(G,HIGH);
    delay(500);
    keyG = 1;
  }else if(readButtonG == 1 && keyG == 1){
    digitalWrite(G,LOW);
    delay(500);
    keyG = 0;
  }
  //end
}
