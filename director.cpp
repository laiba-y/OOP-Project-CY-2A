#include "director.h"
#include "classes.h"
#include "employee.h"
void directorfunc(string ID)
{
    bool running = true;
    Director D(ID);
    while (running)
    {
    D.showMenu(); //showing menu
    int facility;
    cin >> facility;
    while (facility < 1 or facility > 9) //change numbers according to increase in facilities
    {
        cout << "Option not available, try again: ";
        cin >> facility;
    }
    while (running)
    
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
        D.sendGlobalMsg();
    }
    else if (facility == 7)
    {
        string id;
        cout << "Enter the desired ID : ";
        getline(cin, id);
        D.showperformance(id);
    }
    else if (facility == 9)
    {
        cout << "------------------ LOGGING OUT ---------------------------";
        return;
    }
    else
    {
        D.adduser();
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
