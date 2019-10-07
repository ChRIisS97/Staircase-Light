/************* PIR Sensor 1 *****************/
int inputPin = 4;                // choose the input pin (for PIR sensor)
int pirState = LOW;              // we start, assuming no motion detected
int val = 0;                     // variable for reading the pin status

/************* PIR Sensor 2 *****************/
int inputPin2 = 8;               // choose the input pin (for PIR sensor)
int val2 = 0;                    // variable for reading the pin status

/************* Helligkeitssensor ************/
int Helligkeitssensor = A0;      // Pin number
int sensorWert = 0;              // starting value

/************* LED Strips *******************/
#include <Adafruit_NeoPixel.h>   //Adafruit NeoPixel library
#define PIN 7                    // Pin number
#define NUMPIXELS 300            // Numbers of pixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

 
void setup() {
  pinMode(inputPin, INPUT);      // declare sensor as input
  pinMode(inputPin2, INPUT);     // declare sensor as input
  Serial.begin(9600);            // Initialisierung Serial
  pixels.begin();                // Initialisierung der NeoPixel
}
 
void loop(){
  sensorWert =analogRead(Helligkeitssensor);
  Bewegungsmelder1();
  Bewegungsmelder2();
}

void Bewegungsmelder1(){
  val = digitalRead(inputPin);                            // read input value

if (sensorWert <= 290){   
  if (val == HIGH && val2 != HIGH) {
    val2 = LOW;
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(50,50,50));    // Moderately bright green color.
      pixels.show();         
    }
    if (pirState == LOW) {
      //Serial.println("Motion detected!");               // we have just turned on
      pirState = HIGH;                                    // We only want to print on the output change, not state
    }
  } else {
    if (pirState == HIGH){
      //Serial.println("Motion ended!");                  // we have just turned of  
      pirState = LOW;                                     // We only want to print on the output change, not state
      val2 = LOW;
      delay(7000);
      
      for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0));       // Pixel leuchtet in der Farbe Grün
      pixels.show(); 
      }
     }
   }
 } 
}

void Bewegungsmelder2(){
  val2 = digitalRead(inputPin2);                          // read input value

if (sensorWert <= 290 ){   
  if (val2 == HIGH) {
      val = LOW; 
      for(int i = NUMPIXELS - 1;i >= 0; i = i - 1){
      pixels.setPixelColor(i, pixels.Color(50,50,50));    // Pixel leuchtet in der Farbe Grün
      pixels.show();      
     }
     if (pirState == LOW) {
      //Serial.println("Motion 2 detected!");             // we have just turned on
      pirState = HIGH;                                    // We only want to print on the output change, not state
    }
  } else {
    if (pirState == HIGH){
      //Serial.println("Motion 2 ended!");                // we have just turned of
      pirState = LOW;                                     // We only want to print on the output change, not state
      val = LOW;  
      delay(7000);

      for(int i=0;i<NUMPIXELS;i++){      
      pixels.setPixelColor(i, pixels.Color(0,0,0));       // Pixel leuchtet in der Farbe Grün
      pixels.show(); 
      }
    }
  }
 }
}
