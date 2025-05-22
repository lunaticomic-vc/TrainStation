#include "SleeperWagon.h"
#include <iostream>
#include <sstream>

SleeperWagon::SleeperWagon(int id, double basePrice, double pricePer100Km)
    : Wagon(id, basePrice, 5), pricePer100Km(pricePer100Km) {}

std::string SleeperWagon::getType() const {
    return "Sleeper";
}

double SleeperWagon::calculatePrice(int seatIndex, const std::vector<std::string>& extraParams) const {
    double distance = 0.0;

    if (!extraParams.empty()) {
        std::stringstream ss(extraParams[0]);
        ss >> distance;
    }

    return basePrice + (pricePer100Km / 100.0) * distance;
}

void SleeperWagon::printInfo() const {
    std::cout << "=== Wagon ID: " << id << " ===\n";
    std::cout << "Wagon Type: Sleeper\n";
    std::cout << "Base Price: " << basePrice << " lv.\n";
    std::cout << "Price per 100 km: " << pricePer100Km << " lv.\n";
    std::cout << "Beds: 5\n";
    std::cout << "Available Beds:\n";

    for (size_t i = 0; i < seats.size(); ++i) {
        if (seats[i]) std::cout << "XX\n";
        else std::cout << "0" << i + 1 << "\n";
    }
}
