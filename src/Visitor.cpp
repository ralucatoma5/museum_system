#include "../include/Visitor.h"

Visitor::Visitor(const std::string& username, const std::string& password, int loyaltyPoints, bool isFirstTimeVisitor, const std::string& ticketType)
    : User(username, password), loyaltyPoints(loyaltyPoints), isFirstTimeVisitor(isFirstTimeVisitor), ticketType(ticketType) {}

void Visitor::addLoyaltyPoints(int points) {
    loyaltyPoints += points;
}

void Visitor::removeLoyaltyPoints(int points) {
    loyaltyPoints -= points;
}

void Visitor::changeIsFirstTimeVisitor() {
    if (isFirstTimeVisitor)
        isFirstTimeVisitor = false;
}

int Visitor::getLoyaltyPoints() {
    return loyaltyPoints;
}

const std::string& Visitor::getUsername() {
    return username;
}

const std::string& Visitor::getTicketType() {
    return ticketType;
}

const std::string& Visitor::getPassword() {
    return password;
}

bool Visitor::getIsFirstTimeVisitor() const {
    return isFirstTimeVisitor;
}
