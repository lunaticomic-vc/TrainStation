#pragma once
#include "DiscountCard.h"
#include <string>

class AgeCard : public DiscountCard {
    int age;
public:
    AgeCard(const std::string& owner, const std::string& cardID, int age);
    double getDiscount(const Train& train) const override;
    int getAge() const;

};
