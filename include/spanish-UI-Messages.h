#include <iostream>

using namespace std;

/*
    Menu message
*/

std::string Menu = R"(
            Gestion de juegos

1.  Ingresar nuevo cliente.
2.  Editar cliente.
3.  Eliminar cliente.
4.  Listar clientes.
5.  Buscar cliente.

6.  Ingresar juego.
7.  Editar juego.
8.  Eliminar juego.
9.  Listar juegos.
10. Buscar juego.

A. Mostrar juegos por cliente.
B. Mostrar clientes por juegos.
S. Salir.
)";

/*
    Process Operation messages
*/
std::string operationAsk = "Ingrese la operación: ";
/*
    Repetitive messages:
*/

    std::string Confirmation = "Ingrese S para confirmar, u ingrese cualquier otro caracter para cancelar.";
/*
    Add Customer messages
*/

std::string addName = "Ingrese el nombre: ";
std::string addLastName = "Ingrese apellido: ";
std::string addEmail = "Ingrese correo electronico: ";

/*
    Message to ask ID
*/

std::string IDmessage = "Ingrese ID del cliente: ";

/*
    Edit Customer messages
*/
std::string EditConfirmation1 = "Desea modificar el cliente: ";

/*
    Search Customer messages
*/

std::string searchMessage = "Datos del cliente";
std::string CxName = "Nombre: ";
std::string CxLastName = "Apellido: ";
std::string CxEmail = "Email: ";

/*
    Delete Customer messages
*/

std::string delConfirmation = "Desea eliminar el cliente: ";

/*
    Add Game messages
*/
string addGameName = "Ingrese el nombre del juego: ";

/*
    Message to ask Game ID
*/
string GameIDmessage = "Ingrese ID del juego: ";

/*
    Edit Game messages
*/
string editGameConfirmation = "Desea modificar el juego: ";

/*
    Search Game messages
*/
string searchGameMessage = "Datos del juego";
string gameNameMessage = "Nombre del juego: ";

/*
    Delete Game messages
*/
string delGameConfirmation = "Desea eliminar el juego: ";



