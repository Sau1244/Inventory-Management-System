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

    /** Rule of five **/
    ~Inventory() = default;
    Inventory(const Inventory& other) = delete;
    Inventory& operator=(const Inventory& other) = delete;
    Inventory(Inventory&& other) noexcept = default;
    Inventory& operator=(Inventory&& other) noexcept = default;

    void addItem(std::shared_ptr<Item> newItem);
    void removeItem(const std::string& itemID);
    void updateQuantity(const std::string& itemID, int quantity);
    void displayInventory() const;
};