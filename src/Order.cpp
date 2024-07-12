#include <Order.h>


Order::Order() : gameCount(0){}

Order::~Order() {}


void Order::setCustomer(const Customer& customer) {
    tCustomer = customer;
}


bool Order::addGame(const Game& game) {
    if (gameCount < maxGames) {
        tGames[gameCount] = game;
        gameCount++;
        return true;
    } else {
        return false; // maxGames limit reached
    }
}


Customer Order::getCustomer() const {
    return tCustomer;
}


Game* Order::getGames() {
    return tGames;
}

// Getter para la cantidad de juegos
int Order::getGameCount() const {
    return gameCount;
}