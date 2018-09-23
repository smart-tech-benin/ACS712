#include <ACS712.h>

ACS712 mySensor = ACS712(A0, ACS712_30);

void setup(){
    // Init serial communication
    Serial.begin(9600);

    // Initialize the sensor - calibration
    mySensor.begin();
}

void loop(){
    Serial.print("Raw: ");
    Serial.print(mySensor.raw());
    Serial.print(", Current: ");
    Serial.print(mySensor.readDC(mA), 3);
    Serial.print(" mA, Offset: ");
    Serial.println(mySensor.getOffset(), 3);
    delay(500);
}
