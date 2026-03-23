#pragma once

#include <iostream>
#include <memory>
#include <vector>

class Item;

class Inventory{
private:
    std::vector<std::shared_ptr<Item>> stock;
public:
    Inventory() = default;

    void addItem(std::shared_ptr<Item> newItem);
    void removeItem(const std::string& itemID);
    void updateQuantity(const std::string& itemID, int quantity);
    void displayInventory() const;
};