#include "../include/Manager.h"

Manager::Manager(const std::string& name, int age, int salary, const std::string& department)
    : Employees(name, age, salary), department(department) {}

Manager::Manager(const Manager& other)
    : Employees(other), department(other.department) {}

Manager& Manager::operator=(const Manager& other) {
    if (this != &other) {
        Employees::operator=(other);
        department = other.department;
    }
    return *this;
}

std::shared_ptr<Employees> Manager::clone() const {
    return std::make_shared<Manager>(*this);
}

void Manager::print(std::ostream& os) const {
    os << "Manager " << name << "in " << department << " department" << " - " << age << " years old with salary " << salary << "\n";
}