#include "../include/Exhibition.h"
#include <iostream>
#include <memory>

int Exhibition::allTicketsSold = 0;

Exhibition::Exhibition(const std::string& name, int maxVisitors)
    : name(name), maxVisitors(maxVisitors), currentVisitors(0) {}

void Exhibition::incrementVisitors( int nrTickets) {
    if (currentVisitors + nrTickets <= maxVisitors) {
        currentVisitors += nrTickets;
        allTicketsSold += nrTickets;
    } else if (currentVisitors == maxVisitors) {
        std::cout << "Exhibition is full!\n";
    } else {
        std::cout << "You can't buy that many tickets\n";
    }
}

void Exhibition::decrementVisitors(int nrTickets) {
    currentVisitors -= nrTickets;
    allTicketsSold -= nrTickets;
}

void Exhibition::addRating(double rating) {
    if (rating >= 1 && rating <= 5) {
        ratings.push_back(rating);
    } else {
        std::cout << "Rating should be between 1 and 5.\n";
    }
}

double Exhibition::getAverageRating() const {
    if (ratings.empty()) return 0.0;
    double sum = 0;
    for (const auto& r : ratings) sum += r;
    return sum / static_cast<double>(ratings.size());
}

bool operator>(const Exhibition& e1, const Exhibition& e2) {
    return e1.getAverageRating() > e2.getAverageRating();
}

void Exhibition::sortExhibitionsByRating(std::vector<std::shared_ptr<Exhibition>>& exhibitions) {
    std::sort(exhibitions.begin(), exhibitions.end(),
        [](const std::shared_ptr<Exhibition>& e1, const std::shared_ptr<Exhibition>& e2) {
            return *e1 > *e2;
        });
}

int Exhibition::getAllTicketsSold() {
    return allTicketsSold;
}

bool Exhibition::isFull() const {
    return currentVisitors >= maxVisitors;
}

const std::string& Exhibition::getName() {
    return name;
}

int Exhibition::getMaxVisitors() const {
    return maxVisitors;
}

int Exhibition::getCurrentVisitors() const {
    return currentVisitors;
}

std::ostream& operator<<(std::ostream& os, const Exhibition& ex) {
    ex.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Exhibition& ex) {
    ex.read(is);
    return is;
}
