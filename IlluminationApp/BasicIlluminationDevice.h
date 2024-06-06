#pragma once

#include "IlluminationDevice.h"

class BasicIlluminationDevice : public IlluminationDevice {
public:
    BasicIlluminationDevice();
    BasicIlluminationDevice(std::string name, int pwr, std::string source, int bright, std::string color);
    void print() const override;
};
