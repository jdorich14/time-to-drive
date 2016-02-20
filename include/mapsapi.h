#ifndef MAPS_API_H_
#define MAPS_API_H_

#include <exception>
#include <string>

namespace mapsapi
{

class MapsData;

class APIException : public std::runtime_error
{
public:
    APIException(const std::string& reason) :
        std::runtime_error(reason)
    {
    }

    virtual ~APIException () throw()
    {
    }

private:
    std::string m_reason;
};

MapsData parseApiData(const std::string& apiData);
MapsData getDistanceInformation(const std::string& from, const std::string& to);

} // namespace mapsapi

#endif // MAPS_API_H_
