#include "DistanceCard.h"

DistanceCard::DistanceCard(const std::string& owner, const std::string& cardID, int maxDistance)
    : DiscountCard(owner, cardID), maxDistance(maxDistance) {}

double DistanceCard::getDiscount(const Train& train) const {
    return (train.getDistance() <= maxDistance) ? 0.5 : 0.3;
}
int DistanceCard::getMaxDistance() const {
    return maxDistance;
}
