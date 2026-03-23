#include "Grocery.h"

Grocery::Grocery(std::string expirationDate, std::string itemID, std::string name, int quantity, int price)
        : expirationDate(std::move(expirationDate)), Item(std::move(itemID), std::move(name), quantity, price) {}

std::string Grocery::category() const { return "Grocery"; }

void Grocery::display() const{
    std::cout << "[" << category() << "] ";
    displayItemInfo();
    std::cout << " | Expires: " << expirationDate << std::endl;
}

std::optional<std::string> Grocery::findAttribute(const std::string& key) const{
    if(key == "expiration") return expirationDate;
    return findBaseAttribute(key);
}