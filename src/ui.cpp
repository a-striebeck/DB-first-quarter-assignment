#include <ui.H>
#include <map>

ui::ui(/* args */)
{
        Operations['1'] = [this]() { AddCustomer(); };
        Operations['2'] = [this]() { EditCustomer(); };
        Operations['3'] = [this]() { DeleteCustomer(); };
        Operations['4'] = [this]() { ListCustomers(); };
        Operations['5'] = [this]() { SearchCustomer(); };
        Operations['6'] = [this]() { AddGame(); };
        Operations['7'] = [this]() { EditGame(); };
        Operations['8'] = [this]() { DeleteGame(); };
        Operations['9'] = [this]() { ListGames(); };
        Operations['10'] = [this]() { SearchGame(); };
        Operations['A'] = [this]() { showGamesPerCustomer(); };
        Operations['B'] = [this]() { showCustomersPerGame(); };
}

ui::~ui()
{
}

void ui::AddCustomer()
{   

    std::string input;
    Customer* tCustomer = new Customer();
    cout << addName;
    cin >> input;
    tCustomer->setName(input);
    cout << addLastName;
    cin >> input;
    tCustomer->setLastName(input);
    cout << addEmail;
    cin >> input;
    tCustomer->setEmailAddress(input);
    OpManager.AddCustomer(*tCustomer);

    delete tCustomer;

}
void ui::EditCustomer()
{
    Customer* tCustomer = new Customer();
    
    *tCustomer = SearchCustomer();

    std::string input;
    cout << addName;
    cin >> input;
    tCustomer->setName(input);
    cout << addLastName;
    cin >> input;
    tCustomer->setLastName(input);
    cout << addEmail;
    cin >> input;
    tCustomer->setEmailAddress(input);

    OpManager.EditCustomer(*tCustomer);

    delete tCustomer;

}
void ui::DeleteCustomer()
{
    Customer* tCustomer = new Customer();
    
    *tCustomer = SearchCustomer();
    cout << delConfirmation + tCustomer->getName() + " " + tCustomer->getLastName() << "? ";

    OpManager.DeleteCustomer(*tCustomer);
    
    delete tCustomer;
}

void ui::ListCustomers()
{
    
}

Customer ui::SearchCustomer()
{
    string value = "";
    cout << IDmessage;
    cin >> value;
    Customer tCustomer = OpManager.SearchCustomer(value);

    return tCustomer;
}

void ui::AddGame()
{
    std::string input;
    Game* tGame = new Game();

    cout << addGameName;
    cin >> input;
    tGame->setName(input);
    OpManager.AddGame(*tGame);

    delete tGame;
}

void ui::EditGame()
{
    Game* tGame = new Game();
    
    *tGame = SearchGame();

    std::string input;
    cout << addGameName;
    cin >> input;
    tGame->setName(input);

    OpManager.EditGame(*tGame);

    delete tGame;
}

void ui::DeleteGame()
{
    Game *tGame = new Game();
    
    *tGame = SearchGame();
    cout << delConfirmation + tGame->getName() << "? ";
    OpManager.DeleteGame(*tGame);
}

void ui::ListGames()
{

}

Game ui::SearchGame()

{
    string value = "";
    cout << gameIDmessage;
    cin >> value;
    Game tGame = OpManager.SearchGame(value);
}
void ui::showMenu()
{
    std::cout << menuMessage;
}

void ui::processOperation()
{
    char op;
    std::cout << operationAsk;
    std::cin >> op;
    if (op == 'S') {
            cout << exitMessage;
        } else if (Operations.find(op) != Operations.end()) {
            Operations[op]();
        } else {
            cout << invalidOption;
        }
}

void ui::showGamesPerCustomer()
{

}

void ui::showCustomersPerGame()
{

}