#pragma once

#include "BasicIlluminationDevice.h"

class SmartIlluminationDevice : public BasicIlluminationDevice {
private:
    bool isSmart;

public:
    SmartIlluminationDevice();
    SmartIlluminationDevice(std::string name, int pwr, std::string source, int bright, std::string color, bool smart);
    void makeSmart();
    void checkEnergySavingMode() const;
    void print() const override;
};
