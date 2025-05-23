#include "../include/User.h"
#include <iostream>

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

bool User::login(const std::string& user, const std::string& pass) const {
    return username == user && password == pass;
}

void User::readUserCredentials(std::istream& is, std::string& user, std::string& pass) const {
    std::cout << "Enter username: ";
    is >> user;
    std::cout << "Enter password: ";
    is >> pass;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    user.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, User& user) {
    user.read(is);
    return is;
}
