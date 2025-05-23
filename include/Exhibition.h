#ifndef EXHIBITION_H
#define EXHIBITION_H
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
class Exhibition {
protected:
    static int allTicketsSold;
    std::string name;
    int maxVisitors;
    int currentVisitors;
    std::vector<double> ratings;

    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

public:
    Exhibition(const std::string& name, int maxVisitors);
    virtual ~Exhibition() = default;

    [[nodiscard]] virtual double getTicketPrice() const = 0;
    void incrementVisitors(int nrTickets);
    void decrementVisitors(int nrTickets);
    void addRating(double rating);
    [[nodiscard]] double getAverageRating() const;
    [[nodiscard]] bool isFull() const;

    static void sortExhibitionsByRating(std::vector<std::shared_ptr<Exhibition>>& exhibitions);
    static int getAllTicketsSold();

    const std::string& getName();
    [[nodiscard]] int getMaxVisitors() const;
    [[nodiscard]] int getCurrentVisitors() const;

    friend std::ostream& operator<<(std::ostream& os, const Exhibition& ex);
    friend std::istream& operator>>(std::istream& is, Exhibition& ex);
};

bool operator>(const Exhibition& e1, const Exhibition& e2);

#endif //EXHIBITION_H
