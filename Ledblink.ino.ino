void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    char x= Serial.read();
    if (x =='0'){
      digitalWrite(13,LOW);
    }else{
      digitalWrite(13, HIGH);
    }
    }
    }
