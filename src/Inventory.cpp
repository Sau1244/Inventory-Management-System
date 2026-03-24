#include "Inventory.h"
#include "Item.h"
#include "Exceptions.h"

#include <algorithm>

std::vector<std::shared_ptr<Item>>& Inventory::getStock() { return stock; }
const std::vector<std::shared_ptr<Item>>& Inventory::getStock() const { return stock; }

void Inventory::addItem(std::shared_ptr<Item> newItem) {
    bool isExist = std::any_of(stock.begin(), stock.end(),
                               [&newItem](const auto& i){ return i->getItemID() == newItem->getItemID(); });

    if(isExist) throw DuplicateItemException(newItem->getItemID());

    stock.push_back(std::move(newItem));
}

void Inventory::removeItem(const std::string &itemID) {
    auto item = std::remove_if(stock.begin(), stock.end(),
                               [&itemID](const auto& i){
                                    return i->getItemID() == itemID; });

    if(item == stock.end()) throw ItemNotFoundException(itemID);

    stock.erase(item, stock.end());
}

void Inventory::updateQuantity(const std::string &itemID, int quantity) {
    for(auto& item : stock){
        if(item->getItemID() == itemID){
            item->setQuantity(quantity);
            return;
        }
    }

    throw ItemNotFoundException(itemID);
}

void Inventory::displayInventory() const {
    for(const auto& i : stock)
        i->display();
}