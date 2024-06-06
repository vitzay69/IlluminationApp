#include "pch.h"
#include "BasicIlluminationDevice.h"
#include "SmartIlluminationDevice.h"
#include "DeviceContainer.h"

int main() {
    DeviceContainer container;

    IlluminationDevice* device1 = new BasicIlluminationDevice("Basic Light", 60, "Incandescent", 75, "Soft White");
    IlluminationDevice* device2 = new SmartIlluminationDevice("Smart Light", 75, "LED", 90, "Warm White", true);

    container.addDevice(device1);
    container.addDevice(device2);

    container.listDevices();

    container.removeDevice(device1);
    container.listDevices();

    delete device1;
    delete device2;

    return 0;
}
