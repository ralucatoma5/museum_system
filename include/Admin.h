#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"

class Admin : public User {
protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

public:
    Admin();
    ~Admin() override = default;
};

#endif //ADMIN_H