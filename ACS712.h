/**
    Powered by Smart Technology Benin
    
    @autor: AMOUSSOU Z. Kenneth
    @date: 11/09/2018
    @version: 1.0
*/
#ifndef H_ACS712
#define H_ACS712

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#define ACS712_5    185 //  mV/A
#define ACS712_20   100 //  mV/A
#define ACS712_30   66  //  mV/A

#define A   0
#define mA  1

class ACS712{
    public:
        ACS712(uint8_t input, uint8_t sensitivty);
        int16_t raw(); // read raw data form the sensor
        float readDC(uint8_t unit);
        float readRMS(uint8_t unit); // measure the RMS value of an Alternatif current
        float calibrate();  // Make first calibration of the sensor
        float getOffset();  // read the sensor offset after calibration done
        void begin();       // auto-calibration
        
    private:
        uint8_t _input;
        float _offset;
        uint8_t _sensitivity;      
};

#endif
