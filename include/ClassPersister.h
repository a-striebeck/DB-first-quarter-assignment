#ifndef CLASSPERSISTER_H
#define CLASSPERSISTER_H

#include <SqliteDatabaseHandler.h>
#include <Customer.h>
#include <Game.h>



class ClassPersister
{
private:

    SqliteDatabaseHandler *Database;
    string query;

public:

    void AddCustomer(Customer &tCustomer);
    void EditCustomer(Customer &tCustomer);
    void DeleteCustomer(Customer &tCustomer);
    Customer SearchCustomer(string value);
    Table ListCustomers();


    void AddGame(Game &tGame);
    void EditGame(Game &tGame);
    void DeleteGame(Game &tGame);
    Game SearchGame(string value);
    Table ListGames();

    void AddGameToCustomer(Customer &tCustomer, Game &tGame);    
    Table JoinQuerys(bool selection);

    ClassPersister(SqliteDatabaseHandler &db);
    ~ClassPersister();
};
#endif