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

class InvalidChoiceException : public ExhibitionException {
public:
    InvalidChoiceException() : ExhibitionException("Invalid exhibition choice.") {}
};

class ExhibitionFullException : public ExhibitionException {
public:
    ExhibitionFullException() : ExhibitionException("This exhibition is full.") {}
};

class NotEnoughTicketsException : public ExhibitionException {
public:
    NotEnoughTicketsException(): ExhibitionException("Not enough tickets available.") {}

};

#endif // EXHIBITIONEXCEPTION_H
