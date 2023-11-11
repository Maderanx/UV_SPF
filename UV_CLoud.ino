/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/b417c5df-5568-4e2d-942d-6b995e8aad10 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  String spfmsg;
  int sensorValue;
  int spf;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  int sensorValue = analogRead(A4);
  // Print the raw sensor value and calculated UV index
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  if (sensorValue >= 0 && sensorValue <= 300) {
    spf=1;
    spfmsg="No need for sunscreen";
  } else if (sensorValue >= 301 && sensorValue <= 600) {
    spf=2;
    spfmsg="Use spf 15+ sunscreen";
  } else if (sensorValue >= 601 && sensorValue <= 900) {
    spf=3;
    spfmsg="Use spf 15+ sunscreen";
  } else if (sensorValue >= 901 && sensorValue <= 1200) {
    spf=4;
    spfmsg="Use spf 30+ sunscreen";
  } else if (sensorValue >= 1201 && sensorValue <= 1500) {
    spf=5;
    spfmsg="Use spf 30+ sunscreen";
  } else if (sensorValue >= 1501 && sensorValue <= 1800) {
    spf=6;
    spfmsg="Use spf 50+ sunscreen";
  } else if (sensorValue >= 1801 && sensorValue <= 2100) {
    spf=7;
    spfmsg="Use spf 50+ sunscreen";
  } else if (sensorValue >= 2101 && sensorValue <= 2400) {
    spf=8;
    spfmsg="Seek shelter";
  } else if (sensorValue >= 2401 && sensorValue <= 2700) {
    spf=9;
    spfmsg="Seek shelter";
  } else if (sensorValue >= 2701 && sensorValue <= 3000) {
    spf=10;
    spfmsg="Seek shelter";
  }

  delay(10000/2);
}


/*
  Since SensorValue is READ_WRITE variable, onSensorValueChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSensorValueChange()  {
  // Add your code here to act upon SensorValue change
  
  delay(10000/2); 
}

/*
  Since Spf is READ_WRITE variable, onSpfChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSpfChange()  {
  // Add your code here to act upon Spf change
}

/*
  Since Spfmsg is READ_WRITE variable, onSpfmsgChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSpfmsgChange()  {
  // Add your code here to act upon Spfmsg change
}