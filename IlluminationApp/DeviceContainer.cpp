#include "pch.h"
#include "DeviceContainer.h"
#include <iostream>
#include <algorithm>

void DeviceContainer::addDevice(IlluminationDevice* device) {
    devices.push_back(device);
}

void DeviceContainer::removeDevice(IlluminationDevice* device) {
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}

IlluminationDevice* DeviceContainer::findDeviceByName(const std::string& name) {
    auto it = std::find_if(devices.begin(), devices.end(), [&name](IlluminationDevice* device) {
        return device->getDeviceName() == name;
        });
    return it != devices.end() ? *it : nullptr;
}

void DeviceContainer::deleteDeviceByName(const std::string& name) {
    auto it = std::find_if(devices.begin(), devices.end(), [&name](IlluminationDevice* device) {
        return device->getDeviceName() == name;
        });
    if (it != devices.end()) {
        delete* it;
        devices.erase(it);
    }
}

void DeviceContainer::listDevices() const {
    for (const auto& device : devices) {
        device->print();
    }
}

DeviceContainer::~DeviceContainer() {
    for (auto& device : devices) {
        delete device;
    }
}
