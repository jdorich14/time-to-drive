
#include <MapsData.h>

namespace mapsapi
{

MapsData::MapsData() : m_valid(false)
{
}

MapsData::MapsData(const std::string& from, const std::string& to,
                   int distance, int duration) :
    m_from(from),
    m_to(to),
    m_distance(distance),
    m_duration(duration),
    m_valid(true)
{
}

std::ostream& operator<<(std::ostream& stream, const MapsData& mapsData)
{
    if (mapsData.m_valid) {
        stream << "From: '" << mapsData.m_from
               << "' To: '" << mapsData.m_to
               << "' Distance: " << mapsData.m_distance
               << " Duration: " << mapsData.m_duration;
    } else {
        stream << "Invalid";
    }
    return stream;
}

} // namespace mapsapi
