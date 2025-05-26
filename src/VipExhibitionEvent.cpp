#include "../include/VipExhibitionEvent.h"
#include <iostream>

VipExhibitionEvent::VipExhibitionEvent()
    : Exhibition("unknown", 0), time("unknown"), place("unknown"),
      perks({{"Silver", "unknown"}, {"Gold", "unknown"}, {"Diamond", "unknown"}}),
      gifts({{"Silver", "unknown"}, {"Gold", "unknown"}, {"Diamond", "unknown"}}) {}

VipExhibitionEvent::VipExhibitionEvent(const std::string& name, int maxVisitors,
                                       const std::string& time, const std::string& place,
                                       const std::map<std::string, std::string>& perks,
                                       const std::map<std::string, std::string>& gifts)
    : Exhibition(name, maxVisitors), time(time), place(place),
      perks(perks), gifts(gifts) {}

double VipExhibitionEvent::getTicketPrice() const {
    return 40.0;
}

void VipExhibitionEvent::printAllPerksAndGifts(std::ostream& os) const {
    os << "*** All VIP Perks and Gifts ***\n";
    for (const auto& [level, perk] : perks) {
        os << level << " Perks: " << perk << "\n";
        os << level << " Gifts: " << gifts.at(level) << "\n";
    }
}

void VipExhibitionEvent::print(std::ostream& os) const {
    os << "VIP Exhibition Event: " << name << "\n";
    os << "Place: " << place << "\n";
    os << "Time: " << time << "\n";
}

void VipExhibitionEvent::printForYou(std::ostream& os, const std::string& vipLevel) const {
    os << "VIP Exhibition Event: " << name << "\n";
    os << "Place: " << place << "\n";
    os << "Time: " << time << "\n";
    os << "Perks for you: " << perks.at(vipLevel) << "\n";
    os << "Gifts for you: " << gifts.at(vipLevel) << "\n";
    os << "Visitors: " << currentVisitors << "/" << maxVisitors << "\n\n";
}

void VipExhibitionEvent::read(std::istream& is) {
    std::cout << "Exhibition name: ";
    is >> name;
    std::cout << "Max Visitors: ";
    is >> maxVisitors;
    std::cout << "Time: ";
    is >> time;
    std::cout << "Place: ";
    is >> place;
    for (int i = 0; i < 3; i++) {
        std::string level, perk, gift;
        std::cout << "Enter VIP level name: ";
        is >> level;
        std::cout << "Enter perk for " << level << ": ";
        is >> perk;
        std::cout << "Enter gift for " << level << ": ";
        is >> gift;
        perks[level] = perk;
        gifts[level] = gift;
    }
}