/* ------ INCLUDING LIBRARIES ------ */


#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#include <U8g2lib.h>
#include "ui.h"


/* ------ OLED SCREEN SPECS ------ */


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


/* ------ */
Adafruit_NeoPixel pixels(1, 8, NEO_GRB + NEO_KHZ800);


int BUZ = 10;
int LDR = 3;
int VIB = 0;

void setup() {

  pinMode(BUZ, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(VIB, INPUT_PULLUP);
  Serial.begin(9600);

  Wire.begin(5,4);
  u8g2.begin();

  pixels.begin();
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.show();
}

void loop() {



  if(analogRead(LDR) > 1240 && analogRead(LDR) < 2740){
    noTone(BUZ);
    neutral();
    pixels.begin();
    pixels.setBrightness(5);
    pixels.setPixelColor(0, pixels.Color(255, 255, 255));
    pixels.show();
    delay(3000);
    neutral_2();
    neutral_3();
  }

  else if(analogRead(LDR) > 2730){
    pixels.begin();
    pixels.setBrightness(5);
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.show();
    neutral_3();
    tone(BUZ, 50);
  }

  else {
    pixels.begin();
    pixels.setBrightness(5);
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.show();
    bright();
    tone(BUZ, 1000);
  }

  if (analogRead(LDR) > 2730 && digitalRead(VIB) == 0) {
    
    tone(BUZ, 1000, 2000);
    pixels.begin();
    pixels.setBrightness(5);
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();
    evil();
    delay(2000);
  }


  /*if(analogRead(LDR) > 2730 && digitalRead(VIB) == 0) {
    tone(BUZ, 1500);
    delay(2000);
    noTone(BUZ);
  }*/
}
