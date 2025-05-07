#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include "classes.h"
using namespace std;
class Employee {
    protected:
    string emp_id;
    string pw;
    int grade;
    Message* msg;
    Task* task;
    PolicyEngine allowed;
    Audit audit;
    
    public:
    Employee(){
        task = new Task;
        msg = new Message;
        cout << "Constructor called " << endl;
    }
    void sendmsg()
    {
        grade = 1;
        int msgtostring;
        string msgtype;
        string T_id;
        int Tgrade;
        cout << "Enter grade of recipient: ";
        cin >> Tgrade;
        cout << "Enter ID of recipient: ";
        cin.ignore();
        getline(cin, T_id);
        cout << "Press 1 for PRIVATE, 2 for INFO, 3 for ALERT, 4 for WARNING : ";
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

        if (allowed.canSendMessage(grade, Tgrade, msgtype))
        {
              msg->sendmsg(emp_id, T_id, msgtype);
        }
        
    }
    void receivemsg()
    {}
    void CreateTask()
    {
        
        grade = 1;// for my ease, iski assignment you will do once you update the data in users.txt
        char target;
        cout << "Enter the grade of the person you want to Assign a Task to: ";
        cin >> target;
        if (allowed.can_assign(grade, target))
        {
            if (!task)
            task = new Task; //dynamically allocating space for a new task
            task->appendtask(emp_id);
        }
    }
    void delegate_task()
    {
        grade = 1;; // for my ease, iski assignment you will do once you update the data in users.txt
        int target;
        cout << "Enter the grade of the person you want to Delegate a Task to: ";
        cin >> target;
        if (allowed.can_delegate(grade, target))
        {
            cout << "Access Permitted! \n";
            if (!task)
            {
                delete task; //recheck any memory issue here
            }
            task = new Task; //dynamically allocating space for a new task
            task->delegateTask(emp_id);
        }
    }
    void displayTask()
    {
        if (!task)
        {
            delete task; //recheck any memory issue here
        }
        task = new Task;
         task->displayTask(emp_id);
    }
    void Login();
    string hashpw();
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
