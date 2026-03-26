#include "Inventory.h"
#include "Handlers.h"
#include "Item.h"
#include "Inputs.h"

#include <filesystem>

void Handlers::addElectronics(Inventory& inv){
    addItem(inv, "Add Electronics", true);
}

void Handlers::addGrocery(Inventory& inv){
    addItem(inv, "Add Grocery", false);
}

void Handlers::removeItem(Inventory& inv){
    try{
        std::cout << "\n====== Remove Item ======\n";
        std::string itemID = Inputs::inputUniqueID(inv, false);
        inv.removeItem(itemID);
        std::cout << "Item '" + itemID + "' removed properly.";
    }catch(const OperationCancelled& e) {
        std::cout << e.what() << "\n";
    }
}

void Handlers::updateQuantity(Inventory& inv){
    try{
        std::cout << "\n====== Update Item ======\n";
        std::string itemID = Inputs::inputUniqueID(inv, false);
        auto quantity = Inputs::inputValue<int>("Enter quantity:", Item::MIN_QUANTITY, Item::MAX_QUANTITY);
        inv.updateQuantity(itemID, quantity);
        std::cout << "Item '" + itemID + "' updated properly.";
    }catch(const OperationCancelled& e) {
        std::cout << e.what() << "\n";
    }catch(const InventoryException& e){
        std::cout << e.what() << "\n";
    }
}

void Handlers::displayInventory(const Inventory& inv){
    std::cout << "====== Inventory ======\n\n";
    inv.displayInventory();
}

void Handlers::readFromFile(Inventory& inv){
    std::string input;
    std::cout << "====== Read From File ======\n";
    while(true){
        std::cout << "[Warning]: This will clear your current inventory!\n";
        std::cout << "\nEnter path (or 'q' to exit): ";
        std::getline(std::cin, input);

        if(input == "q") return;

        try {
            inv.getStock().clear();
            inv.readFromFile(input);
            std::cout << "File opened properly.";
            return;
        }catch(const InventoryException& e){
            std::cout << e.what() << "\n";
        }

    }
}

void Handlers::writeToFile(Inventory& inv){
    std::string input;
    std::cout << "====== Write To file ======\n";

    if(inv.getStock().empty()){
        std::cout << "Inventory is empty. There is nothing to save.\n\n";
        return;
    }

    while(true){
        std::cout << "\nEnter path (or 'q' to exit): ";
        std::getline(std::cin, input);

        if(input == "q") return;

        if(std::filesystem::exists(input)){
            std::cout << "File Exists. Overwrite? (y/n):";
            std::string choice;
            std::getline(std::cin, choice);

            if(choice != "y") continue;

        }

        try {
            inv.writeToFile(input);
            std::cout << "Inventory saved properly.";
            return;
        }catch(const InventoryException& e){
            std::cout << e.what() << "\n";
        }

    }
}

void Handlers::findMostExpensive(Inventory& inv){
    std::cout << "====== The Most Expensive Item ======\n";
    try{
        auto it = inv.findMostExpensive();
        for(const auto& i : inv.getStock()){
            if(it->getPrice() == i->getPrice())
                i->display();
        }
    }catch(const InventoryException& e){
        std::cout << e.what() << "\n";
    }
}

void Handlers::findBelowQuantityThreshold(const Inventory& inv){
    try {
        std::cout << "====== Quantity Threshold ======\n";
        int quantity = Inputs::inputValue<int>("Enter quantity:", Item::MIN_QUANTITY, Item::MAX_QUANTITY);
        inv.findBelowQuantityThreshold(quantity);
    }catch(const OperationCancelled& e){
        std::cout << e.what() << "\n";
    }
}

void Handlers::sortByPrice(Inventory& inv){
    std::string input;
    while(true) {
        std::cout << "====== Sort By Price ======\n";
        std::cout << "How would you like to sort?\n";
        std::cout << "1. Ascending 2. Descending (or 'q' to exit):";
        std::getline(std::cin, input);

        if(input == "q") return;

        try{
            int value = std::stoi(input);
            if(value != 1 && value != 2) throw InvalidValueException("Invalid input");
            inv.sortByPrice(value == 1);
            std::cout << "Sorted properly.\n";
            return;
        }catch(...){
            std::cout << "Invalid input\n";
        }
    }
}


void Handlers::addItem(Inventory& inv, const std::string& msg, bool isElectronics){
    try {
        std::cout << "====== "<< msg << " ======\n\n";
        Inputs::makeAttributesOfItem(inv, isElectronics);
        std::cout << "Item added properly!\n";
    }catch(const OperationCancelled& e){
        std::cout << e.what() << "\n";
    }catch(const InventoryException& e){
        std::cout << "Error: " << e.what() << "\n";
    }
}