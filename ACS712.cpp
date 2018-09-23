/**
    Powered by Smart Technology Benin
    
    @autor: AMOUSSOU Z. Kenneth
    @date: 11/09/2018
    @version: 1.0
*/
#include "ACS712.h"

ACS712::ACS712(uint8_t input = A0, uint8_t sensitivity = ACS712_5){
    _input = input;
    _offset = 512.0; // default offset value
    _sensitivity = sensitivity;
}

/**
    function: calibrate
    @summary: make multiple reading of the analog input in order to compute the
              mean.
    @parameter: none
    @return:
        float: offset voltage of the sensor
*/
float ACS712::calibrate(){
    uint8_t i = 0;
    for(i = 0; i < 150; i++){
        _offset += analogRead(_input);
        delayMicroseconds(10);
    }
    _offset /= 150;
    return _offset;
}

/**
    function: begin
    @summary: apply calibration on the sensor to get it's offset
    @parameter: none
    @return: none
*/
void ACS712::begin(){
    // TODO: maybe used for futher preprocessing when measuring AC current
    calibrate();
}

/**
    function: raw
    @summary: read multiple raw data from the sensor and compute the mean
    @parameter: none
    @return:
        int16_t: return the mean of analogRead value
*/
int16_t ACS712::raw(){
    float buffer = 0.0;
    uint8_t i = 0;
    for(i = 0; i < 10; i++){
        buffer += analogRead(_input);
        delayMicroseconds(10);
    };
    buffer /= i;   // read the mean over 10 reading
    return buffer;
}

/**
    function: readDC
    @summary: compute the raw data get form sensor to obtain the corresponding 
              current
    @parameter:
        unit: the unit of the current we want to be returned
              [0]: A
              [1]: mA
    @return:
        float: value of the measured current in mA by default
*/
float ACS712::readDC(uint8_t unit = mA){
    float buffer = (float)raw();
    buffer = (buffer * 5/1023) * 1000; // voltage in mV
    buffer = buffer - ((_offset * 5/1023) * 1000); // remove offset
    buffer /= _sensitivity;  // current in A
    if(unit == A) return buffer;
    else return (buffer * 1000); // current in mA
}

/**
    function: getOffset
    @summary: read the offset of the sensor
    @parameter: none
    @return:
        float: offset the sensor set during calibration
*/
float ACS712::getOffset(){
    return _offset;
}
