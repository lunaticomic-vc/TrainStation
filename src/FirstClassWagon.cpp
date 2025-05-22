#include "FirstClassWagon.h"
#include <iostream>

FirstClassWagon::FirstClassWagon(int id, double basePrice, double comfortFactor)
    : Wagon(id, basePrice, 10), comfortFactor(comfortFactor) {}

std::string FirstClassWagon::getType() const {
    return "First Class";
}

double FirstClassWagon::calculatePrice(int seatIndex, const std::vector<std::string>& extraParams) const {
    bool foodIncluded = extraParams.size() > 0 && extraParams[0] == "true";
    double price = basePrice * comfortFactor;
    if (foodIncluded) price += 10.0;
    return price;
}

void FirstClassWagon::printInfo() const {
    std::cout << "=== Wagon ID: " << id << " ===\n";
    std::cout << "Wagon Type: First Class\n";
    std::cout << "Base Price: " << basePrice << " lv.\n";
    std::cout << "Comfort factor: " << comfortFactor << "\n";
    std::cout << "Seats: 10\n";
    std::cout << "Available Seats:\n";
    printSeats();
}
