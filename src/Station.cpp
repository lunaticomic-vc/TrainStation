#include "Station.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Station::Station(const std::string& name, int numPlatforms)
    : name(name), numPlatforms(numPlatforms) {}

std::string Station::getName() const {
    return name;
}

int Station::getAvailablePlatform() const {
    // За сега – просто връщаме произволен свободен (примерно първия)
    // Може да направим по-сериозна проверка по време
    return 1 + (departingTrains.size() % numPlatforms);
}

void Station::addTrain(std::shared_ptr<Train> train) {
    departingTrains.push_back(train);
}

void Station::removeTrain(int trainID) {
    departingTrains.erase(
        std::remove_if(departingTrains.begin(), departingTrains.end(),
            [trainID](std::shared_ptr<Train> t) { return t->getID() == trainID; }),
        departingTrains.end()
    );
}

std::shared_ptr<Train> Station::getTrainByID(int trainID) const {
    for (const auto& train : departingTrains) {
        if (train->getID() == trainID)
            return train;
    }
    return nullptr;
}

const std::vector<std::shared_ptr<Train>>& Station::getDepartingTrains() const {
    return departingTrains;
}
void Station::printSchedule() const {
    std::cout << "=== Schedule for station " << name << " ===\n";

    std::cout << "\nDepartures:\n";
    std::cout << "----------------------------------------------------------\n";
    std::cout << "| Departure | Arrival   | Destination     | Platform | ID |\n";
    std::cout << "----------------------------------------------------------\n";
    for (const auto& train : departingTrains) {
        std::cout << "| " << train->getDepartureTime()
                  << " | " << train->getArrivalTime()
                  << " | " << std::setw(15) << train->getDestination()
                  << " | " << std::setw(8) << train->getDeparturePlatform()
                  << " | " << train->getID() << " |\n";
    }
}

void Station::printScheduleToDestination(const std::string& destination) const {
    std::cout << "\nTrains from " << name << " to " << destination << ":\n";

    for (const auto& train : departingTrains) {
        if (train->getDestination() == destination) {
            std::cout << "- Train ID: " << train->getID()
                      << " | Departure: " << train->getDepartureTime()
                      << " | Arrival: " << train->getArrivalTime()
                      << "\n";
        }
    }
}

void Station::printScheduleAfterTime(const std::string& date, const std::string& time) const {
    std::string target = date + " " + time;

    std::cout << "\nTrains from " << name << " after " << target << ":\n";

    for (const auto& train : departingTrains) {
        if (train->getDepartureTime() > target) {
            std::cout << "- Train ID: " << train->getID()
                      << " | To: " << train->getDestination()
                      << " | Departs: " << train->getDepartureTime()
                      << "\n";
        }
    }
}


