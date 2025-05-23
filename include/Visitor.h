#ifndef VISITOR_H
#define VISITOR_H

#include "User.h"

class Visitor : public User {
protected:
    int loyaltyPoints;
    bool isFirstTimeVisitor;
    std::string ticketType;

public:
    Visitor(const std::string& username, const std::string& password, int loyaltyPoints, bool isFirstTimeVisitor, const std::string& ticketType);
    ~Visitor() override = default;

    [[nodiscard]] virtual double getDiscount(bool groupDiscount) const = 0;

    void addLoyaltyPoints(int points);
    void removeLoyaltyPoints(int points);
    void changeIsFirstTimeVisitor();

    int getLoyaltyPoints();
    const std::string& getUsername();
    const std::string& getTicketType();
    const std::string& getPassword();
    bool getIsFirstTimeVisitor() const;
};

#endif //VISITOR_H
