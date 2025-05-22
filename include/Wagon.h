#pragma once
#include <string>
#include <vector>

class Wagon {
protected:
    int id;
    double basePrice;
    std::vector<bool> seats; 

public:
    Wagon(int id, double basePrice, int seatCount);
    virtual ~Wagon() = default;

    int getId() const;
    virtual std::string getType() const = 0;
    virtual double calculatePrice(int seatIndex, const std::vector<std::string>& extraParams) const = 0;

    bool isSeatAvailable(int seatIndex) const;
    void occupySeat(int seatIndex);
    void printSeats() const;
    virtual void printInfo() const = 0;

    int getSeatCount() const;

};
