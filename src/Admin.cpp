#include "../include/Admin.h"
#include <iostream>

Admin::Admin() : User("admin", "admin123") {}

void Admin::print(std::ostream& os) const {
    os << "Admin: " << username << "\n";
}

void Admin::read(std::istream& is) {
    std::string user, pass;
    readUserCredentials(is, user, pass);
}
