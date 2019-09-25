 // colorWipe function taken from the 
 // Adafruit Neopixel tutorial at 
 // https://learn.adafruit.com/multi-tasking-the-arduino-part-3/the-color-wipe



 
#include <Adafruit_NeoPixel.h>

const int bendPin = A11;  //pin 12
const int pressPin = A7;  //pin 6

int bendValue = 0;        // value read from the bend sensor
int pressValue = 0;        // value read from the pressure sensor

#define PIN 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, 1, NEO_GRB + NEO_KHZ800);

void setup(){
  Serial.begin(9600);
  
   strip.begin();
   strip.show(); 
   strip.setBrightness(50);
}

void loop() {
  bendValue = analogRead(bendPin);   
  Serial.print("bend = " );                       
  Serial.println(bendValue);   // printing bend sensor value on serial monitor

  pressValue = analogRead(pressPin);    
  Serial.print("press = " );                       
  Serial.println(pressValue);  // printing pressure sensor value on serial monitor
  
  
Serial.print("brightness = " );                       
  Serial.println(pressValue/20);

Serial.print("colour = " );                       
  Serial.println(bendValue/4),   Serial.println(bendValue/2),    Serial.println(bendValue/3); 


colorWipe( strip.Color(bendValue/4, bendValue/2, bendValue/3),25); //rgb values taken from bend sensor
strip.setBrightness(pressValue/20);  //brightness value taken from pressure sensor 

 delay(500); //updates every .5 seconds
  
  }
 



void colorWipe(uint32_t c, uint8_t wait) { 
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
