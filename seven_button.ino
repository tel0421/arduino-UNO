//導入按鈕標題檔
#include "SwitchButton.h"
//設定12PIN為按鈕使用
SwitchButton Btn(12);

//建立7段顯示的通電腳位矩陣
byte digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // = 0
  { 0, 1, 1, 0, 0, 0, 0 }, // = 1
  { 1, 1, 0, 1, 1, 0, 1 }, // = 2
  { 1, 1, 1, 1, 0, 0, 1 }, // = 3
  { 0, 1, 1, 0, 0, 1, 1 }, // = 4
  { 1, 0, 1, 1, 0, 1, 1 }, // = 5
  { 1, 0, 1, 1, 1, 1, 1 }, // = 6
  { 1, 1, 1, 0, 0, 0, 0 }, // = 7
  { 1, 1, 1, 1, 1, 1, 1 }, // = 8
  { 1, 1, 1, 0, 0, 1, 1 }  // = 9
};

//設定會使用到pin為mapArdiuinoPin矩陣
byte mapArdiuinoPin[] = {2, 3, 4, 5, 6, 7, 8};

//一次性執行
void setup() {
  Serial.begin(115200);
  //把所有會用到輸出的PIN用for迴圈賦予OUTPUT狀態
  for (byte i = 0; i < 7; i++) {
    pinMode(mapArdiuinoPin[i], OUTPUT); //pinMode 這裡設定所要輸出的PIN腳模式
  }
}

void loop() {
  //btnCount = digitalRead(BtnPin);
  unsigned long clickCount = Btn.getStateChangeCount();
  unsigned long getDigit = (clickCount % 20) / 2;
  displayDigit(getDigit);
}

void displayDigit(int displayDigit) {
  int displayIndex = (int)displayDigit;
  for (int i = 0; i < 7 ; i++) {
    bool onePinState = digits[displayIndex][i];
    byte pinNum = mapArdiuinoPin[i];
    digitalWrite(pinNum, onePinState);
    //digitalWrite(ledPin1, HIGH); => 設定ledPin1 腳位為高電位 = 5V LED 亮
  }
}
