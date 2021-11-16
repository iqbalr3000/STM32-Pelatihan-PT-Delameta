#include<TinyGPS.h>
#include<SoftwareSerial.h>

int RXPin = PA2;
int TXPin = PA3;

int GPSBaud = 9600;

TinyGPS gps;

SoftwareSerial gpsSerial(RXPin, TXPin);

String latitude, longitude, km_ph;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  gpsSerial.begin(GPSBaud);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(gpsSerial.available()>0)
    if(gps.encode(gpsSerial.read()))
      displayInfo();

  if(millis() > 5000 && gps.charsProcessed() < 10){
    Serial.println("No GPS Detected");
    while(true);
  }

}


void displayInfo()
{
  if (gps.location.isValid())
  {
    latitude = String(gps.location.lat(),6);
    longitude = String(gps.location.lng(),6);
    km_ph = String(gps.speed.kmph());
    String link = "www.google.com/maps/place/" + String(latitude) + "," + String(longitude) + " | " + String(km_ph) ;
    Serial.println(link);
  }
  else
  {
    Serial.println("Location: Not Available");
  }
  
  Serial.print("Date: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.println(gps.date.year());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.print("Time: ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.println(gps.time.centisecond());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.println();
  Serial.println();
  delay(1000);
}
