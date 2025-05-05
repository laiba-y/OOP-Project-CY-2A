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
    char grade;
    Message* msg;
    Task* task;
    PolicyEngine allowed;
    Audit audit;
    
    public:
    void sendmsg()
    {}
    void receivemsg()
    {}
    void CreateTask()
    {
        
        grade = 'M'; // for my ease, iski assignment you will do once you update the data in users.txt
        char target;
        cout << "Enter the grade of the person you want to Assign a Task to: ";
        cin >> target;
        if (allowed.isAllowed(grade, target))
        {
            task = new Task; //dynamically allocating space for a new task
            task->appendtask("M5");
        }
    }
    void delegate_task()
    {
        grade = 'M'; // for my ease, iski assignment you will do once you update the data in users.txt
        char target;
        cout << "Enter the grade of the person you want to Delegate a Task to: ";
        cin >> target;
        if (allowed.isAllowed(grade, target))
        {
            cout << "Access Permitted! \n";
            if (!task)
            {
                delete task; //recheck any memory issue here
            }
            task = new Task; //dynamically allocating space for a new task
            task->delegateTask("M2");
        }
    }
    void displayTask()
    {
        if (!task)
        {
            delete task; //recheck any memory issue here
        }
        task = new Task;
         task->displayTask("J6");
    }
    void Login();
    string hashpw();
    virtual void showMenu() = 0;
    ~Employee()
    {
        delete task;
    }
    };
