#include "../include/Cashier.h"

Cashier::Cashier(const std::string& name, int age, int salary, int registerNumber)
    : Employees(name, age, salary), registerNumber(registerNumber) {}

Cashier::Cashier(const Cashier& other)
    : Employees(other), registerNumber(other.registerNumber) {}

Cashier& Cashier::operator=(const Cashier& other) {
    if (this != &other) {
        Employees::operator=(other);
        registerNumber = other.registerNumber;
    }
    return *this;
}

std::shared_ptr<Employees> Cashier::clone() const {
    return std::make_shared<Cashier>(*this);
}

void Cashier::print(std::ostream& os) const {
    os << "Cashier " << name << "at " << registerNumber << " registerNumber" << " - " << age << " years old with salary " << salary << "\n";
}
