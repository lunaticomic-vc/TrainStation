#pragma once
#include "DiscountCard.h"

class DistanceCard : public DiscountCard {
    int maxDistance;
public:
    DistanceCard(const std::string& owner, const std::string& cardID, int maxDistance);
    double getDiscount(const Train& train) const override;
    int getMaxDistance() const;

};
