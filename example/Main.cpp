#include "Inventory.h"
#include "Exceptions.h"
#include "Utils.h"
#include "Factory.h"

int main(){
    Inventory s2;
    try {
        Inventory s;
        s.readFromFile(std::string(PROJECTPATH) + "/data/Inventory.csv");
        std::cout << "File loaded.\n";
        std::cout << "------ Inventory ------\n";
        s.displayInventory();

        /** Demonstrating moving an Inventory instance! **/
        std::cout << "------ Inventory after being moved ------\n";
        s2 = std::move(s);
        s.displayInventory(); // empty
        s2.displayInventory();

        /** Demonstrating filterItems and sorting **/
        s2.findBelowQuantityThreshold(36);

        s2.sortByPrice(true);
        std::cout << "------ Sorted by price ------\n";
        s2.displayInventory();

        /** Added and then deleting item **/
        s2.addItem(Factory::makeElectronics("E3", "Headphones", 13, 531.12, 18));
        std::cout << "------ Added item E3 ------\n";
        s2.displayInventory();
        s2.removeItem("E3");
        std::cout << "------ Removed item E3 ------\n";
        s2.displayInventory();
    }catch(const InventoryException& e){
        std::cout << "\nError: " << e.what() << "\n";
    }

    /** Expected Error Output **/
    try{
        std::cout << "\nExpected Error Output:\n\n";
        std::cout << "> Remove Item: E99";
        s2.removeItem("E99");
    }catch(const InventoryException& e){
        std::cout << "\nError: " << e.what() << "\n";
    }

    try{
        std::cout << "\n> Add Item: E1 (already exists)";
        s2.addItem(Factory::makeElectronics("E1", "temp", 16, 32.64, 128));
    }catch(const InventoryException& e){
        std::cout << "\nError: " << e.what() << "\n";
    }
    return 0;
}