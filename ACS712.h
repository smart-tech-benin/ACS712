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

// Uncomment the one of the following line which map with your sensor specification
//#define SENSITIVITY ACS712_5
//#define SENSITIVITY ACS712_20
#define SENSITIVITY ACS712_30

class ACS712{
    public:
        ACS712(uint8_t input);
        uint16_t raw(); // read raw data form the sensor
        float readDC();
        void begin();   // Required to make first calibration of the sensor
                        // Calibration is only done once - in `begin` only -
        float getOffset();  // read the sensor offset after calibration done
        
    private:
        float _calibrate();  // Make first calibration of the sensor
        uint8_t _input;
        float _offset;        
};

#endif
