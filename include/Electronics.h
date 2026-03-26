#pragma once

#include "Item.h"

class Electronics : public Item{
public:
    static constexpr int MIN_WARRANTY = 0;
    static constexpr int MAX_WARRANTY = 48;
private:
    int warrantyMonths;
public:
    Electronics(int warrantyMonths, std::string itemID, std::string name, int quantity, double price);
    void setWarranty(int newWarranty);

    std::string category() const override;
    void display() const override;
    std::optional<std::string> findAttribute(const std::string& key) const override;
};