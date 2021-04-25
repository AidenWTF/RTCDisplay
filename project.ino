#include <SPI.h>

#include <Wire.h>

#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>

#include "RTClib.h"

RTC_DS3231 rtc;
#define OLED_RESET 4 // not used / nicht genutzt bei diesem Display
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
  Serial.begin(9600);
  delay(3000);
 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  


}

#define DRAW_DELAY 118
#define D_NUM 47

int i;

void loop() {
  if (!rtc.begin()) {
    //display.clearDisplay();
    display.setCursor(1, 1);
    display.print("RTC Error #1302");
    display.display();
  } else {
    DateTime now = rtc.now();
    display.clearDisplay();

    // set text color / Textfarbe setzen
    display.setTextColor(WHITE);
    // set text size / Textgroesse setzen
    display.setTextSize(1);
    // set text cursor position / Textstartposition einstellen
    display.setCursor(1, 1);
    // show text / Text anzeigen
    display.print(daysOfTheWeek[now.dayOfTheWeek()]);
    //  display.print(", ");
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
    // show text / Text anzeigen

    display.display();
    delay(500);
    display.clearDisplay();

  }

}
