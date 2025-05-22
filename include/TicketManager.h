#pragma once
#include "Train.h"
#include "DiscountCard.h"
#include "DiscountCardRegistry.h"

void buyTicket(Train& train, int wagonID, int seatID, const std::string& fileName,const std::vector<std::string>& extraParams);

void buyTicketWithDiscount(Train& train, int wagonID, int seatID, const std::string& ticketFile,const std::string& cardFile, const std::vector<std::string>& extraParams);

bool isCardValid(const std::string& cardID, const DiscountCardRegistry& registry);

