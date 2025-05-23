#include "../include/TourGuide.h"

TourGuide::TourGuide(const std::string& name, int age, int salary, const std::vector<std::string>& languages)
    : Employees(name, age, salary), languages(languages) {}

TourGuide::TourGuide(const TourGuide& other)
    : Employees(other), languages(other.languages) {}

TourGuide& TourGuide::operator=(const TourGuide& other) {
    if (this != &other) {
        Employees::operator=(other);
        languages = other.languages;
    }
    return *this;
}

std::shared_ptr<Employees> TourGuide::clone() const {
    return std::make_shared<TourGuide>(*this);
}

void TourGuide::print(std::ostream& os) const {
    os << "Tour Guid " << name << " who knows ";
    for (std::size_t i = 0; i < languages.size()-1; i++) {
        os << languages[i] << ", ";
    }
    os << languages[languages.size()-1] << " - " << age << " years old with salary " << salary << "\n";

}