#ifndef UI_H
#define UI_H

#include <iostream>
#include <map>
#include <functional>
#include <ClassPersister.h>
#include "Customer.h"
#include "Game.h"
#include "spanish-UI-Messages.h"
#include <iomanip> // Para std::setw

using namespace spanish;
class ui {
private:
    std::map<std::string, std::function<void()>> Operations;
    ClassPersister *OpManager;

    void AddCustomer();
    void EditCustomer();
    void DeleteCustomer();
    void ListCustomers();
    Customer SearchCustomer();
    void AddGame();
    void EditGame();
    void DeleteGame();
    void ListGames();
    Game SearchGame();
    void printTable(const Table& table);

public:
    ui(ClassPersister &DB);  
    ~ui();
    void showMenu();
    void processOperation();
    void showGamesPerCustomer();
    void showCustomersPerGame();
};

#endif // UI_H
