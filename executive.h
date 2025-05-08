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
    public: 
    HigherUp()
    {

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
        cout << "-------------------------------------------------- DASH BOARD -------------------------------------------------------------";
        cout << "\nPress \n1. ASSIGN TASKS \n2. VIEW TASKS \n3. DELEGATE TASK \n4. SEND MESSAGES \n5. VIEW MESSAGES \n6. SEND GLOBAL NOTIFICATION \n7. VIEW PERFORMANCE REPORTS \n8. HIRE A NEW USER \n9. EXIT \nENTER HERE: \n"; 
    //     cout << "Press 1 for assigning task, 2 for viewing task, 3 for delegating task, 4 for sending messages, 5 for recieving messages ";
    //    cout << "6 to Send global messages, 7 for performance reports , 8 to Hire a user, 9 to Exit " << endl;
    }
    void sendGlobalMsg(string emp_id)
    {
        report.setid(emp_id);
        report += 3;
        int msgtype;
        cout << "Press \n1. ALERT  \n2. EMERGENCY \n3. WARNING \n4. EXIT \nENTER HERE : ";
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
