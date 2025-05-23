#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <iostream>
#include <memory>
#include <string>

class Employees {
protected:
    std::string name;
    int age;
    int salary;
    virtual void print(std::ostream& os) const = 0;
public:
    Employees(const std::string& name, int age, int salary);
    Employees(const Employees& other);
    Employees& operator=(const Employees& other);

    [[nodiscard]] const std::string& getName() const;

    friend std::ostream& operator<<(std::ostream& os, const Employees& employees);

    [[nodiscard]] virtual std::shared_ptr<Employees> clone() const = 0;
    virtual ~Employees() = default;

};

#endif //EMPLOYEES_H
