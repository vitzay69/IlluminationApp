#include "pch.h"
#include "IlluminationDevice.h"

IlluminationDevice::IlluminationDevice() : deviceName(""), power(0), lightSource(nullptr), brightness(0), lightColor(""), isOn(false) {}

IlluminationDevice::IlluminationDevice(std::string name, int pwr, std::string source, int bright, std::string color)
    : deviceName(name), power(pwr), brightness(bright), lightColor(color), isOn(false) {
    lightSource = new std::string(source);
}

IlluminationDevice::IlluminationDevice(const IlluminationDevice& other)
    : deviceName(other.deviceName), power(other.power), brightness(other.brightness), lightColor(other.lightColor), isOn(other.isOn) {
    lightSource = new std::string(*(other.lightSource));
}

IlluminationDevice::~IlluminationDevice() {
    delete lightSource;
}

void IlluminationDevice::turnOn() {
    isOn = true;
}

void IlluminationDevice::turnOff() {
    isOn = false;
}

void IlluminationDevice::adjustBrightness(int newBrightness) {
    brightness = newBrightness;
}

void IlluminationDevice::changeLightColor(std::string newColor) {
    lightColor = newColor;
}

std::string IlluminationDevice::getDeviceName() const {
    return deviceName;
}

int IlluminationDevice::getPower() const {
    return power;
}

int IlluminationDevice::getBrightness() const {
    return brightness;
}
