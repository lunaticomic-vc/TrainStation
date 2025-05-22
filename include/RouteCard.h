#pragma once
#include "DiscountCard.h"

class RouteCard : public DiscountCard {
    std::string validDestination;
public:
    RouteCard(const std::string& owner, const std::string& cardID, const std::string& dest);
    double getDiscount(const Train& train) const override;
    std::string getDestination() const;

};
