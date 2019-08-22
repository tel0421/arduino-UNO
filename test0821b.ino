//定義PIN角名稱
#define RedPin 6
#define potPin A0
unsigned long noteTime = millis();

// 放置初始設置 , 一次性執行:
void setup() {
  //115200為跟裝置溝通的頻率
  Serial.begin(115200);
  //設定RedPin為輸出
  pinMode(RedPin, OUTPUT);
}

// 回圈執行:
void loop() {
  doSomeThing();
}


void doSomeThing() {

  unsigned long currentTime = millis();
  if ((currentTime - noteTime) >= 150) {
    noteTime = currentTime;

    int potValue = analogRead(potPin);
    int valueOf8bit = (float)potValue / 1023 * 255;
    Serial.println(valueOf8bit);
    analogWrite(RedPin, valueOf8bit);
  }
}
