#ifndef EXHIBITIONFACTORY_H
#define EXHIBITIONFACTORY_H

#include <memory>
#include <iostream>
#include "ArtExhibition.h"
#include "ScienceExhibition.h"
#include "HistoryExhibition.h"
#include "VipExhibitionEvent.h"

class ExhibitionFactory {
public:
    virtual ~ExhibitionFactory() = default;
    [[nodiscard]] virtual std::shared_ptr<Exhibition> createExhibition() const = 0;
};

class ArtExhibitionFactory : public ExhibitionFactory {
public:
    ~ArtExhibitionFactory() override = default;
    [[nodiscard]] std::shared_ptr<Exhibition> createExhibition() const override;
};

class ScienceExhibitionFactory : public ExhibitionFactory {
public:
    ~ScienceExhibitionFactory() override = default;
    [[nodiscard]] std::shared_ptr<Exhibition> createExhibition() const override;
};

class HistoryExhibitionFactory : public ExhibitionFactory {
public:
    ~HistoryExhibitionFactory() override = default;
    [[nodiscard]] std::shared_ptr<Exhibition> createExhibition() const override;
};

class VipExhibitionFactory : public ExhibitionFactory {
public:
    ~VipExhibitionFactory() override = default;
    [[nodiscard]] std::shared_ptr<Exhibition> createExhibition() const override;
};


#endif //EXHIBITIONFACTORY_H
