#include <SPI.h>

#include <Wire.h>

#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>

#include "RTClib.h"

RTC_DS3231 rtc;

Adafruit_SSD1306 display(OLED_RESET);
char daysOfTheWeek[7][12] = {
  "Sonntag",
  "Montag",
  "Dienstag",
  "Mittwoch",
  "Donnerstag",
  "Freitag",
  "Samstag"
};

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Setting Time/Date
}

void loop() {
  if (!rtc.begin()) {
    display.setCursor(1, 1);
    display.print("RTC Error #1302");
    display.display();
  } 
  else {
    DateTime now = rtc.now();
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(1, 1);
    display.print(daysOfTheWeek[now.dayOfTheWeek()]);
    display.setCursor(1, 10);
    display.print(now.day());
    display.print(".");
    display.print(now.month());
    display.print(".");
    display.print(now.year());
    display.setCursor(1, 20);
    display.print(now.hour());
    display.print(':');
    display.print(now.minute());
    display.print(':');
    display.print(now.second());
    display.display();
    delay(500);
    display.clearDisplay();
    }
}
