#include "SecondClassWagon.h"
#include <iostream>
#include <sstream>

SecondClassWagon::SecondClassWagon(int id, double basePrice, double luggagePricePerKg)
    : Wagon(id, basePrice, 20), luggagePricePerKg(luggagePricePerKg) {}

std::string SecondClassWagon::getType() const {
    return "Second Class";
}

double SecondClassWagon::calculatePrice(int seatIndex, const std::vector<std::string>& extraParams) const {
    double luggageWeight = 0.0;

    if (!extraParams.empty()) {
        std::stringstream ss(extraParams[0]);
        ss >> luggageWeight;
    }

    return basePrice + (luggagePricePerKg * luggageWeight);
}

void SecondClassWagon::printInfo() const {
    std::cout << "=== Wagon ID: " << id << " ===\n";
    std::cout << "Wagon Type: Second Class\n";
    std::cout << "Base Price: " << basePrice << " lv.\n";
    std::cout << "Price for 1 kg luggage: " << luggagePricePerKg << " lv.\n";
    std::cout << "Seats: 20\n";
    std::cout << "Available Seats:\n";

    for (size_t i = 0; i < seats.size(); ++i) {
        if (seats[i]) std::cout << "XX ";
        else std::cout << (i + 1 < 10 ? "0" : "") << i + 1 << " ";

        if ((i + 1) % 4 == 0) std::cout << "\n";
    }
}
