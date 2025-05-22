#include "User.h"
#include "TicketManager.h"

#include <iostream>

void User::printStations(const std::vector<Station>& stations) const {
    std::cout << "Available stations:\n";
    for (const auto& station : stations) {
        std::cout << "- " << station.getName() << "\n";
    }
}

void User::printSchedule(const Station& station) const {
    station.printSchedule();
}

void User::printScheduleToDestination(const Station& station, const std::string& destination) const {
    station.printScheduleToDestination(destination);
}

void User::printScheduleAfterTime(const Station& station, const std::string& date, const std::string& time) const {
    station.printScheduleAfterTime(date, time);
}

void User::printTrainInfo(const Train& train) const {
    train.printInfo();
}

void User::printWagonInfo(const Train& train, int wagonID) const {
    auto wagon = train.getWagonByID(wagonID);
    if (!wagon) {
        std::cout << "Error: Wagon not found.\n";
        return;
    }
    wagon->printInfo();
}

void User::buyTicket(Train& train, int wagonID, int seatID, const std::string& ticketFileName,
                     const std::vector<std::string>& extraParams) const {
    ::buyTicket(train, wagonID, seatID, ticketFileName, extraParams);
}

void User::buyTicketWithDiscount(Train& train, int wagonID, int seatID, const std::string& ticketFileName,
                                 const std::string& cardFileName, const std::vector<std::string>& extraParams) const {
    ::buyTicketWithDiscount(train, wagonID, seatID, ticketFileName, cardFileName, extraParams);
}
