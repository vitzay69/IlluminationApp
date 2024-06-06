#include "pch.h"
#include "BasicIlluminationDevice.h"

BasicIlluminationDevice::BasicIlluminationDevice() : IlluminationDevice() {}

BasicIlluminationDevice::BasicIlluminationDevice(std::string name, int pwr, std::string source, int bright, std::string color)
    : IlluminationDevice(name, pwr, source, bright, color) {}

void BasicIlluminationDevice::print() const {
    std::cout << "Illumination Device: " << deviceName << "\n";
    std::cout << "Power: " << power << "W\n";
    std::cout << "Light Source: " << (*lightSource) << "\n";
    std::cout << "Brightness: " << brightness << "\n";
    std::cout << "Light Color: " << lightColor << "\n";
    std::cout << "Device is " << (isOn ? "on" : "off") << "\n";
}
