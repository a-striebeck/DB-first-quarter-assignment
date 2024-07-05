#include <classhandler.h>

ClassHandler::ClassHandler(/* args */)
{
}

ClassHandler::~ClassHandler()
{
}

void ClassHandler::ShowMenu(){

}
void ClassHandler::AddCustomer(){
    //Agregar un cliente a la base de datos
}
void ClassHandler::EditCustomer(){
    //Editar un cliente en la base de datos
}
void ClassHandler::DeleteCustomer(){
    //Borrar el cliente de la base de datos
}
Customer ClassHandler::SearchCustomer(){
    Customer tCustomer;

    //Pedir campo al usuario

    //Realizar la busqueda en la base de datos

    return tCustomer;
}

void ClassHandler::AddGame(){
    //Agregar un juego a la base de datos
}
void ClassHandler::EditGame(){
    //Editar un juego en la base de datos
}
void ClassHandler::DeleteGame(){
    //Borrar un juego de la base de datos
}
Game ClassHandler::SearchGame(){
    Game tGame;

    //Pedir campo al usuario

    //Realizar la busqueda en la base de datos

    return tGame;
}