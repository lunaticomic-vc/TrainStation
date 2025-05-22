#include "AdminUser.h"
#include "TicketManager.h"
#include "Train.h"
#include "Station.h"
#include "Wagon.h"
#include "DiscountCard.h"
#include "AgeCard.h"
#include "RouteCard.h"
#include "DistanceCard.h"
#include "FirstClassWagon.h"
#include "SecondClassWagon.h"
#include "SleeperWagon.h"
#include <iostream>
#include <fstream>

AdminUser::AdminUser(const std::string& username) : username(username) {}

void AdminUser::printStations(const std::vector<Station>& stations) const {
    for (const auto& s : stations) std::cout << "- " << s.getName() << "\n";
}
void AdminUser::printSchedule(const Station& s) const { s.printSchedule(); }
void AdminUser::printScheduleToDestination(const Station& s, const std::string& d) const { s.printScheduleToDestination(d); }
void AdminUser::printScheduleAfterTime(const Station& s, const std::string& d, const std::string& t) const { s.printScheduleAfterTime(d, t); }
void AdminUser::printTrainInfo(const Train& t) const { t.printInfo(); }
void AdminUser::printWagonInfo(const Train& t, int id) const {
    auto w = t.getWagonByID(id);
    if (w) w->printInfo(); else std::cout << "Wagon not found.\n";
}
void AdminUser::buyTicket(Train& t, int wid, int sid, const std::string& f, const std::vector<std::string>& e) const {
    ::buyTicket(t, wid, sid, f, e);
}
void AdminUser::buyTicketWithDiscount(Train& t, int wid, int sid, const std::string& f, const std::string& cf, const std::vector<std::string>& e) const {
    ::buyTicketWithDiscount(t, wid, sid, f, cf, e);
}

void AdminUser::addStation(std::vector<Station>& stations, const std::string& name) const {
    stations.emplace_back(name, 5); 
    std::cout << "Added station: " << name << "\n";
}

void AdminUser::addTrain(Station& from, Station& to, int distance, int speed, const std::string& departureTime, int trainID) const {
    std::shared_ptr<Train> train = std::make_shared<Train>(trainID, from.getName(), to.getName(), departureTime, distance, speed);
    train->setDeparturePlatform(from.getAvailablePlatform());
    train->setArrivalPlatform(to.getAvailablePlatform());
    from.addTrain(train);
    std::cout << "Train " << trainID << " added from " << from.getName() << " to " << to.getName() << "\n";
}

void AdminUser::removeTrain(Station& station, int trainID) const {
    station.removeTrain(trainID);
    std::cout << "Train " << trainID << " removed from station " << station.getName() << "\n";
}

void AdminUser::addWagon(Train& train, std::shared_ptr<Wagon> wagon) const {
    train.addWagon(wagon);
    std::cout << "Wagon " << wagon->getId() << " added to Train " << train.getID() << "\n";
}

void AdminUser::removeWagon(Train& train, int wagonID) const {
    train.removeWagon(wagonID);
    std::cout << "Wagon " << wagonID << " removed from Train " << train.getID() << "\n";
}

void AdminUser::moveWagon(Train& source, Train& dest, int wagonID) const {
    auto wagon = source.getWagonByID(wagonID);
    if (!wagon) {
        std::cout << "Wagon not found in source train.\n";
        return;
    }
    source.removeWagon(wagonID);
    dest.addWagon(wagon);
    std::cout << "Moved wagon " << wagonID << " from train " << source.getID() << " to train " << dest.getID() << "\n";
}

void AdminUser::createDiscountCard(std::shared_ptr<DiscountCard> card, const std::string& fileName) const {
    std::ofstream out(fileName);
    if (!out) {
        std::cerr << "Failed to create discount card file.\n";
        return;
    }

    if (dynamic_cast<AgeCard*>(card.get())) {
        auto* ageCard = static_cast<AgeCard*>(card.get());
        out << "|===Age card===|\n";
        out << "|" << card->getOwner() << "|\n";
        out << "|" << ageCard->getAge() << " years old|\n";
    } else if (dynamic_cast<RouteCard*>(card.get())) {
        auto* route = static_cast<RouteCard*>(card.get());
        out << "|===Route card===|\n";
        out << "|" << card->getOwner() << "|\n";
        out << "|" << route->getDestination() << "|\n";
    } else if (dynamic_cast<DistanceCard*>(card.get())) {
        auto* dist = static_cast<DistanceCard*>(card.get());
        out << "|===Distance card===|\n";
        out << "|" << card->getOwner() << "|\n";
        out << "|" << dist->getMaxDistance() << " km|\n";
    }

    out << "|" << card->getCardID() << "|\n";
    out << "|===============|\n";

    std::cout << "Discount card saved to: " << fileName << "\n";
}

void AdminUser::validateDiscountCard(const std::string& cardID, DiscountCardRegistry& registry) const {
    registry.addValidCard(cardID);
    std::cout << "Card " << cardID << " validated.\n";
}

