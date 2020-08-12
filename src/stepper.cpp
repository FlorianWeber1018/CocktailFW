#include "stepper.hpp"
#include "FunctionalInterrupt.h"
#include "Arduino.h"

#include <functional>

Stepper::Stepper(uint8_t clkPin, uint8_t dirPin, uint8_t enPin, uint8_t positionSwitchPin, uint16_t range)
{
    clkPin_m = clkPin;
    dirPin_m = dirPin;
    enPin_m = enPin;
    positionSwitchPin_m = positionSwitchPin;
    range_m = range;

    pinMode(clkPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(enPin, OUTPUT);
    pinMode(positionSwitchPin, INPUT_PULLUP);
    digitalWrite(enPin, 1);
    digitalWrite(dirPin, 1);
    timer_m = timerBegin()
        attachInterrupt(
            digitalPinToInterrupt(positionSwitchPin), std::bind(&Stepper::positionSwitchISR, this), RISING);
}
void Stepper::moveRel(int16_t dtg)
{
}
void Stepper::moveAbs(int16_t position)
{
    moveRel(position - actualPosition_m);
}
void Stepper::moveConti(uint8_t speed)
{
    if (speed >= 0)
    {
    }
    else
    {
    }
}
void Stepper::makeReferenceRun()
{
    moveConti(-5);
    while (!calibrated_m)
    {
        sleep(10);
    }
}
void IRAM_ATTR Stepper::positionSwitchISR()
{
    actualPosition_m = 0;
    calibrated_m = true;
}
void startOutput
{
}