#ifndef MAPS_DATA_H_
#define MAPS_DATA_H_

#include <iostream>
#include <string>

namespace mapsapi
{

class MapsData
{
public:
    MapsData();
    MapsData(const std::string& from, const::std::string& to, int distance,
             int duration);

    std::string from() { return m_from; }
    std::string to() { return m_to; }
    int distance() { return m_distance; }
    int duration() { return m_duration; }
    bool valid() { return m_valid; }

    friend std::ostream& operator<<(std::ostream& stream,
                                    const MapsData& mapsData);

private:
    std::string m_from;
    std::string m_to;
    int m_distance;
    int m_duration;
    bool m_valid;

}; // class MapsData

} // namespace mapsapi

#endif // MAPS_DATA_H_
