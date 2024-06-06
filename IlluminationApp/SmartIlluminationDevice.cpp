#include "pch.h"
#include "SmartIlluminationDevice.h"

SmartIlluminationDevice::SmartIlluminationDevice() : BasicIlluminationDevice(), isSmart(false) {}

SmartIlluminationDevice::SmartIlluminationDevice(std::string name, int pwr, std::string source, int bright, std::string color, bool smart)
    : BasicIlluminationDevice(name, pwr, source, bright, color), isSmart(smart) {}

void SmartIlluminationDevice::makeSmart() {
    isSmart = true;
    std::cout << "Device is now smart.\n";
}

void SmartIlluminationDevice::checkEnergySavingMode() const {
    if (brightness < 50) {
        std::cout << "Energy saving mode is activated.\n";
    }
    else {
        std::cout << "Energy saving mode is not activated.\n";
    }
}

void SmartIlluminationDevice::print() const {
    BasicIlluminationDevice::print(); // Виклик методу print() базового класу

    if (isSmart)
        std::cout << "This is a smart device.\n";
    else
        std::cout << "This is not a smart device.\n";

    checkEnergySavingMode(); // Перевірка режиму енергозбереження
}
