#pragma once
#include <string>
#include "Train.h"

class DiscountCard {
protected:
    std::string owner;
    std::string cardID;

public:
    DiscountCard(const std::string& owner, const std::string& cardID);
    virtual ~DiscountCard() = default;

    std::string getOwner() const;
    std::string getCardID() const;

    virtual double getDiscount(const Train& train) const = 0;
};
