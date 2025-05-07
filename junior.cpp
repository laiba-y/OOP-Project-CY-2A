#include "junior.h"
#include "classes.h"

void juniorfunc(string ID) {
    Junior J(ID);
    bool running = true;
    
    while (running) {
        J.showMenu();
        int facility;
        cin >> facility;

        while (facility < 1 || facility > 6) {
            cout << "Option not available, try again: ";
            cin >> facility;
        }

        if (facility == 1)
        {
            J.displayTask();       
        }
        else if (facility == 2)
        {
            J.delegate_task();       
        }
        else if (facility == 3)
        {
            J.sendmsg();
        }
        else if (facility == 4)
        {
            J.receivemsg();
        }
        else if (facility == 5)
        {
            J.showperformance(ID);
        }
        else 
        {
            cout << "----------------------------------- LOGGING OUT ----------------------------------------" << endl;
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
