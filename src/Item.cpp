#include "Item.h"
#include "Exceptions.h"
#include <iomanip>

/** Constructor **/
Item::Item(std::string itemID, std::string name, int quantity, double price)
        : itemID(std::move(itemID)), name(std::move(name)) {
        setQuantity(quantity);
        setPrice(price);
}

/** Getters **/
const std::string& Item::getItemID() const { return itemID; }
const std::string& Item::getName() const { return name; }
int Item::getQuantity() const { return quantity; }
double Item::getPrice() const { return price; }

/** Setters **/
void Item::setItemID(std::string newItemID) { itemID = std::move(newItemID); }
void Item::setName(std::string newName) { name = std::move(newName); }

void Item::setQuantity(int newQuantity) {
    if(newQuantity < MIN_QUANTITY) throw InvalidValueException("Quantity cannot be negative");
    quantity = newQuantity;
}

void Item::setPrice(double newPrice) {
    if(newPrice < MIN_PRICE) throw InvalidValueException("Price cannot be negative");
    price = newPrice;
}

/** Helpers **/
void Item::displayItemInfo() const{
    std::cout << std::setw(3) << "ID: " << itemID
              << std::setw(20) << (" | Name: " + name)
              << " | Qty: " << std::right << std::setw(4) << quantity
              << " | Price: " << std::right << std::setw(8) << price;
}

std::optional<std::string> Item::findBaseAttribute(const std::string& key) const{
    if(key == "itemID") return itemID;
    if(key == "name") return name;
    if(key == "quantity") return std::to_string(quantity);
    if(key == "price") return std::to_string(price);
    return std::nullopt;
}