#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <memory>
#include "include/Exhibition.h"
#include "include/ArtExhibition.h"
#include "include/HistoryExhibition.h"
#include "include/ScienceExhibition.h"
#include "include/VipExhibitionEvent.h"
#include "include/User.h"
#include "include/Admin.h"
#include "include/Visitor.h"
#include "include/StandardVisitor.h"
#include "include/VipVisitor.h"
#include "include/Ticket.h"
#include "include/Employees.h"
#include "include/Manager.h"
#include "include/TourGuide.h"
#include "include/Cashier.h"
#include "include/Menu.h"


int main() {

    Menu& menu = Menu::getMenu();
    Admin admin;
    std::vector<std::shared_ptr<Visitor>> visitors;
    std::vector<std::shared_ptr<Exhibition>> exhibitions;
    std::vector<std::shared_ptr<Employees>> employees;
    std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>> tickets;
    std::vector<std::shared_ptr<Ticket<VipVisitor, VipExhibitionEvent>>> vipTickets;
    menu.seedData(exhibitions, visitors, employees, vipTickets);
    bool gamePlayed = false;
    std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>> ratedTickets;
    std::map<std::string, std::vector<std::shared_ptr<Employees>>> schedule;
    menu.loginUser(admin, exhibitions, employees, schedule, visitors, tickets, vipTickets, menu, gamePlayed, ratedTickets);

    return 0;
}
