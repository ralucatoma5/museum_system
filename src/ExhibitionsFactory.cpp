#include "../include/ExhibitionFactory.h"

std::shared_ptr<Exhibition> ArtExhibitionFactory::createExhibition() const {
    auto exhibition = std::make_shared<ArtExhibition>();
    std::cin >> *exhibition;
    return exhibition;
}

std::shared_ptr<Exhibition> ScienceExhibitionFactory::createExhibition() const {
    auto exhibition = std::make_shared<ScienceExhibition>();
    std::cin >> *exhibition;
    return exhibition;
}

std::shared_ptr<Exhibition> HistoryExhibitionFactory::createExhibition() const {
    auto exhibition = std::make_shared<HistoryExhibition>();
    std::cin >> *exhibition;
    return exhibition;
}

std::shared_ptr<Exhibition> VipExhibitionFactory::createExhibition() const {
    auto exhibition = std::make_shared<VipExhibitionEvent>();
    std::cin >> *exhibition;
    return exhibition;
}
