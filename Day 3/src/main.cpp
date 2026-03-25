#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
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
}

void loop() {
  /*
  
  if(ldrValue < 1240) tone(BUZ, 1500);
   noTone(BUZ);
  else tone(BUZ, 50);
  */

  pixels.begin();
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.show();
  int ldrValue = analogRead(LDR);
  int vibValue = digitalRead(VIB);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  if(ldrValue < 1240){
    display.setTextSize(7);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("o-o");
    display.display();
    tone(BUZ, 100);
    delay(2000);
    noTone(BUZ);
  }

  else if(ldrValue > 2730){
    display.setTextSize(7);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("-w-");
    display.display();
  }

  else{
    display.setTextSize(7);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("owo");
    display.display();
  }

  if(ldrValue > 2730 && vibValue == 0) {
    display.clearDisplay();
    display.setTextSize(7);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("T-T");
    display.display();
    pixels.setPixelColor(0, pixels.Color(255, 255, 255));
    pixels.show();
    tone(BUZ, 1500);
    delay(2000);
    noTone(BUZ);
  }
}
