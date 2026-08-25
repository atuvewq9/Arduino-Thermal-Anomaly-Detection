# Arduino-Thermal-Anomaly-Detection
An Arduino UNO-based embedded system for detecting abnormal temperature conditions in real time using a DHT11 temperature and humidity sensor.

The system continuously monitors the surrounding temperature, validates the sensor data using the DHT11 checksum mechanism, compares the measured temperature against a configurable threshold, and provides an immediate physical indication through LEDs and a relay.

Current prototype: Temperature sensing + data validation + threshold-based decision making + LED/relay indication
Planned upgrade: Buzzer alert + OLED display for real-time status visualization

Thermal anomalies can indicate overheating or potentially unsafe environmental conditions. This project demonstrates a simple, low-cost embedded monitoring system capable of detecting such conditions and generating an immediate response.

The system uses a DHT11 temperature and humidity sensor connected to an Arduino UNO. The Arduino receives digital sensor data, validates the received information using the sensor's checksum, and compares the measured temperature with a configurable threshold of 30°C.(Which can be set according to the conditions)


The system is designed as a prototype that can later be extended with an OLED display and buzzer for enhanced alerting.
