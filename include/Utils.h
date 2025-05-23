#ifndef UTILS_H
#define UTILS_H
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "Employees.h"
#include "Visitor.h"
#include "Exhibition.h"
#include "Ticket.h"


class Utils {
public:
   static std::string capitalizeWord(const std::string& word);

    static void printByType(const std::string& type, const std::vector<std::shared_ptr<Employees>>& employees);

    static void scheduleEachEmployee(const std::vector<std::shared_ptr<Employees>>& employees,
                              std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule,
                              const std::string& day);

    static void scheduleAllEmployees(const std::vector<std::shared_ptr<Employees>>& employees,
                              std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule,
                              const std::string& day);

    static std::shared_ptr<Visitor> upgradeVisitor(std::vector<std::shared_ptr<Visitor>>& visitors,
                                            std::shared_ptr<Visitor> visitor);

    static std::shared_ptr<Visitor> downgradeVisitor(std::vector<std::shared_ptr<Visitor>>& visitors,
                                              std::shared_ptr<Visitor> visitor);

    static void handleReservation(std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets,
                           std::shared_ptr<Visitor>& currentVisitor,
                           std::shared_ptr<Exhibition> selectedExhibition,
                           int nrTickets,
                           std::vector<std::shared_ptr<Visitor>>& visitors);

    static void handleCanceledReservation(std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets,
                                   std::shared_ptr<Visitor>& currentVisitor,
                                   int reservationIndex,
                                   std::vector<std::shared_ptr<Visitor>>& visitors);
};

#endif // UTILS_H

