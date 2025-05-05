#include "junior.h"
#include "manager.h"
#include "director.h"
#include "executive.h"
int main()
{
    system ("clear");
    int role;
    cout << "Press 1 for junior, 2 for manager, 3 for director 4 for executive and 5 to exit ";
    cin >> role;
    while (role < 1 or role > 5)
    {
        cout << "Invalid option, Try again: ";
        cin >> role;
    }
    cin.ignore();
    string ID;
    cout << "Enter Registered ID: ";
    getline(cin, ID);
    // yahan par you add your login security checks and password stuff
    if (role == 1)
    {
        juniorfunc(ID);
    }
    else if (role == 2)
    {
        managerfunc(ID);
    }
    else if (role == 3)
    {
        directorfunc(ID);
    }
    else if (role == 4)
    {
        executivefunc(ID);
    }
    else
    {
        cout << "---------------------------- LOGGING OUT ---------------------------------" << endl;
    }
}
