#include "junior.h"
#include "classes.h"

void juniorfunc(string ID)
{
    Employee* J = new Junior(ID);
    bool running = true;

    while (running)
    {
        J->showMenu();
        int facility;
        cin >> facility;
        system("clear");
        while (facility < 1 || facility > 6)
        {
            cout << "Option not available, try again: ";
            cin >> facility;
        }

        if (facility == 1)
        {
            J->displayTask();
        }
        else if (facility == 2)
        {
            J->delegate_task();
        }
        else if (facility == 3)
        {
            J->sendmsg();
        }
        else if (facility == 4)
        {
            J->receivemsg();
        }
        else if (facility == 5)
        {
            J->showperformance(ID);
        }
        else
        {
            Audit::logAction(ID, "LOG OUT", "SUCCESS");
            cout << GREEN;
            cout << "╔════════════════════════════════════════════════════════════╗\n";
            cout << "║                       LOGGING OUT...                       ║\n";
            cout << "╚════════════════════════════════════════════════════════════╝\n";
            cout << RESET;
            return;
        }
        int option;
        cout << BCYAN;
        cout << "╔══════════════════════════════════════╗\n";
        cout << "║              PRESS                   ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║ 1) DASH BOARD                        ║\n";
        cout << "║ 2) LOG OUT                           ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        cout << RESET;

        cout << YELLOW << "ENTER HERE: ";
        cin >> option;
        cout << RESET;
        while (option < 1 || option > 2)
        {
            cout << "Invalid option, Try again: ";
            cin >> option;
        }
        system("clear");
        if (option == 2)
        {
            Audit::logAction(ID, "LOG OUT", "SUCCESS");
            cout << GREEN;
            cout << "╔════════════════════════════════════════════════════════════╗\n";
            cout << "║                       LOGGING OUT...                       ║\n";
            cout << "╚════════════════════════════════════════════════════════════╝\n";
            cout << RESET;
            running = false;
        }
    }
    delete J;
}
