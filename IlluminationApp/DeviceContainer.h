#pragma once

#include "IlluminationDevice.h"
#include <vector>

class DeviceContainer {
private:
    std::vector<IlluminationDevice*> devices;

public:
    void addDevice(IlluminationDevice* device);
    void removeDevice(IlluminationDevice* device);
    IlluminationDevice* findDeviceByName(const std::string& name);
    void deleteDeviceByName(const std::string& name);
    void listDevices() const;
    ~DeviceContainer();
};
