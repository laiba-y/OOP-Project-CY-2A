#include "junior.h"
#include "manager.h"
#include "director.h"
#include "executive.h"

int main()
{
    system ("clear");
    int role;
    cout << "Press 1 for junior, 2 for manager, 3 for director and 4 for executive: "; //add more options into this dont remove these lines as i have to code with the flow with these
    cin >> role;
    cin.ignore();
    string ID;
    cout << "Enter Registered ID: ";
    getline(cin, ID);
    // yahan par you add your login security checks and password stuff
    if (role == 1)
    {
        juniorfunc(ID);
    }
    else if (role == 2);
    {
        managerfunc(ID);
    }
}
