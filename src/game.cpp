#include <game.h>

Game::Game(/* args */){}

Game::~Game(){}


// Getters
int Game::getId() const
{
    return Id;
}

std::string Game::getName() const
{
    return Name;
}

// Setters
void Game::setId(int id)
{
    Id = id;
}

void Game::setName(const std::string &name)
{
    Name = name;
}

