/**
    Powered by Smart Technology Benin
    
    @autor: AMOUSSOU Z. Kenneth
    @date: 11/09/2018
    @version: 1.0
*/
#include "ACS712.h"

ACS712::ACS712(uint8_t input = A0){
    _input = input;
    _offset = 0.0;
}

/**
    function: _calibrate
    @summary: make multiple reading of the analog input in order to compute the
              mean.
    @parameter: none
    @return:
        float: offset voltage of the sensor
*/
float ACS712::_calibrate(){
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
    _calibrate();
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
    @parameter: none
    @return:
        float: value of the measured current in mA
*/
float ACS712::readDC(){
    float buffer = (float)raw();
    buffer = (buffer * 5/1023) * 1000; // voltage in mV
    buffer = buffer - ((_offset * 5/1023) * 1000); // remove offset
    buffer /= SENSITIVITY;  // current in A
    return (buffer * 1000); // current in mA
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
