#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <memory>
#include "../include/Exhibition.h"
#include "../include/ArtExhibition.h"
#include "../include/HistoryExhibition.h"
#include "../include/ScienceExhibition.h"
#include "../include/VipExhibitionEvent.h"
#include "../include/ExhibitionFactory.h"
#include "../include/User.h"
#include "../include/StandardVisitor.h"
#include "../include/VipVisitor.h"
#include "../include/Ticket.h"
#include "../include/Quiz.h"
#include "../include/Employees.h"
#include "../include/Manager.h"
#include "../include/TourGuide.h"
#include "../include/Cashier.h"
#include "../include/Menu.h"
#include "../include/Utils.h"


std::string Utils::capitalizeWord(const std::string& word) {

    std::string result = word;
    result[0] = std::toupper(result[0]);

    for (auto i = 1u; i < result.size(); i++) {
        result[i] = std::tolower(result[i]);
    }

    return result;
}

void Utils::printByType(const std::string& type, const std::vector<std::shared_ptr<Employees>>& employees) {
    if (!employees.empty()) {
        std::cout << "\n\n" << type << ":\n";
        for (auto i = 0u; i < employees.size(); i++) {
            std::cout << i + 1 << ". " << *employees[i] << "\n";
        }
    }
}

void Utils::scheduleEachEmployee(const std::vector<std::shared_ptr<Employees>>& employees, std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule, const std::string& day) {
    int empIndex;
    std::cout << "Enter employee index to assign: ";
    std::cin >> empIndex;
    empIndex--;
    if (empIndex >= 0 && static_cast<size_t>(empIndex) < employees.size()) {
        schedule[day].push_back(employees[empIndex]);
    } else {
        std::cout << "Invalid index.\n";
    }
}

void Utils::scheduleAllEmployees(const std::vector<std::shared_ptr<Employees>>& employees, std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule, const std::string& day) {
    std::vector<std::shared_ptr<Employees>> managers;
    std::vector<std::shared_ptr<Employees>> tourGuides;
    std::vector<std::shared_ptr<Employees>> cashiers;

    for (const auto& emp : employees) {
        if (std::dynamic_pointer_cast<Manager>(emp)) {
            managers.push_back(emp);
        }
        else if (std::dynamic_pointer_cast<TourGuide>(emp)) {
            tourGuides.push_back(emp);
        }
        else if (std::dynamic_pointer_cast<Cashier>(emp)) {
            cashiers.push_back(emp);
        }
    }

    Utils::printByType("Manager", managers);
    Utils::scheduleEachEmployee(managers, schedule, day);
    Utils::printByType("Tour Guide", tourGuides);
    Utils::scheduleEachEmployee(tourGuides, schedule, day);
    Utils::printByType("Cashier", cashiers);
    Utils::scheduleEachEmployee(cashiers, schedule, day);
    std::cout << "Scheduled " << day << "\n";
}


std::shared_ptr<Visitor> Utils::upgradeVisitor(std::vector<std::shared_ptr<Visitor>>& visitors, std::shared_ptr<Visitor> visitor) {
    auto vipVisitor = std::dynamic_pointer_cast<VipVisitor>(visitor);
    if (vipVisitor) {
        if (vipVisitor->getLoyaltyPoints() >= 200  && vipVisitor->getLoyaltyPoints() < 300 && vipVisitor->getVipLevel() == "Silver") {
            vipVisitor->upgradeToGold();
        } else if (vipVisitor->getLoyaltyPoints() >= 300 && vipVisitor->getVipLevel() != "Diamond") {
            vipVisitor->upgradeToDiamond();
        }
        return visitor;
    }
    auto stdVisitor = std::dynamic_pointer_cast<StandardVisitor>(visitor);
    if (stdVisitor) {
        if (stdVisitor->getLoyaltyPoints() >= 100) {
            auto newVip = std::make_shared<VipVisitor>(
                stdVisitor->getUsername(),
                stdVisitor->getPassword(),
                stdVisitor->getLoyaltyPoints(),
                false,
                stdVisitor->getTicketType(),
                stdVisitor->getLoyaltyPoints() >= 300? "Diamond" : stdVisitor->getLoyaltyPoints() >= 200? "Gold" : "Silver"
            );
            if (stdVisitor->getLoyaltyPoints() >= 300)
                std::cout << "You have been upgraded to VIP Diamond! \n" << std::endl;
            else if (stdVisitor->getLoyaltyPoints() >= 200)
                std::cout << "You have been upgraded to VIP Gold! \n" << std::endl;
            else std::cout << "You have been upgraded to VIP Silver! \n" << std::endl;

            for (auto& v : visitors) {
                if (v == stdVisitor) {
                    v = newVip;
                    break;
                }
            }
            return newVip;
        }
    }
    return visitor;
}

