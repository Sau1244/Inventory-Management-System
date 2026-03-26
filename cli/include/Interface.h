#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Inventory.h"
#include "Handlers.h"

struct MenuOption{
    std::string nameOption;
    std::function<void()> actionOption;
};

class Interface{
private:
    std::vector<MenuOption> menuOptions;
    Inventory inv;
    bool isRunning;
public:
    Interface();
    void run();
private:

    /** menu **/
    void handleOption();
    static int handleMenuInput();
    void showMenu();
};