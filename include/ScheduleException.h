// ExhibitionException.h
#ifndef EXHIBITIONEXCEPTION_H
#define EXHIBITIONEXCEPTION_H

#include <exception>
#include <string>

class ExhibitionException : public std::exception {
    std::string message;
public:
    explicit ExhibitionException(const std::string& msg = "Exhibition error") : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidInputException : public ExhibitionException {
public:
    InvalidInputException() : ExhibitionException("Invalid input. Expected 'yes' or 'no'.") {}
};

class LoginFailedException : public ExhibitionException {
public:
    LoginFailedException() : ExhibitionException("Login failed. Invalid credentials.") {}
};

class UsernameExistsException : public ExhibitionException {
public:
    UsernameExistsException() : ExhibitionException("Username already exists.") {}
};

#endif // EXHIBITIONEXCEPTION_H
