#ifndef CASHIER_H
#define CASHIER_H

#include "Employees.h"

class Cashier : public Employees {
private:
    int registerNumber;
protected:
    void print(std::ostream& os) const override;
public:
    Cashier(const std::string& name, int age, int salary, int registerNumber);
    Cashier(const Cashier& other);
    Cashier& operator=(const Cashier& other);
    [[nodiscard]] std::shared_ptr<Employees> clone() const override;
    ~Cashier() override = default;
};

#endif //CASHIER_H
