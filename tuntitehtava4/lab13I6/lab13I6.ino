#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R2); 
int time_sec = 0;
int time_min = 0;
int time_h = 0;
char str [20];

const int button1Pin = 2;
const int button2Pin = 4;
const int button3Pin = 7;
const int button4Pin = 8;

int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;

bool runClock = 1;

void setup(void) {
   u8g2.begin();

   pinMode(button1Pin, INPUT);
   pinMode(button2Pin, INPUT);
   pinMode(button3Pin, INPUT);
   pinMode(button4Pin, INPUT);
}

void loop() {
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  button4State = digitalRead(button4Pin);

  // put your main code here, to run repeatedly:

  if(button1State == HIGH) {
    if (runClock) {
      runClock = 0;
    } else {
      runClock = 1;
    }
    delay(100);
  }

  if(button2State == HIGH) {
    updateH();
  }

  if(button3State == HIGH) {
    updateMin();
  }

  if(button4State == HIGH) {
    updateSec();
  }
  
  if(runClock) {
    updateSec();
    updateMin();
    updateH();
  }

  sprintf(str,"%02d:%02d:%02d", time_h,time_min,time_sec);

  
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2.drawStr(0,29,str);  // write something to the internal memory
  u8g2.sendBuffer();         // transfer internal memory to the display
  delay(100);
}

void updateSec() {
  time_sec=millis()/1000%60;
}
void updateMin() {
  time_min=millis()/60000%60;
}
void updateH() {
  time_h=millis()/3600000%24;
}
