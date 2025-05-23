#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
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


 bool validInput = false;
 while (!validInput) {
    try {
        std::string response;
        std::cout << "Are you an admin? (yes/no): ";
        std::cin >> response;

        if (response != "yes" && response != "no") {
            throw std::invalid_argument("Invalid answer! Please enter a 'yes' or 'no' answer.");
        }

        if (response == "yes") {
            std::string user, pass;
            std::cout << "Enter username to login: ";
            std::cin >> user;
            std::cout << "Enter password to login: ";
            std::cin >> pass;

            if (admin.login(user, pass)) {
                std::cout << "Logged in as Admin\n";
                std::cout << admin;

                std::string input;
                int choice;

                do {
                    bool incorrectInput = true;
                    while (incorrectInput) {
                        bool correctInput = true;
                        menu.showAdminMenu();
                        std::cin >> input;
                        for (char ch : input) {
                            if (!std::isdigit(ch))
                                correctInput = false;
                        }

                        if(!correctInput)
                            std::cout << "\nChoose a valid number from the list!\n";
                        else
                            choice = std::stoi(input);

                        if (choice < 0 || choice > 5)
                            correctInput = false;

                        if (correctInput) {
                            incorrectInput = false;
                            menu.handleAdminChoice(choice, exhibitions, employees, schedule);
                        }
                    }
                }while (choice!=0);
                validInput = true;
            } else {
                throw std::runtime_error("Admin login failed.");
            }
        }

        if (response == "no") {
            std::cout << "Do you have an account? (yes/no): ";
            std::cin >> response;
            if (response != "yes" && response != "no") {
                throw std::invalid_argument("Invalid answer! Please enter a 'yes' or 'no' answer.");
            }
            bool found = false;
            std::shared_ptr<Visitor> currentVisitor = nullptr;

            if (response == "no") {
                auto newVisitor = std::make_shared<StandardVisitor>();
                std::cin >> *newVisitor;
                std::string newUsername = newVisitor->getUsername();
                bool usernameExists = false;

                for (const auto& v : visitors) {
                    if (v->getUsername() == newUsername) {
                        usernameExists = true;
                        break;
                    }
                }

                if (usernameExists) {
                    throw std::invalid_argument("Username already exists.");
                }
                visitors.push_back(newVisitor);
                currentVisitor = newVisitor;
                found = true;
                std::cout << "Account created successfully!\n";
            }

            if (!found) {
                std::string user, pass;
                std::cout << "Enter username to login: ";
                std::cin >> user;
                std::cout << "Enter password to login: ";
                std::cin >> pass;

                for (const auto& visitor : visitors) {
                    if (visitor->login(user, pass)) {
                        currentVisitor = visitor;
                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                throw std::runtime_error("Visitor login failed.");
            }

            if (currentVisitor) {
                std::cout << "Logged in as Visitor\n";
                std::cout << "Welcome " << currentVisitor->getUsername() << "!\n";
                int choice;
                do {
                    std::string input;
                    bool incorrectInput = true;
                    while (incorrectInput) {
                        bool correctInput = true;
                        menu.showVisitorMenu();
                        std::cin >> input;
                        for (char ch : input) {
                            if (!std::isdigit(ch))
                                correctInput = false;
                        }

                        if(!correctInput)
                            std::cout << "\nChoose a valid number from the list!\n";
                        else
                            choice = std::stoi(input);

                        if (choice < 0 || choice > 10)
                            correctInput = false;

                        if (correctInput) {
                            incorrectInput = false;
                            menu.handleVisitorChoice(choice, exhibitions, ratedTickets, gamePlayed, currentVisitor, visitors, tickets, vipTickets);
                        }
                    }
                } while (choice!=0);
                validInput = true;
            } else {
                std::cout << "Invalid credentials or account not found!\n";
            }
        }

    } catch (const std::exception& e) {
        std::cout << "\nError: " << e.what() << "\n";
        std::cout << "Restarting login process \n\n";
    }
}

    return 0;
}
