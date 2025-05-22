#include "Train.h"
#include <iostream>

Train::Train(int trainID, const std::string& start, const std::string& end,
             const std::string& departureTime, int distance, int speed)
    : trainID(trainID), startStation(start), endStation(end),
      departureDateTime(departureTime), distance(distance), speed(speed),
      departurePlatform(0), arrivalPlatform(0) {}

int Train::getID() const {
    return trainID;
}

std::string Train::getDestination() const {
    return endStation;
}

std::string Train::getDepartureTime() const {
    return departureDateTime;
}

std::string Train::getArrivalTime() const {
    return arrivalDateTime;
}

int Train::getDistance() const {
    return distance;
}

int Train::getDeparturePlatform() const {
    return departurePlatform;
}

int Train::getArrivalPlatform() const {
    return arrivalPlatform;
}

void Train::setArrivalTime(const std::string& arrivalTime) {
    arrivalDateTime = arrivalTime;
}

void Train::setDeparturePlatform(int platform) {
    departurePlatform = platform;
}

void Train::setArrivalPlatform(int platform) {
    arrivalPlatform = platform;
}

void Train::addWagon(std::shared_ptr<Wagon> wagon) {
    wagons.push_back(wagon);
}

void Train::removeWagon(int wagonID) {
    wagons.erase(
        std::remove_if(wagons.begin(), wagons.end(),
            [wagonID](const std::shared_ptr<Wagon>& w) { return w->getId() == wagonID; }),
        wagons.end()
    );
}

std::shared_ptr<Wagon> Train::getWagonByID(int wagonID) const {
    for (const auto& w : wagons) {
        if (w->getId() == wagonID)
            return w;
    }
    return nullptr;
}

void Train::printInfo() const {
    std::cout << "=== Train ID: " << trainID << " ===\n";
    std::cout << "From: " << startStation << " → To: " << endStation << "\n";
    std::cout << "Distance: " << distance << " km | Speed: " << speed << " km/h\n";
    std::cout << "Departure: " << departureDateTime
              << " | Platform: " << departurePlatform << "\n";
    std::cout << "Arrival:   " << arrivalDateTime
              << " | Platform: " << arrivalPlatform << "\n\n";

    printWagons();
}

void Train::printWagons() const {
    std::cout << "Wagons:\n";
    for (const auto& wagon : wagons) {
        std::cout << "- ID " << wagon->getId() << ": " << wagon->getType() << "\n";
    }
}

const std::vector<std::shared_ptr<Wagon>>& Train::getWagons() const {
    return wagons;
}
