#include "Inventory.h"
#include "Item.h"
#include "Exceptions.h"
#include "Factory.h"
#include "Utils.h"

#include <algorithm>
#include <sstream>
#include <fstream>

std::vector<std::shared_ptr<Item>>& Inventory::getStock() { return stock; }
const std::vector<std::shared_ptr<Item>>& Inventory::getStock() const { return stock; }


void Inventory::readFromFile(const std::string& filename){
    if(!stock.empty())
        throw InventoryException("Stock is not empty.");

    std::ifstream file(filename);

    if(!file.is_open())
        throw InventoryException("Unable to open '" + filename + "'");

    if(!Inventory::hasCSV(filename))
        throw InventoryException("File should be ended with '.csv'");

    std::string line;

    while(std::getline(file, line)){
        auto columns = splitString(line);
        try {
            addItemFromFile(columns);
        }catch(const InventoryException& e) {
            std::cout << "\n[Error] " << e.what() << "\n";
        }catch(const std::exception&){
            std::cout << "\n[Error]: Invalid number format.\n";
        }
    }

    file.close();
}

void Inventory::writeToFile(const std::string& filename) const{
    if(stock.empty())
        throw InventoryException("Stock is empty.");

    std::ofstream file(filename);

    if(!file.is_open())
        throw InventoryException("Unable to create " + filename);

    if(!Inventory::hasCSV(filename))
        throw InventoryException("File should be ended with '.csv'");

    for(const auto& i : stock){
        auto category = i->category();

        auto extra = category == "Electronics" ? i->findAttribute("warranty") : i->findAttribute("expiration");
        if(!extra)
            throw InventoryException("Extra Column is empty");

        file << i->getItemID() << ',' << i->category() << ','
            << i->getName() << ',' << i->getQuantity() << ',' << i->getPrice() << ','
            << extra.value() << "\n";
    }
}

bool Inventory::isItemIDExists(const std::string& id) const{
    return std::any_of(stock.begin(), stock.end(),
                               [&id](const auto& i){ return i->getItemID() == id; });
}

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

std::vector<std::string> Inventory::splitString(const std::string& line){
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string column;

    while(std::getline(ss, column, ',')){
        result.push_back(column);
    }

    return result;
}

void Inventory::addItemFromFile(const std::vector<std::string>& columns){
    if(columns.size() < 6)
        throw InventoryException("Invalid row format.");

    const std::string& itemID = columns[0];
    const std::string& category = columns[1];
    const std::string& name = columns[2];

    int quantity = std::stoi(columns[3]);
    double price = std::stod(columns[4]);

    Inventory::validateItemAttributes(itemID, name, quantity, price);
    const auto& extras = columns[5];
    if (category == "Electronics")
        addItem(Factory::makeElectronics(itemID, name, quantity, price, std::stoi(extras)));
    else if (category == "Grocery")
        addItem(Factory::makeGrocery(itemID, name, quantity, price, extras));
    else
        throw InventoryException("Category " + category + " does not exist.");
}

void Inventory::validateItemAttributes(const std::string& itemID, const std::string& name, int quantity, double price){
    if(itemID.empty()) throw InvalidValueException("ID cannot be empty");
    if(name.empty()) throw InvalidValueException("Name cannot be empty");
    if(price < Item::MIN_PRICE) throw InvalidValueException("Price cannot be negative");
    if(price > Item::MAX_PRICE) throw InvalidValueException("Price cannot be above " + std::to_string(Item::MAX_PRICE));
    if(quantity < Item::MIN_QUANTITY) throw InvalidValueException("Quantity cannot be negative");
    if(quantity > Item::MAX_QUANTITY) throw InvalidValueException("Quantity cannot be above " + std::to_string(Item::MAX_QUANTITY));
}

bool Inventory::hasCSV(const std::string& filename){
    return filename.size() >= 4 && (filename.substr(filename.size() - 4) == ".csv");
}

std::shared_ptr<Item> Inventory::findMostExpensive() const{
    if(stock.empty()) throw InventoryException("Stock is empty.");

    return *std::max_element(stock.begin(), stock.end(),
                               [](const auto& a, const auto& b)
                                                { return a->getPrice() < b->getPrice(); });

}

void Inventory::findBelowQuantityThreshold(int threshold) const{
    auto filtered = Utils::filterItems(*this, [&threshold](const auto& item){ return item->getQuantity() < threshold; });
    std::cout << "------ Filtered by items with quantity below " << threshold << " ------\n";
    for(const auto& item : filtered)
        item->display();
}

void Inventory::sortByPrice(bool isAscending){
    Utils::sortItems(*this, [&isAscending](const auto& a, const auto& b){ return isAscending ? a->getPrice() < b->getPrice() : a->getPrice() > b->getPrice(); });
}