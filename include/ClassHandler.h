#include <Game.h>
#include <Customer.h>
#include <SqliteDatabaseHandler.h>


class ClassHandler
{
private:
    SqliteDatabaseHandler Database;
public:

    void ShowMenu();
    void AddCustomer();
    void EditCustomer();
    void DeleteCustomer();
    Customer SearchCustomer();

    void AddGame();
    void EditGame();
    void DeleteGame();
    Game SearchGame();

    ClassHandler();
    ~ClassHandler();
};


