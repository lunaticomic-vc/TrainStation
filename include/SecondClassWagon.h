#pragma once
#include "Wagon.h"

class SecondClassWagon : public Wagon {
    double luggagePricePerKg;

public:
    SecondClassWagon(int id, double basePrice, double luggagePricePerKg);

    std::string getType() const override;
    double calculatePrice(int seatIndex, const std::vector<std::string>& extraParams) const override;
    void printInfo() const override;
};
