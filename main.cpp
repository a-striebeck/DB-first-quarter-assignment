#include <ui.h>
#include <SqliteDatabaseHandler.h>


int main()
{
    SqliteDatabaseHandler dbHandler;
    dbHandler.setConfigFile(".build\\configuration.ini");

    ui userInterface(dbHandler);
    userInterface.showMenu();

    return 0;
}
