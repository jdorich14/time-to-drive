#ifndef MAPS_API_H_
#define MAPS_API_H_

#include <string>

namespace mapsapi
{

class MapsData;

MapsData parseApiData(const std::string& apiData);
MapsData getDistanceInformation(const std::string& from, const std::string& to);

} // namespace mapsapi

#endif // MAPS_API_H_
