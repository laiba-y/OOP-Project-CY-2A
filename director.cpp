#include "director.h"
#include "classes.h"
#include "employee.h"
void directorfunc(string ID)
{
    bool running = true;
    Director D(ID);
    while (running)
    {
        D.showMenu(); // showing menu
        int facility;
        cin >> facility;
        system("clear");
        while (facility < 1 or facility > 11) // change numbers according to increase in facilities
        {
            cout << "Option not available, try again: ";
            cin >> facility;
        }
        if (facility == 1)
        {
            D.CreateTask();
        }
        else if (facility == 2)
        {
            D.displayTask();
        }
        else if (facility == 3)
        {
            D.delegate_task();
        }
        else if (facility == 4)
        {
            D.sendmsg();
        }
        else if (facility == 5)
        {
            D.receivemsg();
        }
        else if (facility == 6)
        {
            D.sendGlobalMsg(ID);
        }
        else if (facility == 7)
        {
            string id;
            cout << "Enter the desired ID : ";
            getline(cin, id);
            D.showperformance(id);
        }
        else if (facility == 11)
        {
            Audit::logAction(ID, "LOG OUT", "SUCCESS");
            cout << GREEN;
            cout << "╔════════════════════════════════════════════════════════════╗\n";
            cout << "║                       LOGGING OUT...                       ║\n";
            cout << "╚════════════════════════════════════════════════════════════╝\n";
            cout << RESET;
            return;
        }
        else if (facility == 8)
        {
            D.adduser(ID);
        }
        else if (facility == 9)
        {
            D.showaudit();
        }
        else
        {
            D.showanomaly();
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
        system("clear");
        while (option < 1 || option > 2)
        {
            cout << "Invalid option, Try again: ";
            cin >> option;
        }

        if (option == 2)
        {
            cout << GREEN;
            Audit::logAction(ID, "LOG OUT", "SUCCESS");
            cout << "╔════════════════════════════════════════════════════════════╗\n";
            cout << "║                       LOGGING OUT...                       ║\n";
            cout << "╚════════════════════════════════════════════════════════════╝\n";
            cout << RESET;
            running = false;
        }
    }
}
