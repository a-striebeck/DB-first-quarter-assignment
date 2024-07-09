#include "Customer.h"


Customer::Customer(){}

Customer::~Customer(){}

// Getters
int Customer::getId() const
{
    return Id;
}

std::string Customer::getName() const
{
    return Name;
}

std::string Customer::getLastName() const
{
    return LastName;
}

std::string Customer::getEmailAddress() const
{
    return EmailAddress;
}

// Setters
void Customer::setId(int id)
{
    Id = id;
}

void Customer::setName(const std::string &name)
{
    Name = name;
}

void Customer::setLastName(const std::string &lastName)
{
    LastName = lastName;
}

void Customer::setEmailAddress(const std::string &address)
{
    EmailAddress = address;
}
