#include "Wagon.h"
#include <iostream>
#include <iomanip>

Wagon::Wagon(int id, double basePrice, int seatCount)
    : id(id), basePrice(basePrice), seats(seatCount, false) {}

int Wagon::getId() const {
    return id;
}

bool Wagon::isSeatAvailable(int seatIndex) const {
    return seatIndex >= 0 && seatIndex < seats.size() && !seats[seatIndex];
}

void Wagon::occupySeat(int seatIndex) {
    if (isSeatAvailable(seatIndex)) {
        seats[seatIndex] = true;
    }
}

void Wagon::printSeats() const {
    for (size_t i = 0; i < seats.size(); ++i) {
        if (seats[i])
            std::cout << "XX ";
        else
            std::cout << std::setw(2) << std::setfill('0') << i + 1 << " ";
        if ((i + 1) % 2 == 0)
            std::cout << "\n";
    }
}

int Wagon::getSeatCount() const {
    return seats.size();
}
