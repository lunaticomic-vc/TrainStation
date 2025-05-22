#pragma once
#include "Wagon.h"

class SleeperWagon : public Wagon {
    double pricePer100Km;

public:
    SleeperWagon(int id, double basePrice, double pricePer100Km);

    std::string getType() const override;
    double calculatePrice(int seatIndex, const std::vector<std::string>& extraParams) const override;
    void printInfo() const override;
};
