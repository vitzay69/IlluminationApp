#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class IlluminationDevice {
protected:
    std::string deviceName;
    int power;
    std::string* lightSource;
    int brightness;
    std::string lightColor;
    bool isOn;

public:
    IlluminationDevice();
    IlluminationDevice(std::string name, int pwr, std::string source, int bright, std::string color);
    IlluminationDevice(const IlluminationDevice& other);
    virtual ~IlluminationDevice();

    virtual void turnOn();
    virtual void turnOff();
    virtual void adjustBrightness(int newBrightness);
    virtual void changeLightColor(std::string newColor);
    virtual void print() const = 0; // Чиста віртуальна функція

    std::string getDeviceName() const;
    int getPower() const;
    int getBrightness() const;
};
