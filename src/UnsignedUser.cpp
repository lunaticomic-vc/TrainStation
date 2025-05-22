#include "UnsignedUser.h"
#include "TicketManager.h"
#include <iostream>

void UnsignedUser::printStations(const std::vector<Station>& stations) const {
    for (const auto& s : stations)
        std::cout << "- " << s.getName() << "\n";
}

void UnsignedUser::printSchedule(const Station& station) const {
    station.printSchedule();
}

void UnsignedUser::printScheduleToDestination(const Station& station, const std::string& destination) const {
    station.printScheduleToDestination(destination);
}

void UnsignedUser::printScheduleAfterTime(const Station& station, const std::string& date, const std::string& time) const {
    station.printScheduleAfterTime(date, time);
}

void UnsignedUser::printTrainInfo(const Train& train) const {
    train.printInfo();
}

void UnsignedUser::printWagonInfo(const Train& train, int wagonID) const {
    auto w = train.getWagonByID(wagonID);
    if (w) w->printInfo();
    else std::cout << "Wagon not found.\n";
}

void UnsignedUser::buyTicket(Train& train, int wagonID, int seatID, const std::string& ticketFileName,
                             const std::vector<std::string>& extraParams) const {
    ::buyTicket(train, wagonID, seatID, ticketFileName, extraParams);
}

void UnsignedUser::buyTicketWithDiscount(Train& train, int wagonID, int seatID, const std::string& ticketFileName,
                                         const std::string& cardFileName, const std::vector<std::string>& extraParams) const {
    ::buyTicketWithDiscount(train, wagonID, seatID, ticketFileName, cardFileName, extraParams);
}
