/*
  Clock.h - Library for using a digital clock
  Created by Exequiel Magni, March 8, 2022.
*/
 
#include "Arduino.h"

// Guardián de inclusión múltiple
#ifndef Clock_h
#define Clock_h

class Clock
{
private:
    uint8_t _hh;
    uint8_t _mm;
    uint8_t _ss;
public:
    Clock();
    void set_time(uint8_t hh, uint8_t mm, uint8_t ss);
    void reset();
    void increment();
    void add_seconds(uint8_t sec);
    uint8_t get_hour();
    uint8_t get_minutes();
    uint8_t get_seconds();
    void Clock::get_str_time(uint8_t tt, char* buffer, size_t bufferSize)
};

#endif
