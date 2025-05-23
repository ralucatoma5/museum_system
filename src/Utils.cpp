#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
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

std::string capitalizeWord(const std::string& word) {
    std::string result = word;
    result[0] = std::toupper(result[0]);

    for (int i = 1; i < result.length(); i++) {
        result[i] = std::tolower(result[i]);
    }

    return result;
}


void printByType(const std::string& type, const std::vector<std::shared_ptr<Employees>>& employees) {
    if (!employees.empty()) {
        std::cout <<"\n\n" << type << ":\n";
        for (int i = 0; i < employees.size(); i++) {
            std::cout << i + 1 << ". " << *employees[i] << "\n";
        }
    }
}

void scheduleEachEmployee(const std::vector<std::shared_ptr<Employees>>& employees, std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule, const std::string& day) {
    int empIndex;
    std::cout << "Enter employee index to assign: ";
    std::cin >> empIndex;
    empIndex--;
    if (empIndex >= 0 && empIndex < employees.size()) {
        schedule[day].push_back(employees[empIndex]);
    } else {
        std::cout << "Invalid index.\n";
    }
}

void scheduleAllEmployees(const std::vector<std::shared_ptr<Employees>>& employees, std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule, const std::string& day) {
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

    printByType("Manager", managers);
    scheduleEachEmployee(managers, schedule, day);
    printByType("Tour Guide", tourGuides);
    scheduleEachEmployee(tourGuides, schedule, day);
    printByType("Cashier", cashiers);
    scheduleEachEmployee(cashiers, schedule, day);
    std::cout << "Scheduled " << day << "\n";
}

void printSchedule(const std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule) {
    for (const auto& [day, employees] : schedule) {
        std::cout << "Schedule for " << day << ":\n";
        for (const auto& emp : employees) {
            std::cout << *emp << "\n";
        }
        std::cout << "\n";
    }
}

std::shared_ptr<Visitor> upgradeVisitor(std::vector<std::shared_ptr<Visitor>>& visitors, std::shared_ptr<Visitor> visitor) {
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

std::shared_ptr <Visitor> downgradeVisitor(std::vector<std::shared_ptr<Visitor>>& visitors, std::shared_ptr<Visitor> visitor) {
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

void handleReservation(std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets,
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

void handleCanceledReservation(std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets,
                       std::shared_ptr<Visitor>& currentVisitor,
                       int reservationIndex,
                       std::vector<std::shared_ptr<Visitor>>& visitors) {

    int nrTickets = tickets[reservationIndex-1] -> getNrTickets();
    Ticket<Visitor, Exhibition>::refundMoney(tickets[reservationIndex-1]->getTotalPrice());
    if (reservationIndex > 0 && reservationIndex <= tickets.size()) {
        tickets.erase(tickets.begin() + reservationIndex - 1);
        std::cout << "Reservation has been canceled\n";
        currentVisitor->removeLoyaltyPoints(nrTickets * 10);
        currentVisitor = downgradeVisitor(visitors, currentVisitor);
    } else {
        std::cout << "Index is not valid, try again\n";
    }
}

void deleteExhibitionByIndex(std::vector<std::shared_ptr<Exhibition>>& exhibitions, int index) {
    index--;
    if (index < exhibitions.size()) {
        exhibitions.erase(exhibitions.begin() + index);
        std::cout << "Exhibition at index " << index + 1 << " deleted successfully.\n";
    } else {
        std::cout << "Invalid index. No exhibition deleted.\n";
    }
}

std::string readTicketType() {
    std::string ticketType;
    std::cin >> ticketType;
    ticketType = capitalizeWord(ticketType);
    if (ticketType != "Adult" && ticketType != "Student" && ticketType != "Senior") {
        throw std::invalid_argument("Invalid ticket type entered.");
    }

    return ticketType;
}