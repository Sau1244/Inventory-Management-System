#include "Electronics.h"
#include "Exceptions.h"
#include <iomanip>

Electronics::Electronics(int warrantyMonths, std::string itemID, std::string name, int quantity, double price)
        : Item(std::move(itemID), std::move(name), quantity, price) {
    setWarranty(warrantyMonths);
}

std::string Electronics::category() const{ return "Electronics"; }

void Electronics::setWarranty(int newWarranty){
    if(newWarranty < MIN_WARRANTY) throw InvalidValueException("Warranty cannot be negative");
    if(newWarranty > MAX_WARRANTY) throw InvalidValueException("Warranty cannot be above " + std::to_string(MAX_WARRANTY));
    warrantyMonths = newWarranty;
}

void Electronics::display() const{
    std::cout << std::left << std::setw(14) << ("[" + category() + "]");
    displayItemInfo();
    std::cout << " | Warranty: " << warrantyMonths << " months" << std::endl;
}

std::optional<std::string> Electronics::findAttribute(const std::string& key) const{
    if(key == "warranty") return std::to_string(warrantyMonths);
    return findBaseAttribute(key);
}

