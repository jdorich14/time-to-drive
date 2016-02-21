#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json/json.h>

#include <mapsapi.h>
#include <MapsData.h>

namespace
{

const std::string MAPS_BASE_URL = "https://maps.googleapis.com/maps/api/distancematrix/json?";

std::string getRequestData(const std::string& requestUrl)
{
    curlpp::Cleanup cleanup;
    curlpp::Easy request;
    std::stringstream dataStream;

    request.setOpt<curlpp::options::Url>(requestUrl);
    request.setOpt<curlpp::options::WriteStream>(&dataStream);
    request.perform();

    return dataStream.str();
}

} // namespace

namespace mapsapi
{

MapsData parseApiData(const std::string& apiData)
{
    Json::Reader reader;
    Json::Value root;

    reader.parse(apiData, root);

    std::string status = root["status"].asString();
    if (status != "OK")
        throw APIException("Query returned status " + status);

    std::string from = root["origin_addresses"][0].asString();
    std::string to = root["destination_addresses"][0].asString();
    int distance = root["rows"][0]["elements"][0]["distance"]["value"].asInt();
    int duration = root["rows"][0]["elements"][0]["duration"]["value"].asInt();

    return MapsData(from, to, distance, duration);
}

MapsData getDistanceInformation(const std::string& from, const std::string& to, const std::string& apiKey)
{
    std::string requestUrl = ::MAPS_BASE_URL + "origins=" + from +
        "&destinations=" + to + "&key=" + apiKey;

    try {
        std::string requestData = ::getRequestData(requestUrl);
        return parseApiData(requestData);
    } catch (curlpp::RuntimeError& e) {
        std::string curlError = std::string(e.what());
        throw APIException("The request could not be made: " + curlError);
    } catch (curlpp::LogicError& e) {
        std::string curlError = std::string(e.what());
        throw APIException("There was an internal cURL error: " + curlError);
    }
}

} // namespace mapsapi
