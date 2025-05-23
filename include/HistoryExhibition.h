#ifndef HISTORYEXHIBITION_H
#define HISTORYEXHIBITION_H
#include "Exhibition.h"

class HistoryExhibition : public Exhibition {
private:
    std::string era;
    int numberOfArtefacts;

protected:
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

public:
    HistoryExhibition();
    HistoryExhibition(const std::string& name, int maxVisitors,
                      const std::string& era, int numberOfArtefacts);
    ~HistoryExhibition() override = default;
    [[nodiscard]] double getTicketPrice() const override;
};

#endif //HISTORYEXHIBITION_H
