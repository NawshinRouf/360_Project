#include "DHT.h"
#define DHTPIN 6
// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println("Temperature & Humidity check ");
  dht.begin();
}

void loop() {
 delay(1000);
  float h = dht.readHumidity();
   //float t = dht.readTemperature();
   float f = dht.readTemperature(true);
   // Checks if any readibng fails and exit early (to try again).
   if (isnan(h) || isnan(f)) {
    Serial.println("Failed to get any Data!");
    return;
    }
  Serial.print(h);
  Serial.print("%");
  Serial.println( );
  Serial.print(f);
  Serial.print("*F");
  Serial.println( );
}
