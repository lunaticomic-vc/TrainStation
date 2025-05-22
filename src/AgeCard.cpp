#include "AgeCard.h"

AgeCard::AgeCard(const std::string& owner, const std::string& cardID, int age)
    : DiscountCard(owner, cardID), age(age) {}

double AgeCard::getDiscount(const Train&) const {
    if (age <= 10) return 1.0;
    else if (age <= 18) return 0.5;
    else return 0.2;
}
int AgeCard::getAge() const {
    return age;
}
