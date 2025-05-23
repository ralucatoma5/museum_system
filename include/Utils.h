#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "Employees.h"
#include "Visitor.h"
#include "Exhibition.h"
#include "Ticket.h"

std::string capitalizeWord(const std::string& word);
std::string readTicketType();

void printByType(const std::string& type, const std::vector<std::shared_ptr<Employees>>& employees);

void scheduleEachEmployee(const std::vector<std::shared_ptr<Employees>>& employees,
                          std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule,
                          const std::string& day);

void scheduleAllEmployees(const std::vector<std::shared_ptr<Employees>>& employees,
                          std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule,
                          const std::string& day);

void printSchedule(const std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule);

void deleteExhibitionByIndex(std::vector<std::shared_ptr<Exhibition>>& exhibitions, int index);

std::shared_ptr<Visitor> upgradeVisitor(std::vector<std::shared_ptr<Visitor>>& visitors,
                                        std::shared_ptr<Visitor> visitor);

std::shared_ptr<Visitor> downgradeVisitor(std::vector<std::shared_ptr<Visitor>>& visitors,
                                          std::shared_ptr<Visitor> visitor);

void handleReservation(std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets,
                       std::shared_ptr<Visitor>& currentVisitor,
                       std::shared_ptr<Exhibition> selectedExhibition,
                       int nrTickets,
                       std::vector<std::shared_ptr<Visitor>>& visitors);

void handleCanceledReservation(std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets,
                               std::shared_ptr<Visitor>& currentVisitor,
                               int reservationIndex,
                               std::vector<std::shared_ptr<Visitor>>& visitors);

#endif // UTILS_H

