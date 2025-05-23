#ifndef VIPEXHIBITIONEVENT_H
#define VIPEXHIBITIONEVENT_H
#include <memory>
#include "Exhibition.h"
#include <map>

class VipExhibitionEvent : public Exhibition {
private:
    std::string time;
    std::string place;
    std::map<std::string, std::string> perks;
    std::map<std::string, std::string> gifts;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

public:
    VipExhibitionEvent();
    VipExhibitionEvent(const std::string& name, int maxVisitors,
                       const std::string& time, const std::string& place,
                       const std::map<std::string, std::string>& perks,
                       const std::map<std::string, std::string>& gifts);

    ~VipExhibitionEvent() override = default;
    [[nodiscard]] double getTicketPrice() const override;
    void printForYou(std::ostream& os, const std::string& vipLevel) const;
    void printAllPerksAndGifts(std::ostream& os) const;
};

#endif //VIPEXHIBITIONEVENT_H
