#pragma once
#include "User.h"
#include <map>
#include "DiscountCard.h"
#include "DiscountCardRegistry.h"

class AdminUser : public User {
private:
    std::string username;

public:
    AdminUser(const std::string& username);
    ~AdminUser() override = default;

    void printStations(const std::vector<Station>& stations) const override;
    void printSchedule(const Station& station) const override;
    void printScheduleToDestination(const Station& station, const std::string& destination) const override;
    void printScheduleAfterTime(const Station& station, const std::string& date, const std::string& time) const override;
    void printTrainInfo(const Train& train) const override;
    void printWagonInfo(const Train& train, int wagonID) const override;
    void buyTicket(Train& train, int wagonID, int seatID, const std::string& ticketFileName,
                   const std::vector<std::string>& extraParams) const override;
    void buyTicketWithDiscount(Train& train, int wagonID, int seatID, const std::string& ticketFileName,
                               const std::string& cardFileName, const std::vector<std::string>& extraParams) const override;

    void addStation(std::vector<Station>& stations, const std::string& name) const;
    void addTrain(Station& from, Station& to, int distance, int speed, const std::string& departureDateTime, int trainID) const;
    void removeTrain(Station& station, int trainID) const;
    void addWagon(Train& train, std::shared_ptr<Wagon> wagon) const;
    void removeWagon(Train& train, int wagonID) const;
    void moveWagon(Train& source, Train& destination, int wagonID) const;
    void createDiscountCard(std::shared_ptr<DiscountCard> card, const std::string& fileName) const;
void validateDiscountCard(const std::string& cardID, DiscountCardRegistry& registry) const;

};
