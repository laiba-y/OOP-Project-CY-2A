#include "manager.h"
#include "classes.h"
void managerfunc(string ID)
{
    Manager M;
    M.showMenu(); //showing menu
    int facility;
    cin >> facility;
    while (facility < 1 or facility > 3) //change numbers according to increase in facilities
    {
        cout << "Option not available, try again: ";
        cin >> facility;
    }
    if (facility == 1)
    {
        M.CreateTask();
    }
}
