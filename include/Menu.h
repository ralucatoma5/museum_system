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
#include "Admin.h"


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

    void loginUser(
        const Admin& admin,
        std::vector<std::shared_ptr<Exhibition>>& exhibitions,
        const std::vector<std::shared_ptr<Employees>>& employees,
        std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule,
        std::vector<std::shared_ptr<Visitor>>& visitors,
        std::vector<std::shared_ptr<Ticket<Visitor,
        Exhibition>>>& tickets,
        const std::vector<std::shared_ptr<Ticket<VipVisitor,
        VipExhibitionEvent>>>& vipTickets,
        bool& gamePlayed,
        const std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& ratedTickets);

    bool isValid(const std::string& input);

    int getValidatedChoice(int min, int max);
    void runVisitor(std::shared_ptr<Visitor> currentVisitor,
                Menu& menu,
                std::vector<std::shared_ptr<Visitor>>& visitors,
                std::vector<std::shared_ptr<Exhibition>>& exhibitions,
                std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets,
                std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>> ratedTickets,
                const std::vector<std::shared_ptr<Ticket<VipVisitor, VipExhibitionEvent>>>& vipTickets,
                bool& gamePlayed);
    void runAdmin(const Admin& admin, Menu& menu,
        std::vector<std::shared_ptr<Exhibition>>& exhibitions,
              const std::vector<std::shared_ptr<Employees>>& employees,
              std::map<std::string,
              std::vector<std::shared_ptr<Employees>>>& schedule);
};




#endif //MENU_H
