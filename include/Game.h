#include <iostream>

class Game
{
private:
    int Id;
    std::string Name;
public:
    Game();
    ~Game();
    // Getters
    int getId() const;
    std::string getName() const;

    // Setters
    void setId(int id);
    void setName(const std::string &name);
};

