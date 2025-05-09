#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Bright versions
#define BRED    "\033[1;31m"
#define BGREEN  "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE   "\033[1;34m"
#define BMAGENTA "\033[1;35m"
#define BCYAN    "\033[1;36m"
#define BWHITE   "\033[1;37m"

#include "junior.h"
#include "manager.h"
#include "director.h"
#include "executive.h"
int main()
{

//J6: pass123
//M2: pass123
//D1: pass123
//E1: pass123
    
    system ("clear");

    int role;
    cout << "\n";
    cout << BMAGENTA<< "╔════════════════════════════════════╗\n";
    cout << "║          ROLE SELECTION MENU       ║\n" ;
    cout << "╠════════════════════════════════════╣\n" ;
    cout << "║  1. Junior                         ║\n" ;
    cout << "║  2. Manager                        ║\n";
    cout << "║  3. Director                       ║\n";
    cout << "║  4. Executive                      ║\n";
    cout << "║  5. Exit                           ║\n";
    cout << "╚════════════════════════════════════╝\n" << RESET;
    cout << YELLOW <<"Enter your choice (1–5): ";
    cin >> role;
    cin.ignore();
    while (role < 1 or role > 5)
    {
        cout << "Invalid option, Try again: ";
        cin >> role;
    }
    system("clear");
    cout << RESET << BMAGENTA << "\n╔══════════════════════════╗\n";
cout <<      BMAGENTA << "║        LOGIN PANEL       ║\n";
cout <<       BMAGENTA << "╚══════════════════════════╝\n";
      string username, password;
      int i = 0;
      for (; i < 3; i++)
      {
    cout << YELLOW << "Enter Username: ";
    getline(cin, username);
    cout << YELLOW << "Enter Password: ";
    getline(cin, password);

    // 2) Check user/pass
    Login user(username, password);
    if (!user.isSuccess()) {
        cout << RESET << RED << "Login failed! " << 3 - (i+1) << " MORE TRIES ...\n" << RESET;
        Audit::logAction(username, "LOGIN", "FAILURE"); // adding to audit
    }
    else
    break;
    }
    if (i == 3)
    {cout << RESET << RED<< "\n╔══════════════════════════╗\n";
cout <<                       "║        LOGIN FAILED      ║\n";
cout <<                       "╚══════════════════════════╝\n" << RESET;
        return 0;
    }
    Login user(username, password);
    // 3) Generate OTP & record gen time
    const int otp_ttl = 60;  // OTP valid for 1 minute
    string otp = user.generate_otp();
    time_t otp_gen_time = time(0);

    cout << RESET << BMAGENTA << "\n╔══════════════════════════╗\n";
    cout <<   "║    OTP : " << otp << "            ║\n";
cout <<       "╚══════════════════════════╝\n" << RESET;
    cout << YELLOW << "Enter OTP: ";
    string realotp;
    getline(cin, realotp);

    // 4) Verify OTP and TTL
    if (realotp == otp && !(Time_Manager::checkExpiry(otp_gen_time, otp_ttl))) {
        cout << RESET << GREEN << "\nLogin fully successful\n\n" << RESET;
    } else {
        cout << RESET << RED << "Incorrect or expired OTP! ACCESS DENIED.\n" << RESET;
        Audit::logAction(username, "OTP_VERIFY", "FAILURE");
        return 0;
    }
    
    if (role == 1)
    {
        juniorfunc(username);
    }
    else if (role == 2)
    {
        managerfunc(username);
    }
    else if (role == 3)
    {
        directorfunc(username);
    }
    else if (role == 4)
    {
        executivefunc(username);
    }
    else
    {
        cout << GREEN;
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║                       LOGGING OUT...                       ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    cout << RESET;
    }

//      cout << "\n====================\nCLASS TEST CASES BEGIN\n====================\n";

//     // ---- LOGIN TESTS ----
//     cout << "===== LOGIN TESTS =====" << endl;

//     // Try valid login
//     Login user1("ali", "abc123");  // Should succeed
//     cout << "Login for ali: " << (user1.isSuccess() ? "Success" : "Failure") << endl;

//     if (user1.isSuccess()) {
//     string otp = user1.generate_otp();  
//     time_t otp_gen= time(0);
//     cout << "Your OTP is: " << otp << endl;

//     string input;
//     cout << "Enter OTP: ";
//     cin >> input;
//     time_t otp_now= time(0);
//     if (input == otp, Time_Manager::checkExpiry(otp_gen, otp_now) ) {
//         cout << "OTP Verified. Login Fully Successful.\n";
//     } else {
//         cout << "Incorrect OTP. Access Denied.\n";
//         Audit::logAction("ali", "OTP_VERIFY", "FAILURE");
//         return 0; // exit program
//     }
//    }
  
//     // Try invalid login
//     Login user2("ali", "wrongpass");  // Should fail
//     cout << "Login for ali with wrong pass: " << (user2.isSuccess() ? "Success" : "Failure") << endl;

//     // ---- DELEGATION TESTS ----
//     cout << "\n===== POLICY TESTS =====" << endl;

//     int junior = 1, manager = 2, director = 3, executive = 4;

//     // Delegation: Junior to Manager (Allowed)
//     cout << "Delegation J->M: " << (PolicyEngine::can_delegate(junior, manager) ? "Allowed" : "Denied") << endl;

//     // Delegation: Manager to Junior (Not allowed)
//     cout << "Delegation M->J: " << (PolicyEngine::can_delegate(manager, junior) ? "Allowed" : "Denied") << endl;

//     // Message: Junior sends PRIVATE to Manager
//     cout << "PRIVATE J->M: " << (PolicyEngine::canSendMessage(junior, manager, "PRIVATE") ? "Allowed" : "Denied") << endl;

//     // Message: Junior sends ALERT to Director
//     cout << "ALERT J->D: " << (PolicyEngine::canSendMessage(junior, director, "ALERT") ? "Allowed" : "Denied") << endl;

//     // Message: Director sends ALERT to Director
//     cout << "ALERT D->D: " << (PolicyEngine::canSendMessage(director, director, "ALERT") ? "Allowed" : "Denied") << endl;

//     // Message: Manager sends WARNING
//     cout << "WARNING M->anyone: " << (PolicyEngine::canSendMessage(manager, junior, "WARNING") ? "Allowed" : "Denied") << endl;

//     // ---- TIME EXPIRY TEST ----
//     cout << "\n===== TIME TEST =====" << endl;

//     time_t taskCreated = time(0) - 3600;  // Task created 1 hour ago
//     int ttl = 1800; // TTL = 30 minutes

//     cout << "Task expired? " << (Time_Manager::checkExpiry(taskCreated, ttl) ? "Yes" : "No") << endl;
//     Anomaly::detect();
}
