#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Train.h"

class Station {
private:
    std::string name;
    int numPlatforms;
    std::vector<std::shared_ptr<Train>> departingTrains;

public:
    Station(const std::string& name, int numPlatforms);

    std::string getName() const;
    int getAvailablePlatform() const;

    void addTrain(std::shared_ptr<Train> train);
    void removeTrain(int trainID);

    std::shared_ptr<Train> getTrainByID(int trainID) const;
    const std::vector<std::shared_ptr<Train>>& getDepartingTrains() const;

    // Печат на разписания
    void printSchedule() const;
    void printScheduleToDestination(const std::string& destination) const;
    void printScheduleAfterTime(const std::string& date, const std::string& time) const;
};
