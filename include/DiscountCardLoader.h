#pragma once
#include <memory>
#include <string>
#include "DiscountCard.h"

std::shared_ptr<DiscountCard> loadCardFromFile(const std::string& fileName);
