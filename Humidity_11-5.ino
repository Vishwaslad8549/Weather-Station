
#include "DHT.h"
#include <LowPower.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Weather Station");

  dht.begin();
  
}

void loop() {
  
  delay(2000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
    delay(2000);
  Serial.println("Arduino:-Going into PowerDown mode");
  delay(200);
   LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
  delay(8000);
  Serial.println("Arduino:- Woke up from Powerdown mode");
  delay(8000);
  Serial.println("Arduino:-Going into idle mode");
  delay(200);
  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                 SPI_OFF, USART0_OFF, TWI_OFF);
 Serial.println("Arduino:- Woke up from idle mode");
   delay(5000);
Serial.println("");
  delay(2000);

}
