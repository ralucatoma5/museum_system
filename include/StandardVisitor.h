#ifndef STANDARDVISITOR_H
#define STANDARDVISITOR_H

#include "Visitor.h"

class StandardVisitor : public Visitor {
protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

public:
    StandardVisitor(const std::string& username, const std::string& password, int loyaltyPoints, bool isFirstTimeVisitor, const std::string& ticketType);
    StandardVisitor();
    ~StandardVisitor() override = default;

    [[nodiscard]] double getDiscount(bool groupDiscount) const override;
};

#endif //STANDARDVISITOR_H
