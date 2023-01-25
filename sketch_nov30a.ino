#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* server = "transport.opendata.ch";

void setup() {
  WiFi.begin("HUH", "owoaleowo");
  Serial.begin(115200); // Initialize serial communication
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi"); 
}

void loop() {
  HTTPClient http;
  http.begin("https://transport.opendata.ch/v1/stationboard?station=Horgen&limit=10");
  int httpCode = http.GET();
  if (httpCode > 0) {
    String payload = http.getString();
    StaticJsonDocument<1000> doc;
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.c_str());
      return;
    }
    //Access the "stationboard" array in the JSON data
    JsonArray stationboard = doc["stationboard"];
    for(int i=0; i< stationboard.size(); i++){
      String category = stationboard[i]["category"];
      String number = stationboard[i]["number"];
      Serial.println("category: " + category + ", number: " + number);
    }
  }
  else {
    Serial.print("Error: ");
    Serial.println(httpCode);
  }
  http.end();
}
