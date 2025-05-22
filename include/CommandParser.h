#pragma once
#include "Session.h"
#include "Station.h"
#include "DiscountCardRegistry.h"

class CommandParser {
private:
    Session& session;
    DiscountCardRegistry& cardRegistry;
    std::vector<Station> stations;
    int nextTrainID = 1000;

    Station* findStationByName(const std::string& name);
    Train* findTrainByID(int id);

public:
    CommandParser(Session& session, DiscountCardRegistry& registry);
    void parseAndExecute(const std::string& commandLine);
};
