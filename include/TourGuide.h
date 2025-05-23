#ifndef TOURGUIDE_H
#define TOURGUIDE_H
#include <memory>
#include "Employees.h"
#include <vector>

class TourGuide : public Employees {
private:
    std::vector<std::string> languages;
protected:
    void print(std::ostream& os) const override;
public:
    TourGuide(const std::string& name, int age, int salary, const std::vector<std::string>& languages);
    TourGuide(const TourGuide& other);
    TourGuide& operator=(const TourGuide& other);
    [[nodiscard]] std::shared_ptr<Employees> clone() const override;
    ~TourGuide() override = default;
};

#endif //TOURGUIDE_H
