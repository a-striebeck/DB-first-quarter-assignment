#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <iostream>
#include <Game.h>

class Customer
{
private:
    int Id;
    std::string Name;
    std::string LastName;
    std::string EmailAddress;
    std::vector<Game> Games;

    
public:
    Customer(/* args */);
    ~Customer();
    // Getters
    int getId() const;
    std::string getName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    Game getGame(int pos) const;

    // Setters
    void setId(int id);
    void setName(const std::string &name);
    void setLastName(const std::string &lastName);
    void setEmailAddress(const std::string &address);
    void addGame(Game tGame);
};

#endif