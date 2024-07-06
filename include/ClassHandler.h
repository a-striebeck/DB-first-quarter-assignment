#include <Game.h>
#include <Customer.h>
#include <SqliteDatabaseHandler.h>


class ClassHandler
{
private:

    SqliteDatabaseHandler Database;
    Customer tCustomer;
    Game tGame;

public:

    void ShowMenu();
    void AddCustomer(Customer &tCustomer);
    void EditCustomer();
    void DeleteCustomer();
    Customer SearchCustomer();
    void ListCustomers();


    void AddGame();
    void EditGame();
    void DeleteGame();
    Game SearchGame();

    ClassHandler();
    ~ClassHandler();
};


