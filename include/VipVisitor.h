#ifndef VIPVISITOR_H
#define VIPVISITOR_H

#include "Visitor.h"

class VipVisitor : public Visitor {
private:
    std::string vipLevel;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

public:
    VipVisitor(const std::string& username, const std::string& password, int loyaltyPoints, bool isFirstTimeVisitor, const std::string& ticketType, const std::string& vipLevel);
    VipVisitor();
    ~VipVisitor() override = default;

    [[nodiscard]] double getDiscount(bool groupDiscount) const override;

    void upgradeToDiamond();
    void upgradeToGold();
    void downgradeToGold();
    void downgradeToSilver();

    const std::string& getVipLevel();
};



#endif //VIPVISITOR_H
