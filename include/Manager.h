#ifndef MANAGER_H
#define MANAGER_H

#include "Employees.h"

class Manager : public Employees {
private:
    std::string department;
protected:
    void print(std::ostream& os) const override;
public:
    Manager(const std::string& name, int age, int salary, const std::string& department);
    Manager(const Manager& other);
    Manager& operator=(const Manager& other);
    [[nodiscard]] std::shared_ptr<Employees> clone() const override;
    ~Manager() override = default;
};

#endif //MANAGER_H
