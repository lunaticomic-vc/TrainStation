#pragma once
#include <string>
#include <unordered_set>

class DiscountCardRegistry {
private:
    std::unordered_set<std::string> validCardIDs;

public:
    DiscountCardRegistry() = default;

    void addValidCard(const std::string& cardID);
    bool isCardValid(const std::string& cardID) const;

    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};
