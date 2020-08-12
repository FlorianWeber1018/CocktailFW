#include "loadCell.hpp"

LoadCell::LoadCell(uint8_t dataOutPin, uint8_t sckPin, uint8_t gain)
{
    begin(dataOutPin, sckPin, gain);
}