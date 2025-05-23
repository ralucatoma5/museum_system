#ifndef USER_H
#define USER_H

#include <string>

class User{
protected:
  std::string username;
  std::string password;
  virtual void print(std::ostream& os) const = 0;
  virtual void read(std::istream& is) = 0;

  public:
    User(const std::string& username, const std::string& password);
    virtual ~User() = default;
    [[nodiscard]] bool login(const std::string& user, const std::string& pass) const;

    void readUserCredentials(std::istream& is, std::string& user, std::string& pass) const;

    friend std::ostream& operator<<(std::ostream& os, const User& user);
    friend std::istream& operator>>(std::istream& is, User& user);
};

#endif //USER_H
