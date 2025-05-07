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
    public: 
    HigherUp()
    {

    }
    void adduser()
    {
        string ID, pw;
        cout << "Enter ID for the User: ";
        getline(cin, ID);
        if (IDexists(ID))
        {
            cout << "ID already exists! Choose another ID: ";
            getline(cin, ID);
        }
        cout << "Choose password for the user: ";
        getline(cin, pw);
        pw = log.hashpw(pw);
        fstream add;
        add.open("users.txt", ios::app);
        add << ID << " " << pw << endl;
        add.close();
    }
    void showMenu()
    {
        cout << "Press 1 for assigning task, 2 for viewing task, 3 for delegating task, 4 for sending messages, 5 for recieving messages ";
       cout << "6 to Send global messages, 7 for performance reports , 8 to Hire a user, 9 to Exit " << endl;
    }
    void sendGlobalMsg()
    {
        int msgtype;
        cout << "Press \n1 to Send Alert, 2 to Send Emergency Message, 3 to Send Warning, 4 to Exit: ";
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
        cout << "Press blah blah" << endl;   
    }
};
void executivefunc(string ID);
