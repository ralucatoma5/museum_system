//// ExhibitionException.h
//#ifndef EXHIBITIONEXCEPTION_H
//#define EXHIBITIONEXCEPTION_H
//
//#include <exception>
//#include <string>
//
//class ExhibitionException : public std::exception {
//    std::string message;
//public:
//    explicit ExhibitionException(const std::string& msg = "Exhibition error") : message(msg) {}
//    const char* what() const noexcept override {
//        return message.c_str();
//    }
//};
//
//class InvalidMenuChoiceException : public ExhibitionException {
//public:
//    InvalidMenuChoiceException() : ExhibitionException("Invalid choice. Please enter 'login' or 'exit'.") {}
//};
//
//#endif // EXHIBITIONEXCEPTION_H
