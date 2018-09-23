# ACS712

The Allegro TM ACS712 provides economical and precise solutions for AC or DC 
current sensing in industrial, commercial, and communications systems. The 
device package allows for easy implementation by the customer. Typical applications
include motor control, load detection and management, switch-mode power supplies, 
and overcurrent fault protection. The device is not intended for automotive 
applications.

The device consists of a precise, low-offset, linear Hall circuit with a copper 
conduction path located near the surface of the die. Applied current flowing 
through this copper conduction path generates a magnetic field which the Hall 
IC converts into a proportional voltage. Device accuracy is optimized through 
the close proximity of the magnetic signal to the Hall transducer.

## Features and Benefits

- Low-noise analog signal path
- Device bandwidth is set via the new FILTER pin
- 5 μs output rise time in response to step input current
- 80 kHz bandwidth
- Total output error 1.5% at Ta = 25°C
- Small footprint, low-profile SOIC8 package
- 1.2 mΩ internal conductor resistance
- 2.1 kVRMS minimum isolation voltage from pins 1-4 to pins 5-8
- 5.0 V, single supply operation
- 66 to 185 mV/A output sensitivity
- Output voltage proportional to AC or DC currents
- Factory-trimmed for accuracy
- Extremely stable output offset voltage
- Nearly zero magnetic hysteresis
- Ratiometric output from supply voltage

## The library

### How it work

This library offert a simple way to operate the ACS712 sensor. You can found an 
example in the example folder.

- Setup

```c++
    ACS712 mySensor = ACS712(A0, ACS712_30);
    
    void setup(){
        mySensor.begin(); // calibrate the sensor
    }
```

### Methods

```c++
    ACS712(uint8_t input, uint8_t sensitivty)
```

The constructor take two parameter:

- input: the analog input  used for the sensor
- sensitivity: the sensitivit of the sensor. This value depends on the range of 
the sensor measurement. So, we get three predefined constant for that
    - ACS712_5 - 185 mV/A
    - ACS712_20 - 100 mV/A
    - ACS712_30 - 66 mV/A

```c++
    int16_t raw()      // read raw data from the sensor
```

```c++
    float readDC(uint8_t unit)   // read DC current (process raw data)
```

`uint` specifie the unit of the returned value of the `readDC` methods. It could 
be two of the predefined constant:

- `A` for Ampere
- `mA` for milli Ampere

```c++
    float calibrate();  // Make first calibration of the sensor
```

```c++
    float getOffset();  // read the sensor offset after calibration done
```
 If none calibration is done the `offset` of the sensor is`512`



