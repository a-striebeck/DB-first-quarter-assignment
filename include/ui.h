#include <iostream>
#include <ClassHandler.h>
#include <spanish-UI-Messages.h>

class ui
{
private:

    std::map<char, std::function<void()>> Operations;
    ClassHandler OpManager;

    
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


public:
    ui();
    ~ui();
    void showMenu();
    void processOperation();
    void showGamesPerCustomer();
    void showCustomersPerGame();
};
