/**
    @author: AMOUSSOU Z. Kenneth
    @date: 23-09-2018
    @summary: measure the Root Mean Square current of an AC current
*/
#include <ACS712.h>

ACS712 mySensor = ACS712(A0, ACS712_30);

void setup(){
    // Init serial communication
    Serial.begin(9600);

    // Initialize the sensor - calibration
    mySensor.begin();
}

void loop(){
    Serial.print("RMS Current: ");
    Serial.print(mySensor.readRMS(mA), 3);
    Serial.println(" mA ");
    delay(500);
}
