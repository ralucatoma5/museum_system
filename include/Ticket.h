#ifndef TICKET_H
#define TICKET_H

#include <memory>
#include <iostream>
#include "VipVisitor.h"
#include "VipExhibitionEvent.h"

template <typename V, typename E>
class Ticket{
private:
    std::shared_ptr<V> visitor;
    std::shared_ptr<E> exhibition;
    int nrTickets;
    double totalPrice;
    static double moneySpent;

    double calculateTotalPrice(int ticketCount) {
        bool groupDiscount = ticketCount >= 7;
        double price = exhibition->getTicketPrice() * (1 - visitor->getDiscount(groupDiscount)) * ticketCount;
        moneySpent += price;
        return price;
    }

public:
    Ticket(const std::shared_ptr<V>& visitor, const std::shared_ptr<E>& exhibition, int nrTickets)
        : visitor(visitor), exhibition(exhibition), nrTickets(nrTickets),
          totalPrice(calculateTotalPrice(nrTickets)) {}

    ~Ticket() = default;

    void addTickets(int additionalTickets) {
        nrTickets += additionalTickets;
        totalPrice += calculateTotalPrice(additionalTickets);
    }

    [[nodiscard]] double getTotalPrice() const {
        return totalPrice;
    }

    [[nodiscard]] int getNrTickets() const {
        return nrTickets;
    }

    static double getMoneySpent() {
        return moneySpent;
    }

    static void refundMoney(double ticketsPrice) {
        moneySpent -= ticketsPrice;
    }

    const std::shared_ptr<E>& getExhibition() const {
        return exhibition;
    }

    friend std::ostream& operator<<(std::ostream& os, const Ticket<V, E>& ticket) {
        os << "--- Ticket ---\n";
        os << "Exhibition: " << (ticket.getExhibition())->getName() << "\n";
        os << "Number of Tickets: " << ticket.nrTickets << "\n";
        os << "Total Price: " << ticket.totalPrice << " lei\n";

        if constexpr (std::is_same_v<V, VipVisitor> && std::is_same_v<E, VipExhibitionEvent>) {
            ticket.exhibition->printAllPerksAndGifts(os);
        }

        os << "----------------------\n";
        return os;
    }

    bool operator==(const Ticket<V, E>& other) const {
        return getExhibition()->getName() == other.getExhibition()->getName();
    }
};

#endif //TICKET_H
