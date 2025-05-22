#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Wagon.h"

class Train {
private:
    std::string startStation;
    std::string endStation;
    std::string departureDateTime;
    std::string arrivalDateTime;
    int departurePlatform;
    int arrivalPlatform;
    int distance;
    int speed;
    int trainID;

    std::vector<std::shared_ptr<Wagon>> wagons;

public:
    Train(int trainID, const std::string& start, const std::string& end,
          const std::string& departureTime, int distance, int speed);

    int getID() const;
    std::string getDestination() const;
    std::string getDepartureTime() const;
    std::string getArrivalTime() const;
    int getDistance() const;
    int getDeparturePlatform() const;
    int getArrivalPlatform() const;

    void setArrivalTime(const std::string& arrivalTime);
    void setDeparturePlatform(int platform);
    void setArrivalPlatform(int platform);

    void addWagon(std::shared_ptr<Wagon> wagon);
    void removeWagon(int wagonID);
    std::shared_ptr<Wagon> getWagonByID(int wagonID) const;

    void printInfo() const;
    void printWagons() const;
    const std::vector<std::shared_ptr<Wagon>>& getWagons() const;

};
