
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
static const int RXPin = 8, TXPin = 9;
static const uint32_t GPSBaud = 9600;
const int trigPin=11;
const int echoPin=12;
long duration;
int distance; 
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);
void setup() {
 
  ss.begin(GPSBaud);  
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.begin (9600);
  
}

void loop() 
{
delay(1000);
  
  digitalWrite (trigPin,LOW);
  delayMicroseconds (2);

  digitalWrite (trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin, LOW);

  duration = pulseIn (echoPin, HIGH);
   distance=duration*0.034/2;

  Serial.print ("Distance: ");
  Serial.print (distance);
  Serial.println (" cm");
  delay (120);
  if(distance<70)
  Serial.print("pothole\n");
 
 

 
 while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Laitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
      
      }
      
 }


}
 



