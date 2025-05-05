#include "director.h"
#include "classes.h"
#include "employee.h"
void directorfunc(string ID)
{
    Director D;
    D.showMenu(); //showing menu
    int facility;
    cin >> facility;
    while (facility < 1 or facility > 3) //change numbers according to increase in facilities
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
}
