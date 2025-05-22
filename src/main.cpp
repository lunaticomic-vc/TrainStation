#include "../include/Session.h"
#include "../include/CommandParser.h"
#include "../include/DiscountCardRegistry.h"

#include <iostream>
#include <string>

int main() {

    DiscountCardRegistry registry;
    registry.loadFromFile("valid_cards.txt");

    Session session(registry);
    session.loadAdminAccounts("admins.txt");

    CommandParser parser(session, registry);

    std::cout << "Welcome to the Train Station System!\n";
    std::cout << "Type 'exit' to quit.\n";

    std::string input;
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, input);
        if (input == "exit") break;
        parser.parseAndExecute(input);
    }

    registry.saveToFile("valid_cards.txt");
    std::cout << "Goodbye!\n";
    return 0;
}
