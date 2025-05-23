#include "../include/ArtExhibition.h"
#include <iostream>

ArtExhibition::ArtExhibition()
    : Exhibition("unknown", 0), artistName("unknown"), artStyle("unknown") {}

ArtExhibition::ArtExhibition(const std::string& name, int maxVisitors,
                             const std::string& artistName, const std::string& artStyle)
    : Exhibition(name, maxVisitors), artistName(artistName), artStyle(artStyle) {}

double ArtExhibition::getTicketPrice() const {
    return 20.0;
}

void ArtExhibition::print(std::ostream& os) const {
    os << "Art Exhibition: " << name << "\n"
       << "Artist: " << artistName << ", Style: " << artStyle << "\n"
       << "Visitors: " << currentVisitors << "/" << maxVisitors << "\n";
}

void ArtExhibition::read(std::istream& is) {
    std::cout << "Exhibition name: ";
    is >> name;
    std::cout << "Max Visitors: ";
    is >> maxVisitors;
    std::cout << "Artist name: ";
    is >> artistName;
    std::cout << "Art style: ";
    is >> artStyle;
}
