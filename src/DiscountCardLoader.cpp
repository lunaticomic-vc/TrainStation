#include "DiscountCardLoader.h"
#include "AgeCard.h"
#include "RouteCard.h"
#include "DistanceCard.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>

using std::getline;

extern bool isCardValid(const std::string& cardID); // ако е външна функция

std::shared_ptr<DiscountCard> loadCardFromFile(const std::string& fileName) {
    std::ifstream in(fileName);
    if (!in) return nullptr;

    std::string type, name, thirdLine, cardID;
    std::getline(in, type);
    std::getline(in, name);
    std::getline(in, thirdLine);
    std::getline(in, cardID);

    cardID.erase(remove(cardID.begin(), cardID.end(), '|'), cardID.end());
    cardID = cardID.substr(0, 6);

    if (!isCardValid(cardID)) return nullptr;

    if (type.find("Age card") != std::string::npos) {
        std::stringstream ss(thirdLine);
        int age;
        ss >> age;
        return std::make_shared<AgeCard>(name, cardID, age);
    }
    else if (type.find("Route card") != std::string::npos) {
        return std::make_shared<RouteCard>(name, cardID, thirdLine);
    }
    else if (type.find("Distance card") != std::string::npos) {
        std::stringstream ss(thirdLine);
        int dist;
        ss >> dist;
        return std::make_shared<DistanceCard>(name, cardID, dist);
    }

    return nullptr;
}
