#ifndef ARTEXHIBITION_H
#define ARTEXHIBITION_H
#include "Exhibition.h"

class ArtExhibition : public Exhibition {
private:
    std::string artistName;
    std::string artStyle;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

public:
    ArtExhibition();
    ArtExhibition(const std::string& name, int maxVisitors,
                  const std::string& artistName, const std::string& artStyle);
    [[nodiscard]] double getTicketPrice() const override;
};

#endif //ARTEXHIBITION_H
