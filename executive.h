#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "employee.h"
#include "classes.h"
using namespace std;
class HigherUp : public Employee{
    private:
    Global global;
    Login log;
    Tracker report;
    Audit audit;
    Anomaly anom;
    public: 
    HigherUp()
    {

    }
    void showaudit()
    {
        cout << BMAGENTA;
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║                       AUDIT REPORTS                        ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    cout << RESET;
   cout << audit;
        return;
    }
    void showanomaly()
    {
         cout << BMAGENTA;
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║                       ANOMALY REPORTS                      ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    cout << RESET;
        cout << anom;
        return;
    }
    void adduser(string emp_id)
    {
        report.setid(emp_id);
        report += 20;
        string ID, pw;
        cout << "Enter ID for NEW USER: ";
        getline(cin, ID);
        if (IDexists(ID))
        {
            cout << "ID already exists! Choose another ID: ";
            getline(cin, ID);
        }
        cout << "Enter PASSWORD for NEW user: ";
        getline(cin, pw);
        pw = log.hashpw(pw);
        fstream add;
        add.open("users.txt", ios::app);
        add << ID << " " << pw << endl;
        add.close();
        cout << ID << " HIRED!" << endl;
    }
    void showMenu()
    {
        cout << BMAGENTA;
        cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                                 DASH BOARD                                                       ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << RESET;
    
        // Menu Options
        cout << BCYAN;
        cout << "╔════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║ Press                                                                  ║\n";
        cout << "║ 1. ASSIGN TASKS                                                        ║\n";
        cout << "║ 2. VIEW TASKS                                                          ║\n";
        cout << "║ 3. DELEGATE TASK                                                       ║\n";
        cout << "║ 4. SEND MESSAGES                                                       ║\n";
        cout << "║ 5. VIEW MESSAGES                                                       ║\n";
        cout << "║ 6. SEND GLOBAL NOTIFICATION                                            ║\n";
        cout << "║ 7. VIEW PERFORMANCE REPORTS                                            ║\n";
        cout << "║ 8. HIRE A NEW USER                                                     ║\n";
        cout << "║ 9. VIEW AUDIT REPORTS                                                  ║\n";
        cout << "║ 10.VIEW ANOMALY REPORTS                                                ║\n";
        cout << "║ 11.EXIT                                                                ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════╝\n";
        cout << RESET;
    
    cout << YELLOW << "ENTER HERE : " << RESET;
    }
    void sendGlobalMsg(string emp_id)
    {
        report.setid(emp_id);
        report += 3;
        int msgtype;
       cout << BMAGENTA;
    cout << "╔════════════════════════════════════════╗\n";
    cout << "║" << BCYAN << "              Press                     " << BMAGENTA << "║\n";
    cout << "╠════════════════════════════════════════╣\n";
    cout << "║ " << BCYAN << "1. ALERT                               "     << BMAGENTA << "║\n";
    cout << "║ " << BCYAN << "2. EMERGENCY                           " << BMAGENTA << "║\n";
    cout << "║ " << BCYAN << "3. WARNING                             "    << BMAGENTA << "║\n";
    cout << "║ " << BCYAN << "4. EXIT                                " << BMAGENTA << "║\n";
    cout << "╚════════════════════════════════════════╝\n";
    cout << RESET;

    cout << YELLOW << "ENTER HERE : " << RESET;
        cin >> msgtype;
        cin.ignore();
        while (msgtype < 1 or msgtype > 4)
        {
            cout << "Invalid option, Try again: ";
            cin >> msgtype;
        }
        if (msgtype == 1)
        {
            global.sendAlert();
        }
        else if (msgtype == 2)
        {
            global.sendEmergency();
        }
        else if (msgtype == 3)
        {
            global.sendWarning();
        }
        else
        {
            return;
        }
    }
};
class Executive: public HigherUp{
    public:
    Executive(string id)
    {
        emp_id = id;
        grade = 4;
    }
    void showmenu()
    {
    }
};
void executivefunc(string ID);
