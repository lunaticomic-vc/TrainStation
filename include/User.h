#pragma once
#include <string>
#include <vector>
#include "Train.h"
#include "Station.h"

class User {
public:
    virtual ~User() = default;

    virtual void printStations(const std::vector<Station>& stations) const = 0;
    virtual void printSchedule(const Station& station) const = 0;
    virtual void printScheduleToDestination(const Station& station, const std::string& destination) const = 0;
    virtual void printScheduleAfterTime(const Station& station, const std::string& date, const std::string& time) const = 0;
    virtual void printTrainInfo(const Train& train) const = 0;
    virtual void printWagonInfo(const Train& train, int wagonID) const = 0;
    virtual void buyTicket(Train& train, int wagonID, int seatID, const std::string& ticketFileName,
                           const std::vector<std::string>& extraParams) const = 0;
    virtual void buyTicketWithDiscount(Train& train, int wagonID, int seatID, const std::string& ticketFileName,
                                       const std::string& cardFileName, const std::vector<std::string>& extraParams) const = 0;
};
