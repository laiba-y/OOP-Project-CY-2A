#include "manager.h"
#include "classes.h"
#include "employee.h"
void managerfunc(string ID)
{
    Manager M(ID);
    bool running = true;
    while (running)
    {
        M.showMenu(); // showing menu
        int facility;
        cin >> facility;
        while (facility < 1 or facility > 7) // change numbers according to increase in facilities
        {
            cout << "Option not available, try again: ";
            cin >> facility;
        }
        system("clear");
        if (facility == 1)
        {
            M.CreateTask();
        }
        else if (facility == 2)
        {
            M.displayTask();
        }
        else if (facility == 3)
        {
            M.delegate_task();
        }
        else if (facility == 4)
        {
            M.sendmsg();
        }
        else if (facility == 5)
        {
            M.receivemsg();
        }
        else if (facility == 6)
        {
            M.showperformance(ID);
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
}
