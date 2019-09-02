#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

//使用firebaseData建立firebaseData
FirebaseData firebaseData;

void setup()
{
  //連線WIFI
  Serial.begin(115200);
  Serial.println();
  WiFi.begin("0gm2", "2773524311");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  //連線firebase
  Firebase.begin("iot-class-tel5380.firebaseio.com", "MghZN4LbDvjXRGA8FT4phVSydYnWulWw3Ae54n0b");
  Firebase.reconnectWiFi(true);
  Firebase.setMaxRetry(firebaseData, 3);
  Firebase.setMaxErrorQueue(firebaseData, 30);
}

void loop() {

  if (Firebase.getBool(firebaseData, "/iot0624/LED")) {
    if (firebaseData.dataType() == "boolean") {
      Serial.println(firebaseData.boolData());
    }

  } else {
    Serial.println(firebaseData.errorReason());
  }

  delay(500);
}
