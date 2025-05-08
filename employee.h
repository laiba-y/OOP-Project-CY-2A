#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "classes.h"
using namespace std;

class Employee
{
protected:
    string emp_id;
    string pw;
    int grade;
    Message *msg;
    Task *task;
    PolicyEngine allowed;
    Audit audit;
    Tracker report;

public:
    Employee()
    {
        task = new Task;
        msg = new Message;
        cout << "--------------------------------- GLOBAL MESSAGES FROM HIGHER UPS --------------------------------------\n\n";
        ifstream notif;
        notif.open("global.txt");
        string message;
        while (getline(notif, message, '\n'))
        {
            cout << message << endl;
        }
        cout << " ********************************************************************************" << endl << endl;
    }
    bool IDexists(string emp_id)
    {
        string id, password;
        bool found = false;
        ifstream check;
        check.open("users.txt");
        while (getline(check, id, ' '))
        {
            getline(check, password, '\n');
            if (id == emp_id)
            {
            found = true;
            break;
            }
        }
        return found;
    }
    void showperformance(string emp_id)
    {
        cout << ".................................... REPORT " << emp_id << " ...................................." << endl << endl;
        
        cout << "PERFORMANCE CRITERIA :  \n1) COMPLETING TASKS +10           2) EXPIRING TASK -10             3) SENDING MESSAGE +2\n";
        cout << "FOR HIGHER UPS:           4) SEND GLOBAL NOTIFICATION +3    5) HIRE A NEW USER +20       " << endl;
        report.setid(emp_id);
        cout << "DEFAULT SCORE : 100" << endl;
        cout << report ;
        
    }
    void sendmsg()
    {
        int msgtostring;
        string msgtype;
        string T_id;
        int Tgrade;
        cout << "Enter grade of recipient (1-4): ";
        cin >> Tgrade;
        while (Tgrade < 1 or Tgrade > 4)
        {
            cout << "Invalid grade, try again in the range : ";
            cin >> Tgrade;
        }
        cout << "Enter ID of recipient: ";
        cin.ignore();
        getline(cin, T_id);
        if (!IDexists(T_id))
        {
            cout << "ID does not exist, please choose another user: ";
            getline(cin, T_id);
        }
        cout << "Press \n1. PRIVATE  \n2. INFO \n3. ALERT \n4. WARNING \nENTER HERE: ";
        cin >> msgtostring;

        while (msgtostring < 1 or msgtostring > 4)
        {
            cout << "Invalid Option, Try again: ";
            cin >> msgtostring;
        }

        if (msgtostring == 1)
            msgtype = "PRIVATE";
        else if (msgtostring == 2)
            msgtype = "INFO";
        else if (msgtostring == 3)
            msgtype = "ALERT";
        else
            msgtype = "WARNING";

        if (allowed.canSendMessage(grade, Tgrade, msgtype)) //checking permission
        {
            msg->sendmsg(emp_id, T_id, msgtype);
        }
        else
        {
            cout << "Permission denied! " << endl;
        }
    }
    void receivemsg()
    {
        if (!msg)
        {
            delete msg;
            msg = new Message;
        }
        msg->receivemsg(emp_id);
    }
    void CreateTask()
    {
        string T_ID;
        int target;
        cout << "Enter the grade of ASSIGNEE (1 - 4): ";
        cin >> target;
        while (target < 1 or target > 4)
        {
            cout << "Grade doesnt exist, Try again: ";
            cin >> target;
        }
        if (allowed.can_assign(grade, target))
        {
            cout << "Access permitted!\nEnter the ASSIGNEE ID: ";
            cin.ignore();
            std::getline(cin, T_ID);
            if (!IDexists(T_ID))
        {
            cout << "ID does not exist, please choose another user: ";
            getline(cin, T_ID);
        }
            if (!task)
                task = new Task; // dynamically allocating space for a new task
            task->appendtask(emp_id, T_ID);
        }
        else
        {
            cout << "Permission denied! " << endl;
        }
    }
    void delegate_task()
    {
        string T_ID;
        int target;
        cout << "Enter the grade of DELEGATED ASSIGNEE :  ";
        cin >> target;

        while (target < 1 or target > 4)
        {
            cout << "Grade doesnt exist, Try again: ";
            cin >> target;
        }

        if (allowed.can_delegate(grade, target))
        { 
            cout << "Access Permitted! \n";
            if (!task)
            {
                delete task;
            }
            task = new Task; // dynamically allocating space for a new task
            task->delegateTask(emp_id);
        }
        else
        {
            cout << " PERMISSION DENIED! " << endl;
        }
    }
    void displayTask()
    {
        if (!task)
        {
            delete task;
        }
        task = new Task;
        task->displayTask(emp_id);
    }
    virtual void showMenu() = 0;
    ~Employee()
    {
        if (!task)
        {
            delete task;
        }
        if (!msg)
        {
            delete msg;
        }
    }
};
