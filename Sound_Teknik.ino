//Video Tutorial @elasdump on TikTok!

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* lyrics[] = {
  "Sudah terbiasa",
  "Terjadi",
  "Tante",
  "Teman datang",
  "Ketika",
  "Lagi",
  "Butuh saja",
  "Coba",
  "Kalau",
  "Lagi susah",
  "Mereka semua",
  "Mereka semua",
  "Menghilaaang",
};

const int numLines = sizeof(lyrics) / sizeof(lyrics[0]);
int currentLine = 0;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1); 
  display.setTextColor(SSD1306_WHITE);
  display.display(); 
}

void loop() {
  display.clearDisplay(); 

  int16_t x, y; 
  uint16_t textWidth, textHeight; 
  display.getTextBounds(lyrics[currentLine], 0, 0, &x, &y, &textWidth, &textHeight);

  display.setCursor((SCREEN_WIDTH - textWidth) / 2, (SCREEN_HEIGHT - textHeight) / 2); 
  display.println(lyrics[currentLine]); 
  display.display(); 

  currentLine++; 
  if (currentLine >= numLines) {
    currentLine = 0; 
  }

  delay(950);
}