std::shared_ptr<Visitor> Utils::downgradeVisitor(std::vector<std::shared_ptr<Visitor>>& visitors, std::shared_ptr<Visitor> visitor) {
    auto vipVisitor = std::dynamic_pointer_cast<VipVisitor>(visitor);
    if (vipVisitor) {
        if (vipVisitor->getLoyaltyPoints() < 200 && vipVisitor->getLoyaltyPoints() >= 100 && vipVisitor->getVipLevel() != "Silver") {
            vipVisitor->downgradeToSilver();
        } else if (vipVisitor->getLoyaltyPoints() >= 200 && vipVisitor->getLoyaltyPoints() < 300 && vipVisitor->getVipLevel() == "Diamond") {
            vipVisitor->downgradeToGold();
        } else
            {
            auto newVisitor = std::make_shared<StandardVisitor>(
                   vipVisitor->getUsername(),
                   vipVisitor->getPassword(),
                   vipVisitor->getLoyaltyPoints(),
                   false,
                   vipVisitor->getTicketType()
               );
            std::cout << "You have been downgraded to Standard! \n" << std::endl;

            for (auto& v : visitors) {
                if (v == vipVisitor) {
                    v = newVisitor;
                    break;
                }
            }
            return newVisitor;
        }
    }
    return visitor;
}

void Utils::handleReservation(std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets,
                       std::shared_ptr<Visitor>& currentVisitor,
                       std::shared_ptr<Exhibition> selectedExhibition,
                       int nrTickets,
                       std::vector<std::shared_ptr<Visitor>>& visitors) {

    bool reservationFound = false;
    auto newTicket = std::make_shared<Ticket<Visitor, Exhibition>>(currentVisitor, selectedExhibition, nrTickets);
    for (auto& ticket : tickets) {
        if (*ticket==*newTicket) {
            ticket->addTickets(nrTickets);
            reservationFound = true;
            std::cout << "Updated Reservation:\n" << *ticket;
            break;
        }
    }
    if (!reservationFound) {
        tickets.push_back(newTicket);
        std::cout << *newTicket;
    }

    currentVisitor->addLoyaltyPoints(nrTickets * 10);
    currentVisitor = upgradeVisitor(visitors, currentVisitor);
    currentVisitor->changeIsFirstTimeVisitor();
}

void Utils::handleCanceledReservation(std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets,
                       std::shared_ptr<Visitor>& currentVisitor,
                       int reservationIndex,
                       std::vector<std::shared_ptr<Visitor>>& visitors) {

    int nrTickets = tickets[reservationIndex-1] -> getNrTickets();

    if (reservationIndex > 0 && reservationIndex <= static_cast<int>(tickets.size())) {
        tickets.erase(tickets.begin() + reservationIndex - 1);
        std::cout << "Reservation has been canceled\n";
        currentVisitor->removeLoyaltyPoints(nrTickets * 10);
        currentVisitor = downgradeVisitor(visitors, currentVisitor);
    } else {
        std::cout << "Index is not valid, try again\n";
    }
}



