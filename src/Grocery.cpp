#include "Grocery.h"
#include <iomanip>

Grocery::Grocery(std::string expirationDate, std::string itemID, std::string name, int quantity, double price)
        : expirationDate(std::move(expirationDate)), Item(std::move(itemID), std::move(name), quantity, price) {}

std::string Grocery::category() const { return "Grocery"; }

void Grocery::display() const{
    std::cout << std::left << std::setw(14) << ("[" + category() + "]");
    displayItemInfo();
    std::cout << " | Expires: " << expirationDate << std::endl;
}

std::optional<std::string> Grocery::findAttribute(const std::string& key) const{
    if(key == "expiration") return expirationDate;
    return findBaseAttribute(key);
}