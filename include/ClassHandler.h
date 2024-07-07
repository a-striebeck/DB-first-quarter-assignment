#include <Game.h>
#include <Customer.h>
#include <SqliteDatabaseHandler.h>


class ClassHandler
{
private:

    SqliteDatabaseHandler *Database;
    Customer tCustomer;
    Game tGame;
    string query;

public:

    void ShowMenu();
    void AddCustomer(Customer &tCustomer);
    void EditCustomer(Customer &tCustomer);
    void DeleteCustomer(Customer &tCustomer);
    Customer SearchCustomer(string value);
    void ListCustomers();


    void AddGame(Game &tGame);
    void EditGame(Game &tGame);
    void DeleteGame(Game &tGame);
    Game SearchGame(string value);
    void ListGames();
    

    ClassHandler();
    ~ClassHandler();
};


