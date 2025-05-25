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

class InvalidCityException : public ExhibitionException {
public:
    InvalidCityException() : ExhibitionException("Unsupported city. Please enter a valid city.") {}
};

class InvalidExhibitionTypeException : public ExhibitionException {
public:
    InvalidExhibitionTypeException() : ExhibitionException("Unsupported exhibition type. Choose art/history/science/vip.") {}
};



#endif // EXHIBITIONEXCEPTION_H
