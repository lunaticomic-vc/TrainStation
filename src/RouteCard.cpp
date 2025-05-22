#include "RouteCard.h"

RouteCard::RouteCard(const std::string& owner, const std::string& cardID, const std::string& dest)
    : DiscountCard(owner, cardID), validDestination(dest) {}

double RouteCard::getDiscount(const Train& train) const {
    return (train.getDestination() == validDestination) ? 1.0 : 0.0;
}
std::string RouteCard::getDestination() const {
    return validDestination;
}
