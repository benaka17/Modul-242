#include <ArduinoJson.h>
#include <WiFi.h>
#include <M5StickC.h>
#include <HTTPClient.h>

const char* ssid = "HUH";
const char* password = "owoaleowo";

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    M5.Lcd.println("Connecting to WiFi...");
    delay(1000);
  }
  M5.Lcd.println("Connected to WiFi");
  
  Serial.begin(115200); // Initialize serial communication

  // Make HTTP request
  HTTPClient http;
  http.begin("https://transport.opendata.ch/v1/stationboard?station=Horgen&limit=10");
  int httpCode = http.GET();
  if (httpCode != HTTP_CODE_OK) {
    M5.Lcd.println("Error making the request");
    return;
  }

  // Parse JSON response
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, http.getString());
  if (error) {
    M5.Lcd.println("Error parsing the json");
    return;
  }

  // Extract "category" and "number" values
  const char* category = doc["stationboard"][0]["category"];
  const char* number = doc["stationboard"][0]["number"];
  M5.Lcd.print("Category: ");
  M5.Lcd.println(category);
  M5.Lcd.print("Number: ");
  M5.Lcd.println(number);
  Serial.println(category);
  Serial.println(number); // Print the values to the serial monitor

  http.end();
}

void loop() {
}
