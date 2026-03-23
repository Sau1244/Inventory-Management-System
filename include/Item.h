#pragma once

#include <iostream>
#include <optional>

/**
 * @class Item
 * @brief Implements abstract base for Inventory Items
 * with base attributes of id, name, quantity and price
 */
class Item{
private:
    std::string itemID;
    std::string name;
    int quantity;
    double price;

    static constexpr int MIN_QUANTITY = 0;
    static constexpr double MIN_PRICE = 0.0;
public:
    /**
     * @brief Parameterized Constructor to initialize an object
     * @param itemID
     * @param name
     * @param quantity
     * @param price
     */
    Item(std::string itemID, std::string name, int quantity, double price);

    /** Getters **/
    const std::string& getItemID() const;
    const std::string& getName() const;
    int getQuantity() const;
    double getPrice() const;

    /** Setters **/
    void setItemID(std::string newItemID);
    void setName(std::string newName);
    void setQuantity(int newQuantity);
    void setPrice(double newPrice);

    virtual ~Item() = default;
    virtual std::string category() const = 0;
    virtual void display() const = 0;
    virtual std::optional<std::string> findAttribute(const std::string& key) const = 0;
};