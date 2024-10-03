#include <ClassPersister.h>

ClassPersister::ClassPersister(SqliteDatabaseHandler &db) : Database(&db)
{
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
ClassPersister::~ClassPersister()
{
}


void ClassPersister::AddCustomer(Customer &tCustomer)
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
void ClassPersister::EditCustomer(Customer &tCustomer)
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
void ClassPersister::DeleteCustomer(Customer &tCustomer)
{
    query = R"(
        DELETE FROM Customers
        WHERE ID = ?;
    )";

    Database->prepareQuery(query);
    Database->addParameter(1, std::to_string(tCustomer.getId()));
    Database->execute();
}

void ClassPersister::AddGameToCustomer(Customer &tCustomer, Game &tGame){
    query = R"(
        INSERT INTO Purchases (CustomerID, GameID)
        VALUES (?, ?);
    )";

    Database->prepareQuery(query);
    Database->addParameter(1, std::to_string(tCustomer.getId()));
    Database->addParameter(2, std::to_string(tGame.getId()));

    Database->execute();
}

Customer ClassPersister::SearchCustomer(string value)
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
Table ClassPersister::ListCustomers()
{
    query = "SELECT * FROM Customers";
    Database->prepareQuery(query);
    Database->execute();
    return Database->fetchAll();
}

void ClassPersister::AddGame(Game &tGame)
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
void ClassPersister::EditGame(Game &tGame)
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
void ClassPersister::DeleteGame(Game &tGame)
{
    query = R"(
        DELETE FROM Games
        WHERE ID = ?;
    )";

    Database->prepareQuery(query);
    Database->addParameter(1, std::to_string(tGame.getId()));
    Database->execute();
}
Game ClassPersister::SearchGame(string value)
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
Table ClassPersister::ListGames()
{
    query = "SELECT * FROM Games";
    Database->prepareQuery(query);
    Database->execute();
    return Database->fetchAll();
}

Table ClassPersister::JoinQuerys(bool selection) {
    
    if (selection) {
        query = R"(
            SELECT Customers.Name AS CustomerName, Games.Name AS GameName
            FROM Customers
            INNER JOIN Orders ON Customers.ID = Orders.CustomerID
            INNER JOIN Games ON Orders.GameID = Games.ID;
        )";
    } else {
        query = R"(
            SELECT Games.Name AS GameName, Customers.Name AS CustomerName
            FROM Games
            INNER JOIN Orders ON Games.ID = Orders.GameID
            INNER JOIN Customers ON Orders.CustomerID = Customers.ID;
        )";
    }

    Database->prepareQuery(query);
    Database->execute();
    return Database->fetchAll();
}
