#include <ui.h>
#include <SqliteDatabaseHandler.h>


int main()
{
    
    std::cout << "Compiled successfuly";
    
    //Instancio la base de datos.
    SqliteDatabaseHandler DB;

    //Le indico cual es el archivo de configuracion.
    DB.setConfigFile(".build\\configuration.ini");

    //Instancio y le indico al ClassPersister cual es la base de datos que va a modificar.
    ClassPersister Persister = ClassPersister(DB);
    

    //Instancio una UI que recibe un objeto de tipo ClassPersister,
    //encargado de guardar los datos ingresados en la base de datos.
    ui userInterface(Persister);
    userInterface.showMenu();

    return 0;
}
