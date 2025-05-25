#include "../include/ScienceExhibition.h"
#include <iostream>

ScienceExhibition::ScienceExhibition()
    : Exhibition("unknown", 0), fieldOfScience("unknown"), hasLiveDemos(false) {}

ScienceExhibition::ScienceExhibition(const std::string& name, int maxVisitors,
                                     const std::string& fieldOfScience, bool hasLiveDemos)
    : Exhibition(name, maxVisitors), fieldOfScience(fieldOfScience), hasLiveDemos(hasLiveDemos) {}

double ScienceExhibition::getTicketPrice() const {
    return hasLiveDemos ? 30.0 : 20.0;
}

void ScienceExhibition::print(std::ostream& os) const {
    os << "Science Exhibition: " << name << "\n"
       << "Field of Science: " << fieldOfScience << "\n"
       << "Has Live Demos: " << (hasLiveDemos ? "Yes" : "No") << "\n"
       << "Visitors: " << currentVisitors << "/" << maxVisitors << "\n";
}

void ScienceExhibition::read(std::istream& is) {
    std::cout << "Exhibition name: ";
    is >> name;
    std::cout << "Max Visitors: ";
    is >> maxVisitors;
    std::cout << "Field of science: ";
    is >> fieldOfScience;
    std::cout << "Has live demos (0-No/1-Yes): ";
    is >> hasLiveDemos;
}
