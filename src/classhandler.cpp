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
        INSERT INTO Customers (ID, Name, Lastname, EmailAddress)
        SELECT ?, ?, ?, ? FROM (SELECT ?, ?, ?, ?) AS tmp
        WHERE NOT EXISTS (
            SELECT EmailAddress FROM Customers WHERE EmailAddress = ?
        ) LIMIT 1;
    )";

    // Preparar la consulta en la base de datos
    Database->prepareQuery(query);

    // Enlazar los parámetros uno por uno en la consulta preparada
    Database->addParameter(1, std::to_string(tCustomer.getId()));     
    Database->addParameter(2, tCustomer.getName());                   
    Database->addParameter(3, tCustomer.getLastName());
    Database->addParameter(4, tCustomer.getEmailAddress());
    Database->addParameter(5, std::to_string(tCustomer.getId()));     
    Database->addParameter(6, tCustomer.getName());                   
    Database->addParameter(7, tCustomer.getLastName());
    Database->addParameter(8, tCustomer.getEmailAddress());
    Database->addParameter(9, tCustomer.getEmailAddress());           // Para la subconsulta EXISTS

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
Customer ClassHandler::SearchCustomer(string value)
{
    query = R"(
    SELECT * FROM Customers
    WHERE )" + value + R"(';
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
