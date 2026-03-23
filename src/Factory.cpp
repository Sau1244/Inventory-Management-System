#include "Factory.h"
#include "Electronics.h"
#include "Grocery.h"

std::shared_ptr<Item> Factory::makeElectronics(const std::string& id, const std::string& name,
                                      int qty, double price, int warrantyMonths){
    return std::make_shared<Electronics>(warrantyMonths, id, name, qty, price);
}

std::shared_ptr<Item> Factory::makeGrocery(const std::string& id, const std::string& name,
                                  int qty, double price, const std::string& expDate){
    return std::make_shared<Grocery>(expDate, id, name, qty, price);
}