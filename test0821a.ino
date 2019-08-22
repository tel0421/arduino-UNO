//定義PIN角名稱
#define RedPin 6
#define potPin A0

// 放置初始設置 , 一次性執行:
void setup() {
 
//115200為跟裝置溝通的頻率
Serial.begin(115200);
//設定RedPin為輸出
pinMode(RedPin,OUTPUT);
pinMode(13,OUTPUT);
}

// 回圈執行:
void loop() {
  digitalWrite(13,LOW);
  //讀取potPin值然後放到potValue中
  int potValue = analogRead(potPin);
  //把potValue轉換成浮點數,除以1023之後乘以255(目的是轉換成8bit數值),並把值放入valueOf8bit中
  int valueOf8bit = (float)potValue/1023 * 255;
  Serial.println(valueOf8bit);
  //每0.1秒,把valueOf8bit值,寫入至RedPin中
  delay(100);analogWrite(RedPin,valueOf8bit);
}
