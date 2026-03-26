#include "Interface.h"
#include <iomanip>

Interface::Interface() : isRunning(false){
    menuOptions = { {"Add Electronics", [this](){ Handlers::addElectronics(inv); }},
                    {"Add Grocery", [this](){ Handlers::addGrocery(inv); }},
                    {"Remove Item", [this](){ Handlers::removeItem(inv); }},
                    {"Update Quantity", [this](){ Handlers::updateQuantity(inv); }},
                    {"Display Inventory", [this](){ Handlers::displayInventory(inv); }},
                    {"Read From File", [this](){ Handlers::readFromFile(inv); }},
                    {"Write to File", [this](){ Handlers::writeToFile(inv); }},
                    {"Find Most Expensive Item", [this](){ Handlers::findMostExpensive(inv); }},
                    {"Find Items Below Quantity Threshold", [this](){ Handlers::findBelowQuantityThreshold(inv); }},
                    {"Sort by Price", [this](){ Handlers::sortByPrice(inv); }},
                    {"Exit", [this](){ isRunning = false; }}
    };
}

void Interface::run(){
    isRunning = true;
    while(isRunning) {
        showMenu();
        handleOption();
    }
}

void Interface::handleOption(){
    std::cout << "Choose option: ";
    int choice = handleMenuInput();
    if(choice < 1 || choice > menuOptions.size()){
        std::cout << "Invalid input";
        return;
    }

    menuOptions[choice - 1].actionOption();
}

int Interface::handleMenuInput(){
    std::string input;
    std::getline(std::cin, input);

    try{
        return std::stoi(input);
    }catch(...){
        return -1;
    }
}

void Interface::showMenu(){
    std::cout << "\n\n====== Menu ======\n";
    for(size_t i = 0; i < menuOptions.size(); i++)
        std::cout << std::setw(3) << i + 1 << ". " << menuOptions[i].nameOption << "\n";
}

