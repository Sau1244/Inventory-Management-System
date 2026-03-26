#include "Electronics.h"
#include <iomanip>

Electronics::Electronics(int warrantyMonths, std::string itemID, std::string name, int quantity, double price)
        : warrantyMonths(warrantyMonths), Item(std::move(itemID), std::move(name), quantity, price) {}

std::string Electronics::category() const{ return "Electronics"; }

void Electronics::display() const{
    std::cout << std::left << std::setw(14) << ("[" + category() + "]");
    displayItemInfo();
    std::cout << " | Warranty: " << warrantyMonths << " months" << std::endl;
}

std::optional<std::string> Electronics::findAttribute(const std::string& key) const{
    if(key == "warranty") return std::to_string(warrantyMonths);
    return findBaseAttribute(key);
}

