#include <fstream>
#include <iostream>
#include <string>

#include <gtest/gtest.h>

#include <mapsapi.h>
#include <MapsData.h>

int main()
{
    using namespace mapsapi;

    std::ifstream apiKeyStream("../apikey");
    std::string apiKey;

    apiKeyStream >> apiKey;

    std::string startLocation = "Marlborough+MA";
    std::string endLocation = "Quincy+MA";

    MapsData data = getDistanceInformation(startLocation, endLocation, apiKey);
    std::cout << data << std::endl;

    return 0;
}
