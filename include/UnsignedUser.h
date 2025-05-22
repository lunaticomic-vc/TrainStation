#pragma once
#include "User.h"

class UnsignedUser : public User {
public:
    UnsignedUser() = default;
    ~UnsignedUser() override = default;

    void printStations(const std::vector<Station>& stations) const override;
    void printSchedule(const Station& station) const override;
    void printScheduleToDestination(const Station& station, const std::string& destination) const override;
    void printScheduleAfterTime(const Station& station, const std::string& date, const std::string& time) const override;
    void printTrainInfo(const Train& train) const override;
    void printWagonInfo(const Train& train, int wagonID) const override;

    void buyTicket(Train& train, int wagonID, int seatID, const std::string& ticketFileName, const std::vector<std::string>& extraParams) const override;

    void buyTicketWithDiscount(Train& train, int wagonID, int seatID, const std::string& ticketFileName, const std::string& cardFileName, const std::vector<std::string>& extraParams) const override;
};
