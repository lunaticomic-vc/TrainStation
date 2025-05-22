#include "DiscountCard.h"

DiscountCard::DiscountCard(const std::string& owner, const std::string& cardID)
    : owner(owner), cardID(cardID) {}

std::string DiscountCard::getOwner() const { return owner; }
std::string DiscountCard::getCardID() const { return cardID; }
