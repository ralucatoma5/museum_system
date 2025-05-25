// ScheduleException.h
#ifndef SCHEDULEEXCEPTION_H
#define SCHEDULEEXCEPTION_H

#include <exception>
#include <string>

class ScheduleException : public std::exception {
    std::string msg;
public:
    explicit ScheduleException(const std::string& message = "Schedule error")
        : msg(message) {}

    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class InvalidDayException : public ScheduleException {
public:
    InvalidDayException() : ScheduleException("Invalid day name.") {}
};

class InvalidYesNoResponseException : public ScheduleException {
public:
    InvalidYesNoResponseException() : ScheduleException("Expected 'yes' or 'no' response.") {}
};

class DayNotFoundException : public ScheduleException {
public:
    DayNotFoundException() : ScheduleException("The specified day was not found in the schedule.") {}
};

#endif // SCHEDULEEXCEPTION_H
