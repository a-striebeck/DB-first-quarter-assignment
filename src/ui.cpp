#include "ui.h"
#include "ORMPersister.h"

ui::ui(const std::string &db_path) {
    // Inicializa el ORM persister con la ruta de la base de datos
    ormPersister = std::make_unique<ORMPersister>(db_path);
    
    // Mapea las operaciones a las funciones correspondientes
    Operations["1"] = [this]() { AddCustomer(); };
    Operations["2"] = [this]() { EditCustomer(); };
    Operations["3"] = [this]() { DeleteCustomer(); };
    Operations["4"] = [this]() { ListCustomers(); };
    Operations["5"] = [this]() { SearchCustomer(); };
    Operations["6"] = [this]() { AddGame(); };
    Operations["7"] = [this]() { EditGame(); };
    Operations["8"] = [this]() { DeleteGame(); };
    Operations["9"] = [this]() { ListGames(); };
    Operations["10"] = [this]() { SearchGame(); };
    Operations["A"] = [this]() { showGamesPerCustomer(); };
    Operations["B"] = [this]() { showCustomersPerGame(); };
}

void ui::AddCustomer() {
    Customer tCustomer;
    std::string input;

    std::cout << addName;
    std::cin >> input;
    tCustomer.setName(input);
    
    std::cout << addLastName;
    std::cin >> input;
    tCustomer.setLastName(input);
    
    std::cout << addEmail;
    std::cin >> input;
    tCustomer.setEmailAddress(input);

    ormPersister->AddCustomer(tCustomer);  // Usamos el ORM persister
}

void ui::EditCustomer() {
    Customer tCustomer = SearchCustomer();
    std::string input;

    std::cout << addName;
    std::cin >> input;
    tCustomer.setName(input);

    std::cout << addLastName;
    std::cin >> input;
    tCustomer.setLastName(input);

    std::cout << addEmail;
    std::cin >> input;
    tCustomer.setEmailAddress(input);

    ormPersister->EditCustomer(tCustomer);
}

void ui::DeleteCustomer() {
    Customer tCustomer = SearchCustomer();

    std::cout << delConfirmation + tCustomer.getName() + " " + tCustomer.getLastName() << "? ";
    ormPersister->DeleteCustomer(tCustomer);
}

void ui::ListCustomers() {
    Table customers = ormPersister->ListCustomers();
    printTable(customers);
}

Customer ui::SearchCustomer() {
    std::string value;
    std::cout << IDmessage;
    std::cin >> value;
    return ormPersister->SearchCustomer(value);
}

void ui::AddGame() {
    Game tGame;
    std::string input;

    std::cout << addGameName;
    std::cin >> input;
    tGame.setName(input);

    ormPersister->AddGame(tGame);
}

void ui::EditGame() {
    Game tGame = SearchGame();
    std::string input;

    std::cout << addGameName;
    std::cin >> input;
    tGame.setName(input);

    ormPersister->EditGame(tGame);
}

void ui::DeleteGame() {
    Game tGame = SearchGame();
    std::cout << delConfirmation + tGame.getName() << "? ";
    ormPersister->DeleteGame(tGame);
}

void ui::ListGames() {
    Table games = ormPersister->ListGames();
    printTable(games);
}

Game ui::SearchGame() {
    std::string value;
    std::cout << gameIDmessage;
    std::cin >> value;
    return ormPersister->SearchGame(value);
}

void ui::showMenu() {
    std::cout << menuMessage;
}

void ui::processOperation() {
    std::string op;
    std::cout << operationAsk;
    std::cin >> op;

    if (op == "S") {
        std::cout << exitMessage;
    } else if (Operations.find(op) != Operations.end()) {
        Operations[op]();
    } else {
        std::cout << invalidOption;
    }
}

void ui::showGamesPerCustomer() {
    Table joinQuery = ormPersister->JoinQueries(true);
    printTable(joinQuery);
}

void ui::showCustomersPerGame() {
    Table joinQuery = ormPersister->JoinQueries(false);
    printTable(joinQuery);
}

void ui::printTable(const Table& table) {
    if (table.empty()) {
        std::cout << EmpyTable << std::endl;
        return;
    }

    // Imprimir encabezados
    const Row& firstRow = table[0];
    for (const auto& column : firstRow) {
        std::cout << std::setw(20) << std::left << column.first;
    }
    std::cout << std::endl;

    // Imprimir separador
    for (size_t i = 0; i < firstRow.size(); ++i) {
        std::cout << std::setw(20) << std::left << "--------------------";
    }
    std::cout << std::endl;

    // Imprimir filas
    for (const auto& row : table) {
        for (const auto& column : row) {
            std::cout << std::setw(20) << std::left << column.second;
        }
        std::cout << std::endl;
    }
}