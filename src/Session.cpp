#include "Session.h"
#include <fstream>
#include <iostream>
#include <sstream>

Session::Session(DiscountCardRegistry& registry)
    : currentUser(std::make_unique<UnsignedUser>()), cardRegistry(registry) {}

User& Session::getCurrentUser() const {
    return *currentUser;
}

bool Session::login(const std::string& username, const std::string& password) {
    auto it = adminCredentials.find(username);
    if (it == adminCredentials.end() || it->second != password) {
        std::cout << "Error: Incorrect credentials!\n";
        return false;
    }

    currentUser = std::make_unique<AdminUser>(username);
    std::cout << "Welcome back, " << username << "!\n";
    return true;
}

void Session::logout() {
    currentUser = std::make_unique<UnsignedUser>();
    std::cout << "Logged out.\n";
}

bool Session::loadAdminAccounts(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Failed to load admin accounts.\n";
        return false;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string username, password;
        if (iss >> username >> password) {
            adminCredentials[username] = password;
        }
    }

    return true;
}
