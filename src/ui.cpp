#include <ui.h>


ui::ui(ClassPersister &DB)

{   
    OpManager = &DB;
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

ui::~ui()
{
    delete OpManager;
}

void ui::AddCustomer()
{   

    std::string input;
    Customer* tCustomer = new Customer();
    cout << spanish::addName;
    cin >> input;
    tCustomer->setName(input);
    cout << spanish::addLastName;
    cin >> input;
    tCustomer->setLastName(input);
    cout << spanish::addEmail;
    cin >> input;
    tCustomer->setEmailAddress(input);
    OpManager->AddCustomer(*tCustomer);

    delete tCustomer;

}
void ui::EditCustomer()
{
    Customer* tCustomer = new Customer();
    
    *tCustomer = SearchCustomer();

    std::string input;
    cout << spanish::addName;
    cin >> input;
    tCustomer->setName(input);
    cout << spanish::addLastName;
    cin >> input;
    tCustomer->setLastName(input);
    cout << spanish::addEmail;
    cin >> input;
    tCustomer->setEmailAddress(input);

    OpManager->EditCustomer(*tCustomer);

    delete tCustomer;

}
void ui::DeleteCustomer()
{
    Customer* tCustomer = new Customer();
    
    *tCustomer = SearchCustomer();
    cout << spanish::delConfirmation + tCustomer->getName() + " " + tCustomer->getLastName() << "? ";

    OpManager->DeleteCustomer(*tCustomer);
    
    delete tCustomer;
}

void ui::ListCustomers()
{
    Table customers = OpManager->ListCustomers();
    printTable(customers);
}

Customer ui::SearchCustomer()
{
    string value = "";
    cout << spanish::IDmessage;
    cin >> value;
    Customer tCustomer = OpManager->SearchCustomer(value);

    return tCustomer;
}

void ui::AddGame()
{
    std::string input;
    Game* tGame = new Game();

    cout << spanish::addGameName;
    cin >> input;
    tGame->setName(input);
    OpManager->AddGame(*tGame);

    delete tGame;
}

void ui::EditGame()
{
    Game* tGame = new Game();
    
    *tGame = SearchGame();

    std::string input;
    cout << spanish::addGameName;
    cin >> input;
    tGame->setName(input);

    OpManager->EditGame(*tGame);

    delete tGame;
}

void ui::DeleteGame()
{
    Game *tGame = new Game();
    
    *tGame = SearchGame();
    cout << spanish::delConfirmation + tGame->getName() << "? ";
    OpManager->DeleteGame(*tGame);
}

void ui::ListGames()
{
    Table games = OpManager->ListGames();
    printTable(games);    
}


Game ui::SearchGame()

{
    string value = "";
    cout << spanish::gameIDmessage;
    cin >> value;
    Game tGame = OpManager->SearchGame(value);

    return tGame;
}
void ui::showMenu()
{
    std::cout << spanish::menuMessage;
}

void ui::processOperation()
{
    std::string op;
    std::cout << spanish::operationAsk;
    std::cin >> op;
    if (op == "S") {
            cout << exitMessage;
        } else if (Operations.find(op) != Operations.end()) {
            Operations[op]();
        } else {
            cout << invalidOption;
        }
}

void ui::showGamesPerCustomer()
{
    Table JoinQuery = OpManager->JoinQuerys(true);
    printTable(JoinQuery);
}

void ui::showCustomersPerGame()
{
    Table JoinQuery = OpManager->JoinQuerys(false);
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