// Pin to which the SENS-34UV Sensor is connected
const int sensorPin = A4;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Read the analog voltage from the sensor
  int sensorValue = analogRead(sensorPin);
  // Print the raw sensor value and calculated UV index
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  // Add if statements to print values based on sensorValue ranges
  if (sensorValue >= 1 && sensorValue <= 300) {
    Serial.println("Value: 1");
  } else if (sensorValue >= 301 && sensorValue <= 600) {
    Serial.println("Value: 2");
  } else if (sensorValue >= 601 && sensorValue <= 900) {
    Serial.println("Value: 3");
  } else if (sensorValue >= 901 && sensorValue <= 1200) {
    Serial.println("Value: 4");
  } else if (sensorValue >= 1201 && sensorValue <= 1500) {
    Serial.println("Value: 5");
  } else if (sensorValue >= 1501 && sensorValue <= 1800) {
    Serial.println("Value: 6");
  } else if (sensorValue >= 1801 && sensorValue <= 2100) {
    Serial.println("Value: 7");
  } else if (sensorValue >= 2101 && sensorValue <= 2400) {
    Serial.println("Value: 8");
  } else if (sensorValue >= 2401 && sensorValue <= 2700) {
    Serial.println("Value: 9");
  } else if (sensorValue >= 2701 && sensorValue <= 3000) {
    Serial.println("Value: 10");
  }

  delay(10000/2); 
}


