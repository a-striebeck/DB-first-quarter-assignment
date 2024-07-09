#ifndef UI_H
#define UI_H

#include <iostream>
#include <map>
#include <iomanip>
#include <ClassHandler.h>
#include "Customer.h"
#include "Game.h"
#include <spanish-UI-Messages.h>
class ui
{
private:

    std::map<char, std::function<void()>> Operations;
    ClassHandler *OpManager;

    
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
    ui(SqliteDatabaseHandler &dbHandler);
    ~ui();
    void showMenu();
    void processOperation();
    void showGamesPerCustomer();
    void showCustomersPerGame();
};

#endif // UI_H