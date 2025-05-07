#include "executive.h"
#include "classes.h"
#include "employee.h"
void executivefunc(string ID)
{
    bool running = true;
    Executive Ex(ID);
    while (running)
    {
    Ex.showMenu(); //showing menu
    int facility;
    cin >> facility;
    while (facility < 1 or facility > 8) //change numbers according to increase in facilities
    {
        cout << "Option not available, try again: ";
        cin >> facility;
    }
    while (running)
    
    if (facility == 1)
    {
        Ex.CreateTask();
    }
    else if (facility == 2)
    {
        Ex.displayTask();
    }
    else if (facility == 3)
    {
        Ex.delegate_task();
    }
    else if (facility == 4)
    {
        Ex.sendmsg();
    }
    else if (facility == 5)
    {
        Ex.receivemsg();
    }
    else if (facility == 6)
    {
        Ex.sendGlobalMsg();
    }
    else if (facility == 7)
    {
        string id;
        cout << "Enter the desired ID : ";
        getline(cin, id);
        Ex.showperformance(id);
    }
    else if (facility == 8)
    {
        cout << "------------------ LOGGING OUT ---------------------------";
        return;
    }
    int option;
    cout << "Press 3 to Continue, 4 to Exit: ";
    cin >> option;

    while (option < 3 || option > 4) {
        cout << "Invalid option, Try again: ";
        cin >> option;
    }

    if (option == 4) {
        cout << "----------------------------- LOGGING OUT ----------------------------" << endl;
        running = false;
    }
}
}
