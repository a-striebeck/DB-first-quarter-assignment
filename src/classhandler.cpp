#include <classhandler.h>

ClassHandler::ClassHandler(SqliteDatabaseHandler &db) : Database(&db)
{
    Database->setConfigFile(".build\\configuration.ini");

    query = R"(
        CREATE TABLE IF NOT EXISTS Customers (
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            Name TEXT NOT NULL,
            LastName TEXT NOT NULL,
            EmailAddress TEXT NOT NULL
        );
    )";
    Database->prepareQuery(query);
    Database->execute();

    query = R"(
        CREATE TABLE IF NOT EXISTS Games (
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            Name TEXT NOT NULL
        );
    )";
    Database->prepareQuery(query);
    Database->execute();

    query = R"(
        CREATE TABLE IF NOT EXISTS Purchases (
            CustomerID INTEGER,
            GameID INTEGER,
            FOREIGN KEY(CustomerID) REFERENCES Customers(ID),
            FOREIGN KEY(GameID) REFERENCES Games(ID)
        );
    )";
    Database->prepareQuery(query);
    Database->execute();

}
ClassHandler::~ClassHandler()
{
}


void ClassHandler::AddCustomer(Customer &tCustomer)
{   
    query = R"(
        INSERT INTO Customers (ID, Name, Lastname, EmailAddress)
        VALUES (?, ?, ?, ?);
    )";

    Database->prepareQuery(query);
    Database->addParameter(1, std::to_string(tCustomer.getId()));
    Database->addParameter(2, tCustomer.getName());
    Database->addParameter(3, tCustomer.getLastName());
    Database->addParameter(4, tCustomer.getEmailAddress());

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
    Database->addParameter(9, tCustomer.getEmailAddress());           

    Database->execute();

}
void ClassHandler::DeleteCustomer(Customer &tCustomer)
{
    query = R"(
        DELETE FROM Customers
        WHERE ID = ?;
    )";

    Database->prepareQuery(query);
    Database->addParameter(1, std::to_string(tCustomer.getId()));
    Database->execute();
}
Customer ClassHandler::SearchCustomer(string value)
{
    query = R"(
        SELECT ID, Name, LastName, EmailAddress FROM Customers WHERE Name = ?;
    )";

    Database->prepareQuery(query);
    Database->addParameter(1, value);
    Database->execute();
    Row row = Database->fetch();

    Customer tCustomer;  // Asegurarse de inicializar tCustomer
    tCustomer.setId(std::stoi(row["ID"]));
    tCustomer.setName(row["Name"]);
    tCustomer.setLastName(row["LastName"]);
    tCustomer.setEmailAddress(row["EmailAddress"]);
    
    return tCustomer;
}
Table ClassHandler::ListCustomers()
{
    query = "SELECT * FROM Customers";
    Database->prepareQuery(query);
    Database->execute();
    return Database->fetchAll();
}

void ClassHandler::AddGame(Game &tGame)
{
    query = R"(
        INSERT INTO Games (ID, Name)
        VALUES (?, ?);
    )";

    Database->prepareQuery(query);
    Database->addParameter(1, std::to_string(tGame.getId()));
    Database->addParameter(2, tGame.getName());

    Database->execute();
}
void ClassHandler::EditGame(Game &tGame)
{
    query = R"(
        UPDATE Games
        SET Name = ?
        WHERE ID = ?;
    )";

    Database->prepareQuery(query);
    Database->addParameter(1, tGame.getName());
    Database->addParameter(2, std::to_string(tGame.getId()));

    Database->execute();
}
void ClassHandler::DeleteGame(Game &tGame)
{
    query = R"(
        DELETE FROM Games
        WHERE ID = ?;
    )";

    Database->prepareQuery(query);
    Database->addParameter(1, std::to_string(tGame.getId()));
    Database->execute();
}
Game ClassHandler::SearchGame(string value)
{
    query = R"(
        SELECT ID, Name FROM Games WHERE Name = ?;
    )";

    Database->prepareQuery(query);
    Database->addParameter(1, value);
    Database->execute();
    Row row = Database->fetch();

    Game tGame;  // Asegurarse de inicializar tGame
    tGame.setId(std::stoi(row["ID"]));
    tGame.setName(row["Name"]);

    return tGame;
}
Table ClassHandler::ListGames()
{
    query = "SELECT * FROM Games";
    Database->prepareQuery(query);
    Database->execute();
    return Database->fetchAll();
}

Table ClassHandler::JoinQuerys(bool selection) {
    
    if (selection) {
        query = R"(
            SELECT Customers.Name AS CustomerName, Games.Name AS GameName
            FROM Customers
            INNER JOIN Purchases ON Customers.ID = Purchases.CustomerID
            INNER JOIN Games ON Purchases.GameID = Games.ID;
        )";
    } else {
        query = R"(
            SELECT Games.Name AS GameName, Customers.Name AS CustomerName
            FROM Games
            INNER JOIN Purchases ON Games.ID = Purchases.GameID
            INNER JOIN Customers ON Purchases.CustomerID = Customers.ID;
        )";
    }

    Database->prepareQuery(query);
    Database->execute();
    return Database->fetchAll();
}