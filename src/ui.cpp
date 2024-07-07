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
    Customer tCustomer;
    cout << addName;
    cin >> input;
    tCustomer.setName(input);
    cout << addLastName;
    cin >> input;
    tCustomer.setLastName(input);
    cout << addEmail;
    cin >> input;
    tCustomer.setEmailAddress(input);
    OpManager.AddCustomer(tCustomer);

}
void ui::EditCustomer()
{
    Customer tCustomer = SearchCustomer();

    std::string input;
    cout << addName;
    cin >> input;
    tCustomer.setName(input);
    cout << addLastName;
    cin >> input;
    tCustomer.setLastName(input);
    cout << addEmail;
    cin >> input;
    tCustomer.setEmailAddress(input);

    OpManager.EditCustomer(tCustomer);

}
void ui::DeleteCustomer()
{
    Customer tCustomer = SearchCustomer();
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

}

void ui::EditGame()
{

}

void ui::DeleteGame()
{

}

void ui::ListGames()
{

}

Game ui::SearchGame()

{

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