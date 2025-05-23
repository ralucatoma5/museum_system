#include "../include/HistoryExhibition.h"
#include <iostream>

HistoryExhibition::HistoryExhibition()
    : Exhibition("unknown", 0), era("unknown"), numberOfArtefacts(0) {}

HistoryExhibition::HistoryExhibition(const std::string& name, int maxVisitors,
                                     const std::string& era, int numberOfArtefacts)
    : Exhibition(name, maxVisitors), era(era), numberOfArtefacts(numberOfArtefacts) {}

double HistoryExhibition::getTicketPrice() const {
    return 15 + 0.25 * numberOfArtefacts;
}

void HistoryExhibition::print(std::ostream& os) const {
    os << "History Exhibition: " << name << "\n"
       << "Number of artefacts: " << numberOfArtefacts << " in the " << era << "\n"
       << "Visitors: " << currentVisitors << "/" << maxVisitors << "\n";
}

void HistoryExhibition::read(std::istream& is) {
    std::cout << "Exhibition name: ";
    is >> name;
    std::cout << "Max Visitors: ";
    is >> maxVisitors;
    std::cout << "Era: ";
    is >> era;
    std::cout << "Number of artefacts: ";
    is >> numberOfArtefacts;
}

