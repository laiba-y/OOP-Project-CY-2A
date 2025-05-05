#include "executive.h"
#include "classes.h"
#include "employee.h"
void executivefunc(string ID)
{
    Executive Ex;
    Ex.showMenu(); //showing menu
    int facility;
    cin >> facility;
    while (facility < 1 or facility > 3) //change numbers according to increase in facilities
    {
        cout << "Option not available, try again: ";
        cin >> facility;
    }
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
}
