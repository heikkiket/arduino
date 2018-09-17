#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R2); 
int time_sec = 0;
char str [20];
const int buttonPin = 2;
const int ledPin =  13;

int buttonState = 0;
bool ledState = 0;

unsigned long last_time;
unsigned long blink_time;

void setup(void) {
   u8g2.begin();

   pinMode(ledPin, OUTPUT);
   pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    time_sec = 30;
    last_time = millis();
  }
  
  if(millis()-last_time>1000) {
    if(time_sec > 0) {
      time_sec--;
    }
    last_time = millis();
  }

  if(time_sec < 5 && time_sec > 0) {
    blink();
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  
  sprintf(str,"sec:%d", time_sec);
  
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2.drawStr(0,29,str);  // write something to the internal memory
  u8g2.sendBuffer();         // transfer internal memory to the display
  delay(10);
}

void blink() {
  if(millis()-blink_time > 250) {
    blink_time=millis();
  } else {
    return;
  }
  
  if(ledState == 0) {
    digitalWrite(ledPin, HIGH);
    ledState = 1;
  } else {
    digitalWrite(ledPin, LOW);
    ledState = 0;
  }
}
