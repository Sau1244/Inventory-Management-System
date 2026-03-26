#include "Inputs.h"
#include "Inventory.h"
#include "Factory.h"
#include "Electronics.h"

void Inputs::makeAttributesOfItem(Inventory& inv, bool isElectronics){
    std::string itemID = Inputs::inputUniqueID(inv, true);
    std::string name = Inputs::inputName();
    auto quantity = Inputs::inputValue<int>("Enter quantity:", Item::MIN_QUANTITY, Item::MAX_QUANTITY);
    auto price = Inputs::inputValue<double>("Enter price:", Item::MIN_PRICE, Item::MAX_PRICE);
    if(isElectronics){
        int extras = Inputs::inputWarrantyMonth();
        inv.addItem(Factory::makeElectronics(itemID, name, quantity, price, extras));
    }else{
        std::string extras = Inputs::inputExpiration();
        inv.addItem(Factory::makeGrocery(itemID, name, quantity, price, extras));
    }
}

std::string Inputs::inputUniqueID(const Inventory& inv, bool isBeingAdd){
    std::string input;

    while(true){
        std::cout << "Enter id (or 'q' to exit):";
        std::getline(std::cin, input);

        if(input == "q") throw OperationCancelled();

        if(isBeingAdd) {
            if (inv.isItemIDExists(input)) {
                std::cout << "Item with entered ID, already exists.\n\n";
                continue;
            }
        }else{
            if(!inv.isItemIDExists(input)){
                std::cout << "Item with entered ID does not exist.\n\n";
                continue;
            }
        }

        if(input.empty()){
            std::cout << "ID cannot be empty.\n\n";
            continue;
        }

        return input;
    }
}

std::string Inputs::inputName(){
    while(true) {
        std::cout << "Enter name (or 'q' to exit): ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "q") throw OperationCancelled();

        if (input.empty()) {
            std::cout << "Name cannot be empty.\n\n";
            continue;
        }

        return input;
    }
}

int Inputs::inputWarrantyMonth(){
    std::string input;
    while(true) {
        std::cout << "Enter warranty months (or 'q' to exit): ";
        std::getline(std::cin, input);

        if (input == "q") throw OperationCancelled();

        try{
            int value = std::stoi(input);
            if(value < Electronics::MIN_WARRANTY || value > Electronics::MAX_WARRANTY){
                std::cout << "Value must be between " << Electronics::MIN_WARRANTY << " and " << Electronics::MAX_WARRANTY << "\n\n";
                continue;
            }
            return value;
        }catch(...){
            std::cout << "Invalid input\n";
            continue;
        }
    }
}

std::string Inputs::inputExpiration(){
    std::cout << "Enter expiration date (or 'q' to exit): ";
    std::string input;
    std::getline(std::cin, input);
    if(input == "q") throw OperationCancelled();
    return input;
}