#include "../include/VipVisitor.h"
#include <iostream>

VipVisitor::VipVisitor(const std::string& username, const std::string& password, int loyaltyPoints, bool isFirstTimeVisitor, const std::string& ticketType, const std::string& vipLevel)
    : Visitor(username, password, loyaltyPoints, isFirstTimeVisitor, ticketType), vipLevel(vipLevel) {}

VipVisitor::VipVisitor() : Visitor("unknown", "unknown", 0, false, "unknown"), vipLevel("unknown") {}

void VipVisitor::print(std::ostream& os) const {
    os << "\n==== Account Info ====" << "\n";
    os << "Username: " << username << "\n";
    os << "Ticket Type: " << ticketType << "\n";
    os << "VIP Level: " << vipLevel << "\n";
    os << "Loyalty Points: " << loyaltyPoints << "\n \n";
}

void VipVisitor::read(std::istream& is) {
    readUserCredentials(is, username, password);
    vipLevel = "Silver";
    loyaltyPoints = 0;
    isFirstTimeVisitor = true;
}

double VipVisitor::getDiscount(bool groupDiscount) const {
    double discount = 0.0;
    if (vipLevel == "Diamond") discount += 0.25;
    else if (vipLevel == "Gold") discount += 0.20;
    else discount += 0.15;
    if (groupDiscount) discount += 0.05;
    return discount;
}

void VipVisitor::upgradeToDiamond() {
    vipLevel = "Diamond";
    std::cout << "You have been upgraded to VIP Diamond \n";
}

void VipVisitor::upgradeToGold() {
    vipLevel = "Gold";
    std::cout << "You have been upgraded to VIP Gold!\n";
}

void VipVisitor::downgradeToGold() {
    vipLevel = "Gold";
    std::cout << "You have been downgraded to VIP Gold!\n";
}

void VipVisitor::downgradeToSilver() {
    vipLevel = "Silver";
    std::cout << "You have been downgraded to Silver!\n";
}

const std::string& VipVisitor::getVipLevel() {
    return vipLevel;
}
