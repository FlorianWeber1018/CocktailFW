#include "HX711.h"
#ifndef loadCell__h
#define loadCell__h
class LoadCell : private HX711
{
public:
    LoadCell(uint8_t dataOutPin, uint8_t sckPin, uint8_t gain = 128);

private:
};
#endif