/*
  Clock.cpp - Library for using a digital clock
  Created by Exequiel Magni, March 8, 2022.
*/

#include "Arduino.h"
#include "Clock.h"

Clock::Clock() {}

void Clock::set_time(uint8_t hh, uint8_t mm, uint8_t ss)
{
    _hh = hh;
    _mm = mm;
    _ss = ss;
}

void Clock::reset()
{
    set_time(0, 0, 0);
}

void Clock::increment()
{
    if (_ss < 59)
    {
        _ss++;
    }
    else
    {
        _ss = 0;
        _mm++;
        if (_mm >= 60)
        {
            _mm = 0;
            _hh++;
            if (_hh >= 24)
            {
                _hh = 0;
            }
        }
    }
}

void Clock::add_seconds(int sec)
{
    _ss += sec;
    _mm += _ss / 60;
    _ss = _ss % 60;
    if (_mm >= 60)
    {
        _mm = 0;
        _hh++;
        if (_hh >= 24)
        {
            _hh = 0;
        }
    }
}


uint8_t Clock::get_hour()
{
    return _hh;
}

uint8_t Clock::get_minutes()
{
    return _mm;
}

uint8_t Clock::get_seconds()
{
    return _ss;
}

void Clock::get_str_time(uint8_t tt, char* buffer, size_t bufferSize)
{
  snprintf(buffer, bufferSize, "%02u", tt);
}
