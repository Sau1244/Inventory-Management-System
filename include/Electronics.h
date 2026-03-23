#pragma once

#include "Item.h"

class Electronics : public Item{
private:
    int warrantyMonths;
public:
    Electronics(int warrantyMonths, std::string itemID, std::string name, int quantity, double price);

    std::string category() const override;
    void display() const override;
    std::optional<std::string> findAttribute(const std::string& key) const override;
};