//載入按鈕標題檔
#include "SwitchButton.h"

//全域變數
//設定btn pin 12
SwitchButton btn(12);
//設定七段顯示器的陣列
byte digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // = 顯示0
  { 0, 1, 1, 0, 0, 0, 0 }, // = 顯示1
  { 1, 1, 0, 1, 1, 0, 1 }, // = 顯示2
  { 1, 1, 1, 1, 0, 0, 1 }, // = 顯示3
  { 0, 1, 1, 0, 0, 1, 1 }, // = 顯示4
  { 1, 0, 1, 1, 0, 1, 1 }, // = 顯示5
  { 1, 0, 1, 1, 1, 1, 1 }, // = 顯示6
  { 1, 1, 1, 0, 0, 0, 0 }, // = 顯示7
  { 1, 1, 1, 1, 1, 1, 1 }, // = 顯示8
  { 1, 1, 1, 0, 0, 1, 1 }  // = 顯示9
};
//
byte mapArdiuinoPin[] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  Serial.begin(115200);
  for (byte i = 0; i < 7; i++) {
    pinMode(mapArdiuinoPin[i], OUTPUT);
  }
  digitalWrite(9, 0);  // 關閉小數點
}

void loop() {
  unsigned int stateChangeCount = btn.getStateChangeCount();
  switch (stateChangeCount % 20) {
    case 0:
      Serial.println("LED 0");
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 0);
      break;
    case 2:
      Serial.println("LED 1");
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
      break;
    case 4:
      Serial.println("LED 2");
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      digitalWrite(8, 1);
      break;
    case 6:
      Serial.println("LED 3");
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 0);
      digitalWrite(7, 0);
      digitalWrite(8, 1);
      break;
    case 8:
      Serial.println("LED 4");
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
      break;
    case 10:
      Serial.println("LED 5");
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 0);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
      break;
    case 12:
      Serial.println("LED 6");
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
      break;
    case 14:
      Serial.println("LED 7");
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 0);
      digitalWrite(8, 0);
      break;
    case 16:
      Serial.println("LED 8");
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
      break;
    case 18:
      Serial.println("LED 9");
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
      digitalWrite(7, 1);
      digitalWrite(8, 1);
      break;
  }
}

// 暫停 4 秒鐘
