#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 
int time_sec;
char str [20];

 void setup(void) {
   u8g2.begin();
   time_sec=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  time_sec=millis()/1000;
  sprintf(str,"sec:%d", time_sec);
  
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2.drawStr(0,29,str);  // write something to the internal memory
  u8g2.sendBuffer();         // transfer internal memory to the display
  delay(100);
}
