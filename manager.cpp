#include "manager.h"
#include "classes.h"
#include "employee.h"
void managerfunc(string ID)
{
    Manager M;
    M.showMenu(); //showing menu
    int facility;
    cin >> facility;
    while (facility < 1 or facility > 7) //change numbers according to increase in facilities
    {
        cout << "Option not available, try again: ";
        cin >> facility;
    }
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
        //performance reports here
    }
    else
    {
        cout << "--------------------------- LOGGING OUT ------------------------------------" << endl;
        return;
    }
    int option;
    cout << "Press 3 to Continue, 4 to Exit : ";
    cin >> option;

    while (option < 3 or option > 4)
    {
        cout << "Invalid option, Try again: ";
        cin >> option;
    }
    if (option == 3)
    {
        managerfunc(ID);
    }
    else {
        cout << "----------------------------- LOGGING OUT ----------------------------" << endl;
        return;
    }
}
