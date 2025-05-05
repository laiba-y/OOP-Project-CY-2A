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
    public: 
    void showMenu()
    {
        cout << "Press blah blah" << endl;   
    }
    void sendGlobalMsg()
    {
        int msgtype;
        cout << "Press \n1 to Send Alert, 2 to Send Emergency Message, 3 to Send Warning, 4 to Exit: ";
        cin >> msgtype;
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
    void showmenu()
    {
        cout << "Press blah blah" << endl;   
    }
};
void executivefunc(string ID);
