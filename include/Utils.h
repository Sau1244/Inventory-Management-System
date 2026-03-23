#pragma once

#include "Item.h"
#include "Inventory.h"
#include <algorithm>

namespace Utils{
    template<typename Predicate>
    std::vector<std::shared_ptr<Item>> filterItems(const Inventory& inv, Predicate pred){
        const auto& stock = inv.getStock();
        std::vector<std::shared_ptr<Item>> result;

        std::copy_if(stock.begin(), stock.end(), std::back_inserter(result), pred);

        return result;
    }

    template<typename Key>
    void sortItems(Inventory& inv, Key keyFn){
        auto& stock = inv.getStock();
        std::sort(stock.begin(), stock.end(), keyFn);
    }
}