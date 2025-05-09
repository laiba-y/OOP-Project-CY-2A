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
        system("clear");
        task = new Task;
        msg = new Message;
        cout << BMAGENTA;
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                       GLOBAL MESSAGES FROM HIGHER UPS                                    ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << RESET;
        ifstream notif;
        notif.open("global.txt");
        string message;
        while (getline(notif, message, '\n'))
        {
            cout << BCYAN << message << endl << RESET;
        }
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
        cout << BMAGENTA << "\n╔══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                     PERFORMANCE REPORT - " << emp_id << "                          ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════╝\n" << RESET;

    cout << BCYAN<< "\n╔══════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                  PERFORMANCE CRITERIA (SCORE SYSTEM)                 ║\n";
    cout << "╠══════════════════════════════════════════════════════════════════════╣\n";
    cout << "║ 1) Completing Tasks:        +10      | 2) Expired Task:        -10   ║\n";
    cout << "║ 3) Sending Message:         +2       | 4) Global Notification: +3    ║\n";
    cout << "║ 5) Hire New User:           +20                                      ║\n";
    cout << "╚══════════════════════════════════════════════════════════════════════╝\n" << RESET;
        report.setid(emp_id);
        cout << YELLOW << "DEFAULT SCORE : 100" << endl << RESET;
        cout << report ;
        
    }
    void sendmsg()
    {
        int msgtostring;
        string msgtype;
        string T_id;
        int Tgrade;
        cout << BCYAN;
    cout << "╔════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                  ACCESS STOP                                       ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << RESET;
    cout << "\n";
        cout << YELLOW << "Enter grade of recipient (1-4): ";
        cin >> Tgrade;
        while (Tgrade < 1 or Tgrade > 4)
        {
            cout << RESET << RED << "Invalid grade, try again in the range : ";
            cin >> Tgrade;
        }
        cout << YELLOW << "Enter ID of recipient: " << RESET;
        cin.ignore();
        getline(cin, T_id);
        if (!IDexists(T_id))
        {
            cout << RED << "ID does not exist, please choose another user: " << RESET;
            getline(cin, T_id);
        }
        cout << YELLOW << "Press \n1. PRIVATE  \n2. INFO \n3. ALERT \n4. WARNING \nENTER HERE: " << RESET;
        cin >> msgtostring;

        while (msgtostring < 1 or msgtostring > 4)
        {
            cout << RED << "Invalid Option, Try again: " << RESET;
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
            cout << GREEN;
    cout << "╔════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                  ACCESS PERMITTED                                  ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << RESET;
            msg->sendmsg(emp_id, T_id, msgtype);
        }
        else
        {
            cout << RED;
            cout << "╔════════════════════════════════════════════════════════════════════════════════════╗\n";
            cout << "║                                  ACCESS DENIED                                     ║\n";
            cout << "╚════════════════════════════════════════════════════════════════════════════════════╝\n";
            cout << RESET;
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
        cout << BCYAN;
        cout << "╔════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                  ACCESS STOP                                       ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << RESET;
        cout << "\n";
        cout << YELLOW << "Enter the grade of ASSIGNEE (1 - 4): ";
        cin >> target;
        while (target < 1 or target > 4)
        {
            cout << RESET << RED << "Grade doesnt exist, Try again: ";
            cin >> target;
        }
        if (allowed.can_assign(grade, target))
        {
            
            cout << GREEN;
    cout << "╔════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                                  ACCESS PERMITTED                                  ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════════════╝\n";
    cout << RESET;
            cout << RESET << YELLOW << "Enter the ASSIGNEE ID: ";
            cin.ignore();
            std::getline(cin, T_ID);
            if (!IDexists(T_ID))
        {
            cout << RESET << RED << "ID does not exist, please choose another user: ";
            getline(cin, T_ID);
        }
            if (!task)
                task = new Task; // dynamically allocating space for a new task
            task->appendtask(emp_id, T_ID);
        }
        else
        {
            cout << RED;
            cout << "╔════════════════════════════════════════════════════════════════════════════════════╗\n";
            cout << "║                                  ACCESS DENIED                                     ║\n";
            cout << "╚════════════════════════════════════════════════════════════════════════════════════╝\n";
            cout << RESET;
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
