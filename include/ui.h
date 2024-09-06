#ifndef UI_H
#define UI_H

#include <iostream>
#include <map>
#include <functional>
#include <memory>  // Para usar smart pointers
#include "Customer.h"
#include "Game.h"
#include "ORMPersister.h"
#include <iomanip> // Para std::setw

class ui {
private:
    std::map<std::string, std::function<void()>> Operations;
    std::unique_ptr<ORMPersister> ormPersister;  // Cambiado a unique_ptr para manejar ORM

    // Métodos privados para manejar operaciones
    void AddCustomer();
    void EditCustomer();
    void DeleteCustomer();
    void ListCustomers();
    Customer SearchCustomer();
    void AddGame();
    void EditGame();
    void DeleteGame();
    void ListGames();
    Game SearchGame();
    void printTable(const Table& table);
    void AddOrder();

public:
    ui(const std::string &db_path);  // Cambiado para inicializar con la ruta de la base de datos
    ~ui() = default;  // Uso de destructor por defecto, no necesitamos liberar memoria manualmente
    void showMenu();
    void processOperation();
    void showGamesPerCustomer();
    void showCustomersPerGame();
};

#endif // UI_H
