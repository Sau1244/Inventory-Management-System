#pragma once
#include <iostream>
#include "Exceptions.h"

class Inventory;

namespace Handlers{
    void addElectronics(Inventory& inv);
    void addGrocery(Inventory& inv);
    void removeItem(Inventory& inv);
    void updateQuantity(Inventory& inv);
    void displayInventory(const Inventory& inv);
    void readFromFile(Inventory& inv);
    void writeToFile(Inventory& inv);
    void findMostExpensive(Inventory& inv);
    void findBelowQuantityThreshold(const Inventory& inv);
    void sortByPrice(Inventory& inv);

    void addItem(Inventory& inv, const std::string& msg, bool isElectronics);
}