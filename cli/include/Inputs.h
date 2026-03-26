#pragma once
#include <iostream>
#include "Exceptions.h"

class Inventory;

namespace Inputs{
    void makeAttributesOfItem(Inventory& inv, bool isElectronics);

    std::string inputUniqueID(const Inventory& inv, bool isBeingAdd);
    std::string inputName();
    int inputWarrantyMonth();
    std::string inputExpiration();

    template <typename T>
    T inputValue(const std::string& msg, T minValue, T maxValue){
        std::string input;
        while(true){
            std::cout << msg << " (or 'q' to exit):";
            std::getline(std::cin, input);

            if(input == "q") throw OperationCancelled();

            try{
                T value;
                if constexpr (std::is_same_v<T, int>)
                    value = std::stoi(input);
                else if constexpr (std::is_same_v<T, double>)
                    value = std::stod(input);

                if(value < minValue || value > maxValue){
                    std::cout << "Value must be between " << minValue << " and " << maxValue << "\n\n";
                    continue;
                }

                return value;
            }catch(...){
                std::cout << "Invalid input.\n\n";
            }

        }
    }
}