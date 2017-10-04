#include "DHT.h"

// DHT22 DAT pin 
#define DHTPIN 12

// Type of DHT sensor
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  String message = "";

  if (isnan(h) || isnan(t)) {
    return;
  }

  // Create JSON as a message
  message = message + "{\"humidity\": ";
  message = message + h;
  message = message + ", \"temperature\": ";
  message = message + t;
  message = message + "}";

  // Send message
  Serial.println(message);
  
}
