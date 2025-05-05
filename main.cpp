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

     cout << "\n====================\nCLASS TEST CASES BEGIN\n====================\n";

    // Login Tests
    Login validUser("alice", "pass123");
    cout << "Test: Valid Login (alice/pass123): " << (validUser.isSuccess() ? "PASSED" : "FAILED") << endl;

    Login invalidUser("alice", "wrongpass");
    cout << "Test: Invalid Login (alice/wrongpass): " << (invalidUser.isSuccess() ? "FAILED" : "PASSED") << endl;

    // PolicyEngine Tests
    cout << "Test: Can Junior delegate to Manager: " 
         << (PolicyEngine::can_delegate(1, 2) ? "PASSED" : "FAILED") << endl;

    cout << "Test: Manager sending WARNING to Junior: "
         << (PolicyEngine::canSendMessage(2, 1, "WARNING") ? "PASSED" : "FAILED") << endl;

    cout << "Test: Junior sending ALERT to Director: "
         << (!PolicyEngine::canSendMessage(1, 3, "ALERT") ? "PASSED" : "FAILED") << endl;

    // Time Expiry Tests
    time_t past = time(0) - 3600; // 1 hour ago
    cout << "Test: TTL Expired for 30min TTL: "
         << (Time::checkExpiry(past, 1800) ? "PASSED" : "FAILED") << endl;
}
