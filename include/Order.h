#ifndef ORDER_H
#define ORDER_H

#include <Customer.h>
#include <Game.h>

const int maxGames = 10;
class Order
{
private:

    Customer tCustomer;
    Game tGames[maxGames];
    int gameCount;

public:
    Order();
    ~Order();
    
    // Setters
    void setCustomer(const Customer& customer);
    bool addGame(const Game& game);

    // Getters
    Customer getCustomer() const;
    Game* getGames();
    int getGameCount() const;
};


#endif