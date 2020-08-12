#ifndef stepper__h
#define stepper__h
#include <stdint.h>
class Stepper
{
public:
    Stepper(uint8_t clkPin, uint8_t dirPin, uint8_t enPin, uint8_t positionSwitchPin, uint16_t range);
    void moveRel(int16_t dtg);
    void moveAbs(int16_t position);
    void moveConti(uint8_t speed);
    void makeReferenceRun();

protected:
    uint8_t clkPin_m;
    uint8_t dirPin_m;
    uint8_t enPin_m;
    uint8_t positionSwitchPin_m;
    uint16_t range_m;
    bool calibrated_m = false;
    uint16_t actualPosition_m = 0;
    hw_timer_t *timer_m = nullptr;
    void positionSwitchISR();
};
class TimerFactory
{
public:
protected:
    std::vector<uint8_t> timerPool { 0, 1, 2, 3 }
}
#endif