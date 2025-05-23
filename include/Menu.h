#ifndef MENU_H
#define MENU_H

#include <vector>
#include <map>
#include <memory>
#include "Exhibition.h"
#include "Employees.h"
#include "Visitor.h"
#include "Ticket.h"
#include "VipVisitor.h"
#include "VipExhibitionEvent.h"


class Menu {
private:
    Menu();
    Menu(const Menu&) = delete;
    Menu operator=(const Menu&) = delete;

public:
    static Menu& getMenu();

    void showAdminMenu();
    void showVisitorMenu();

    void handleAdminChoice(
        int choice,
        std::vector<std::shared_ptr<Exhibition>>& exhibitions,
        const std::vector<std::shared_ptr<Employees>>& employees,
        std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule
    );

    void handleVisitorChoice(
        int choice,
        std::vector<std::shared_ptr<Exhibition>>& exhibitions,
        std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& ratedTickets,
        bool& gamePlayed,
        std::shared_ptr<Visitor>& currentVisitor,
        std::vector<std::shared_ptr<Visitor>>& visitors,
        std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets,
        const std::vector<std::shared_ptr<Ticket<VipVisitor, VipExhibitionEvent>>>& vipTickets
    );

    void seedData(
        std::vector<std::shared_ptr<Exhibition>>& exhibitions,
        std::vector<std::shared_ptr<Visitor>>& visitors,
        std::vector<std::shared_ptr<Employees>>& employees,
        std::vector<std::shared_ptr<Ticket<VipVisitor, VipExhibitionEvent>>>& vipTickets);
};


#endif //MENU_H
