#include "sqlite_orm.h"
#include "Customer.h"
#include "Game.h"

using namespace sqlite_orm;

// Función para inicializar el almacenamiento ORM
auto initStorage(const std::string &path) {
    return make_storage(path,
        make_table("customers",
            make_column("id", &Customer::id, autoincrement(), primary_key()),
            make_column("name", &Customer::name),
            make_column("email", &Customer::email)),
        make_table("games",
            make_column("id", &Game::id, autoincrement(), primary_key()),
            make_column("title", &Game::title),
            make_column("price", &Game::price)));
}