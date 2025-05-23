#include "../include/StandardVisitor.h"
#include "../include/Utils.h"
#include <iostream>


StandardVisitor::StandardVisitor(const std::string& username, const std::string& password, int loyaltyPoints, bool isFirstTimeVisitor, const std::string& ticketType)
    : Visitor(username, password, loyaltyPoints, isFirstTimeVisitor, ticketType) {}

StandardVisitor::StandardVisitor() : Visitor("unknown", "unknown", 0, false, "unknown") {}

void StandardVisitor::print(std::ostream& os) const {
    os << "\n==== Account Info ====" << "\n";
    os << "Username: " << username << "\n";
    os << "Ticket Type: " << ticketType << "\n";
    os << "Loyalty Points: " << loyaltyPoints << "\n";
}

void StandardVisitor::read(std::istream& is) {
    readUserCredentials(is, username, password);
    bool firstAttempt = true;

    while (true) {
        if (!firstAttempt) {
            std::cerr << "Error: Invalid ticket type entered. Please try again.\n";
        }

        if (firstAttempt) {
            std::cout << "Enter your ticketType (Adult/Student/Senior): ";
        }
        try {
            ticketType = readTicketType();
            break;
        } catch (const std::exception&) {
            firstAttempt = false;
        }
    }


    loyaltyPoints = 0;
    isFirstTimeVisitor = true;
}

double StandardVisitor::getDiscount(bool groupDiscount) const {
    double discount = 0.0;
    if (ticketType == "Student") discount += 0.10;
    if (ticketType == "Senior") discount += 0.10;
    if (isFirstTimeVisitor) discount += 0.10;
    if (groupDiscount) discount += 0.05;
    return discount;
}
