#include <classhandler.h>

ClassHandler::ClassHandler(/* args */)
{
}

ClassHandler::~ClassHandler()
{
}


void ClassHandler::AddCustomer(Customer &tCustomer)
{   
    query = R"(
    INSERT INTO Customers (ID, Name, Lastname, EmailAddress)
    VALUES (')" + std::to_string(tCustomer.getId()) + R"(', ')" 
    + tCustomer.getName() + R"(', ')" 
    + tCustomer.getLastName() + R"(', ')" 
    + tCustomer.getEmailAddress() + R"(', ')";

    Database->prepareQuery(query);
    Database->execute();
}
void ClassHandler::EditCustomer(Customer &tCustomer)
{
    query = R"(
        UPDATE Customers
        SET Name = ')" + tCustomer.getName() + R"(',
            Lastname = ')" + tCustomer.getLastName() + R"(',
            EmailAddress = ')" + tCustomer.getEmailAddress() + R"('
        WHERE ID = )" + std::to_string(tCustomer.getId()) + R"();
    )";

    Database->prepareQuery(query);
    Database->execute();
}
void ClassHandler::DeleteCustomer(Customer &tCustomer)
{
    query = R"(
        DELETE FROM Customers
        WHERE ID = )" + std::to_string(tCustomer.getId()) + R"();
    )";

    Database->prepareQuery(query);
    Database->execute();
}
Customer ClassHandler::SearchCustomer(string row, string value)
{
    query = R"(
        SELECT * FROM Customers
        WHERE )" + row + " = '" + value + R"(';
    )";
    Database->prepareQuery(query);
    Database->execute();

    //Asignar los valores del registro, a los atributos de un objeto.


    return tCustomer;
}
void ClassHandler::ListCustomers()
{
    query = "SELECT * FROM Customers";
    Database->prepareQuery(query);
    Database->execute();
}

void ClassHandler::AddGame(Game &tGame)
{
    query = R"(
        INSERT INTO Games (ID, Name)
        VALUES (')" + std::to_string(tGame.getId()) 
        + R"(', ')" + tGame.getName() + R"(');
    )";

    Database->prepareQuery(query);
    Database->execute();
}
void ClassHandler::EditGame(Game &tGame)
{
    query =  R"(
        UPDATE Games
        SET Name = ')" + tGame.getName() + R"('
        WHERE ID = )" + std::to_string(tGame.getId()) + R"();
    )";

    Database->prepareQuery(query);
    Database->execute();
}
void ClassHandler::DeleteGame(Game &tGame)
{
    query = R"(
        DELETE FROM Games
        WHERE ID = )" + std::to_string(tGame.getId()) + R"();
    )";

    Database->prepareQuery(query);
    Database->execute();
}
Game ClassHandler::SearchGame(string row, string value)
{
    query = R"(
        SELECT * FROM Games
        WHERE )" + row + " = '" + value + R"(';
    )";
    Database->prepareQuery(query);
    Database->execute();

    //Asignar los valores del registro, a los atributos de un objeto.

    return tGame;
}
void ClassHandler::ListGames()
{
    query = "SELECT * FROM Games";
    Database->prepareQuery(query);
    Database->execute();
    
    //Listar los registros de la BD y mostrarlos por consola.
}
