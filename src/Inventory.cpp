#include "Inventory.h"
#include "Item.h"

#include <algorithm>

void Inventory::addItem(std::shared_ptr<Item> newItem) {
    stock.push_back(std::move(newItem));
}

void Inventory::removeItem(const std::string &itemID) {
    auto item = std::remove_if(stock.begin(), stock.end(),
                               [&itemID](const auto& i){
                                    return i->getItemID() == itemID; });

    stock.erase(item, stock.end());
}

void Inventory::updateQuantity(const std::string &itemID, int quantity) {
    for(auto& item : stock){
        if(item->getItemID() == itemID){
            item->setQuantity(quantity);
            return;
        }
    }
}

void Inventory::displayInventory() const {
    for(const auto& i : stock)
        i->display();
}