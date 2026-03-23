#pragma once

#include <iostream>
#include <memory>

class Item;

namespace Factory{
    std::shared_ptr<Item> makeElectronics(const std::string& id, const std::string& name,
                                          int qty, double price, int warrantyMonths);

    std::shared_ptr<Item> makeGrocery(const std::string& id, const std::string& name,
                                          int qty, double price, const std::string& expDate);
}