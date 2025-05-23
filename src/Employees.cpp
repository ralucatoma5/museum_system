#include "../include/Employees.h"

Employees::Employees(const std::string& name, int age, int salary)
    : name(name), age(age), salary(salary) {}

Employees::Employees(const Employees& other)
    : name(other.name), age(other.age), salary(other.salary) {}

Employees& Employees::operator=(const Employees& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        salary = other.salary;
    }
    return *this;
}

std::string const Employees::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Employees& employees) {
    employees.print(os);
    return os;
}

