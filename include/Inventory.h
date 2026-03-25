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

    std::vector<std::shared_ptr<Item>>& getStock();
    const std::vector<std::shared_ptr<Item>>& getStock() const;

    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;

    void addItem(std::shared_ptr<Item> newItem);
    void removeItem(const std::string& itemID);
    void updateQuantity(const std::string& itemID, int quantity);
    void displayInventory() const;
private:
    static std::vector<std::string> splitString(const std::string& line);
    void addItemFromFile(const std::vector<std::string>& columns);
};