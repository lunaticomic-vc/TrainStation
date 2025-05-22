#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "User.h"
#include "UnsignedUser.h"
#include "AdminUser.h"
#include "DiscountCardRegistry.h"

class Session {
private:
    std::unique_ptr<User> currentUser;
    std::unordered_map<std::string, std::string> adminCredentials; // username → password
    DiscountCardRegistry& cardRegistry;

public:
    Session(DiscountCardRegistry& registry);

    User& getCurrentUser() const;
    bool login(const std::string& username, const std::string& password);
    void logout();

    bool loadAdminAccounts(const std::string& filename);
};
