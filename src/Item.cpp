#include "Item.h"

#include <utility>

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
    if(newQuantity < MIN_QUANTITY) throw std::invalid_argument("Quantity cannot be negative");
    quantity = newQuantity;
}

void Item::setPrice(double newPrice) {
    if(newPrice < MIN_PRICE) throw std::invalid_argument("Price cannot be negative");
    price = newPrice;
}