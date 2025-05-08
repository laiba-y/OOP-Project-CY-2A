#include "junior.h"
#include "manager.h"
#include "director.h"
#include "executive.h"
int main()
{

//J6: pass123
//M2: password2
//D1: nopw123
//E1: pw123
    
    system ("clear");
    // 1) Prompt for credentials
  

    int role;
    cout << "Press 1 for junior, 2 for manager, 3 for director 4 for executive and 5 to exit ";
    cin >> role;
    cin.ignore();
    while (role < 1 or role > 5)
    {
        cout << "Invalid option, Try again: ";
        cin >> role;
    }
      string username, password;
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    // 2) Check user/pass
    Login user(username, password);
    if (!user.isSuccess()) {
        cout << "Login failed. Exiting.\n";
        return 0;
    }

    // 3) Generate OTP & record gen time
    const int otp_ttl = 60;  // OTP valid for 1 minute
    string otp = user.generate_otp();
    time_t otp_gen_time = time(0);

    cout << "Your one-time code is: " << otp << "\n";
    cout << "Enter OTP: ";
    string realotp;
    getline(cin, realotp);

    // 4) Verify OTP and TTL
    
    if (realotp == otp && !(Time_Manager::checkExpiry(otp_gen_time, otp_ttl))) {
        cout << "OTP Verified. Login fully successful.\n";
    } else {
        cout << "Incorrect or expired OTP. Access denied.\n";
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
        cout << "---------------------------- LOGGING OUT ---------------------------------" << endl;
    }

     cout << "\n====================\nCLASS TEST CASES BEGIN\n====================\n";

    // ---- LOGIN TESTS ----
    cout << "===== LOGIN TESTS =====" << endl;

    // Try valid login
    Login user1("ali", "abc123");  // Should succeed
    cout << "Login for ali: " << (user1.isSuccess() ? "Success" : "Failure") << endl;

    if (user1.isSuccess()) {
    string otp = user1.generate_otp();  
    time_t otp_gen= time(0);
    cout << "Your OTP is: " << otp << endl;

    string input;
    cout << "Enter OTP: ";
    cin >> input;
    time_t otp_now= time(0);
    if (input == otp, Time_Manager::checkExpiry(otp_gen, otp_now) ) {
        cout << "OTP Verified. Login Fully Successful.\n";
    } else {
        cout << "Incorrect OTP. Access Denied.\n";
        Audit::logAction("ali", "OTP_VERIFY", "FAILURE");
        return 0; // exit program
    }
   }
  
    // Try invalid login
    Login user2("ali", "wrongpass");  // Should fail
    cout << "Login for ali with wrong pass: " << (user2.isSuccess() ? "Success" : "Failure") << endl;

    // ---- DELEGATION TESTS ----
    cout << "\n===== POLICY TESTS =====" << endl;

    int junior = 1, manager = 2, director = 3, executive = 4;

    // Delegation: Junior to Manager (Allowed)
    cout << "Delegation J->M: " << (PolicyEngine::can_delegate(junior, manager) ? "Allowed" : "Denied") << endl;

    // Delegation: Manager to Junior (Not allowed)
    cout << "Delegation M->J: " << (PolicyEngine::can_delegate(manager, junior) ? "Allowed" : "Denied") << endl;

    // Message: Junior sends PRIVATE to Manager
    cout << "PRIVATE J->M: " << (PolicyEngine::canSendMessage(junior, manager, "PRIVATE") ? "Allowed" : "Denied") << endl;

    // Message: Junior sends ALERT to Director
    cout << "ALERT J->D: " << (PolicyEngine::canSendMessage(junior, director, "ALERT") ? "Allowed" : "Denied") << endl;

    // Message: Director sends ALERT to Director
    cout << "ALERT D->D: " << (PolicyEngine::canSendMessage(director, director, "ALERT") ? "Allowed" : "Denied") << endl;

    // Message: Manager sends WARNING
    cout << "WARNING M->anyone: " << (PolicyEngine::canSendMessage(manager, junior, "WARNING") ? "Allowed" : "Denied") << endl;

    // ---- TIME EXPIRY TEST ----
    cout << "\n===== TIME TEST =====" << endl;

    time_t taskCreated = time(0) - 3600;  // Task created 1 hour ago
    int ttl = 1800; // TTL = 30 minutes

    cout << "Task expired? " << (Time_Manager::checkExpiry(taskCreated, ttl) ? "Yes" : "No") << endl;
    Anomaly::detect();
}
