#include "DiscountCardRegistry.h"
#include <fstream>
#include <iostream>

void DiscountCardRegistry::addValidCard(const std::string& cardID) {
    validCardIDs.insert(cardID);
}

bool DiscountCardRegistry::isCardValid(const std::string& cardID) const {
    return validCardIDs.find(cardID) != validCardIDs.end();
}

bool DiscountCardRegistry::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Failed to save registry to file.\n";
        return false;
    }

    for (const auto& id : validCardIDs) {
        out << id << "\n";
    }

    return true;
}

bool DiscountCardRegistry::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Failed to load registry from file.\n";
        return false;
    }

    std::string id;
    while (std::getline(in, id)) {
        if (!id.empty()) {
            validCardIDs.insert(id);
        }
    }

    return true;
}
