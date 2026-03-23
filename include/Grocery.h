#pragma once

#include "Item.h"

class Grocery : public Item{
private:
    std::string expirationDate;
public:
    Grocery(std::string expirationDate, std::string itemID, std::string name, int quantity, int price);

    std::string category() const override;
    void display() const override;
    std::optional<std::string> findAttribute(const std::string& key) const override;
};