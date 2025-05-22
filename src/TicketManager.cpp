#include "TicketManager.h"
#include "DiscountCardLoader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <unordered_set>

std::unordered_set<std::string> validCardIDs = { "827345", "532421", "111495" };

bool isCardValid(const std::string& cardID) {
    return validCardIDs.find(cardID) != validCardIDs.end();
}

void buyTicket(Train& train, int wagonID, int seatID, const std::string& fileName,
               const std::vector<std::string>& extraParams) {
    auto wagon = train.getWagonByID(wagonID);
    if (!wagon) {
        std::cerr << "Error: Wagon not found!\n";
        return;
    }

    int maxSeats = wagon->getSeatCount();
    if (seatID < 1 || seatID > maxSeats) {
        std::cerr << "Error: Invalid seat ID!\n";
        return;
    }

    if (!wagon->isSeatAvailable(seatID - 1)) {
        std::cerr << "Error: Seat already taken!\n";
        return;
    }

    double price = wagon->calculatePrice(seatID - 1, extraParams);
    wagon->occupySeat(seatID - 1);

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    char dateTimeBuf[64];
    std::strftime(dateTimeBuf, sizeof(dateTimeBuf), "%d/%m/%Y %H:%M", now);

    std::ofstream out(fileName);
    out << "|============Train Ticket============|\n";
    out << "| Ticket: " << train.getID() << " " << wagon->getType() << "\n";
    out << "| Train ID: " << train.getID() << "\n";
    out << "| Wagon ID: " << wagonID << "\n";
    out << "| Seat ID: " << seatID << "\n";
    out << "| Departure time: " << train.getDepartureTime() << "\n";
    out << "| Arrival time: " << train.getArrivalTime() << "\n";
    out << "| Departure platform: " << train.getDeparturePlatform() << "\n";
    out << "| Discount: 0 lv.\n";
    out << "| Price: " << price << " lv.\n";
    out << "| Purchase Time: " << dateTimeBuf << "\n";
    out << "|====================================|\n";

    std::cout << "Ticket successfully bought for Train ID: " << train.getID() << "\n";
    std::cout << "Ticket price: " << price << " lv.\n";
    std::cout << "Ticket saved to file: " << fileName << "\n";
}

void buyTicketWithDiscount(Train& train, int wagonID, int seatID, const std::string& fileName,
                           const std::string& cardFile, const std::vector<std::string>& extraParams) {
    auto wagon = train.getWagonByID(wagonID);
    if (!wagon) {
        std::cerr << "Error: Wagon not found!\n";
        return;
    }

    int maxSeats = wagon->getSeatCount();
    if (seatID < 1 || seatID > maxSeats) {
        std::cerr << "Error: Invalid seat ID!\n";
        return;
    }

    if (!wagon->isSeatAvailable(seatID - 1)) {
        std::cerr << "Error: Seat already taken!\n";
        return;
    }

    std::ifstream in(cardFile);
    if (!in) {
        std::cerr << "Error: Cannot open card file!\n";
        return;
    }

    std::string line, cardType, name, thirdLine, cardID;
    std::getline(in, cardType);
    std::getline(in, name);
    std::getline(in, thirdLine);
    std::getline(in, cardID);
    cardID.erase(remove(cardID.begin(), cardID.end(), '|'), cardID.end()); // махни рамки
    cardID = cardID.substr(0, 6);

    if (!isCardValid(cardID)) {
        std::cerr << "Error: Discount card is not valid!\n";
        return;
    }

    double price = wagon->calculatePrice(seatID - 1, extraParams);
    double discount = 0.0;

    if (cardType.find("Age card") != std::string::npos) {
        int age = std::stoi(thirdLine.substr(0, thirdLine.find(" ")));
        if (age <= 10) discount = 1.0;
        else if (age <= 18) discount = 0.5;
        else discount = 0.2;
    } else if (cardType.find("Route card") != std::string::npos) {
        std::string destination = thirdLine;
        if (destination.find(train.getDestination()) != std::string::npos) {
            discount = 1.0;
        }
    } else if (cardType.find("Distance card") != std::string::npos) {
        int maxDistance = std::stoi(thirdLine.substr(0, thirdLine.find(" ")));
        if (train.getDistance() <= maxDistance)
            discount = 0.5;
        else
            discount = 0.3;
    }

    double finalPrice = price * (1.0 - discount);
    wagon->occupySeat(seatID - 1);

    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    char dateTimeBuf[64];
    std::strftime(dateTimeBuf, sizeof(dateTimeBuf), "%d/%m/%Y %H:%M", now);

    std::ofstream out(fileName);
    out << "|============Train Ticket============|\n";
    out << "| Ticket: " << train.getID() << " " << wagon->getType() << "\n";
    out << "| Train ID: " << train.getID() << "\n";
    out << "| Wagon ID: " << wagonID << "\n";
    out << "| Seat ID: " << seatID << "\n";
    out << "| Departure time: TBD\n";
    out << "| Arrival time: TBD\n";
    out << "| Departure platform: TBD\n";
    out << "| Discount: " << (price - finalPrice) << " lv.\n";
    out << "| Price: " << finalPrice << " lv.\n";
    out << "| Purchase Time: " << dateTimeBuf << "\n";
    out << "|====================================|\n";

    std::cout << "Ticket successfully bought with discount for Train ID: " << train.getID() << "\n";
    std::cout << "Ticket price: " << finalPrice << " lv.\n";
    std::cout << "Ticket saved to file: " << fileName << "\n";
}
