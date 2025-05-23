#ifndef SCIENCEEXHIBITION_H
#define SCIENCEEXHIBITION_H

#include "Exhibition.h"

class ScienceExhibition : public Exhibition {
private:
    std::string fieldOfScience;
    bool hasLiveDemos;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

public:
    ScienceExhibition();
    ScienceExhibition(const std::string& name, int maxVisitors,
                      const std::string& fieldOfScience, bool hasLiveDemos);
    ~ScienceExhibition() override = default;
    [[nodiscard]] double getTicketPrice() const override;
};


#endif //SCIENCEEXHIBITION_H
