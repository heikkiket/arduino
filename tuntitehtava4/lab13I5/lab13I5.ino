#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R2);
int time_sec = 0;
int time_min = 0;
int time_h = 0;
char str [20];

void setup(void) {
   u8g2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  time_sec=millis()/1000%60;
  time_min=millis()/60000%60;
  time_h=millis()/3600000%24;
  
  sprintf(str,"%02d:%02d:%02d", time_h,time_min,time_sec);
  
  
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2.drawStr(0,29,str);  // write something to the internal memory
  u8g2.sendBuffer();         // transfer internal memory to the display
  delay(100);
}
