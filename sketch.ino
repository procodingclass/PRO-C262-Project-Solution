#include <Adafruit_NeoPixel.h>

const byte pir_pin= 15; 
const byte data_pin=22;
const byte buzzer_pin=21;
const byte led_num = 20;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(led_num, data_pin, NEO_GRB + NEO_KHZ800);

void setup() {

  Serial.begin(115200);
  pinMode(pir_pin, INPUT);

  pinMode(buzzer_pin, OUTPUT);

  pixels.begin(); // initialize the library
  pixels.show();
}

void loop() {

  if(digitalRead(pir_pin)){
    
    for(int i=0; i<500; i++){

      digitalWrite(buzzer_pin, HIGH);
      delay(2);
      generate_pattern();
      digitalWrite(buzzer_pin, LOW);
      delay(2);
    }
  }
  delay(100); // this speeds up the simulation
}

void generate_pattern(){

    for (int i = 0; i < led_num; i++){
      pixels.setPixelColor(i, 255, 255, 255);
    }
    delay(2);
    pixels.show();
    for (int i = 0; i < led_num; i++){
      pixels.setPixelColor(i, 0, 0, 0);
    }
    delay((2));
    pixels.show();

}