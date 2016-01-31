#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json/json.h>

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char** argv) {
    std::string mapsUrl = "https://maps.googleapis.com/maps/api/distancematrix/json?origins=";
    std::string startLocation = "Marlborough+MA";
    std::string endLocation = "Quincy+MA";

    std::string requestUrl = mapsUrl + startLocation + "&destinations=" + endLocation;

    curlpp::Cleanup cleanup;
    curlpp::Easy request;
    std::stringstream dataStream;

    std::cout << "Requesting " << requestUrl << std::endl;
    request.setOpt<curlpp::options::Url>(requestUrl);
    request.setOpt<curlpp::options::WriteStream>(&dataStream);
    request.perform();

    Json::Reader reader;
    Json::Value root;
    // We can pass the stringstream directly to reader.parse, but creating a
    // string first allows us to view it.
    std::string apiData = dataStream.str();
    reader.parse(apiData, root);
    std::string status = root["status"].asString();
    std::cout << "Data: " << apiData << std::endl;

    if (status != "OK") {
        std::cerr << "The request was not successful" << std::endl;
    } else {
        std::cout << "The request was successful" << std::endl;
        std::string origin = root["origin_addresses"][0].asString();
        std::string destination = root["destination_addresses"][0].asString();
        std::string distance = root["rows"][0]["elements"][0]["distance"]["text"].asString();
        std::string duration = root["rows"][0]["elements"][0]["duration"]["text"].asString();
        std::cout << "The distance from " << origin << " to " << destination
                  << " is " << distance << std::endl;
        std::cout << "The time from " << origin << " to " << destination
                  << " is " << duration << std::endl;
    }

    return 0;
}
