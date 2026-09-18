#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define RELAY_PIN 7
#define GREEN_LED 8
#define RED_LED 10

#define TEMP_THRESHOLD 30.0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.println("=================================");
  Serial.println(" Arduino Thermal Anomaly Detection");
  Serial.println("=================================");
  Serial.println("System Started...");
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

 
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("ERROR: Invalid DHT11 sensor data!");

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(RELAY_PIN, LOW);

    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (temperature >= TEMP_THRESHOLD) {

    
    Serial.println("WARNING: Thermal Anomaly Detected!");

    digitalWrite(GREEN_LED, LOW);

    
    digitalWrite(RED_LED, HIGH);

    digitalWrite(RELAY_PIN, HIGH);

  } else {

  
    Serial.println("STATUS: Temperature Normal.");

    digitalWrite(RED_LED, LOW);

    
    digitalWrite(GREEN_LED, HIGH);

    digitalWrite(RELAY_PIN, LOW);
  }

  Serial.println("---------------------------------");

  delay(2000);
}