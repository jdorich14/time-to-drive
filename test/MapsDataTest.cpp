#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include <mapsapi.h>
#include <MapsData.h>

int main()
{
    using namespace mapsapi;

    std::string startLocation = "Marlborough+MA";
    std::string endLocation = "Quincy+MA";

    MapsData data = getDistanceInformation(startLocation, endLocation);
    std::cout << data << std::endl;

    return 0;
}
