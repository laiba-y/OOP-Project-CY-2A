#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "employee.h"
using namespace std;
class Manager : public Employee{
    private:

    public:
    Manager(string id) {
        emp_id = id;
    } 
    void showMenu()
    {
        cout << "------------------------ MENU --------------------------------";
        cout << "\nPRess 1 for assigning tasks, 2 for viewing tasks, 3 for delegating tasks, 4 for sending messages, 5 for recieving messages, 6 to check Perfomance Reports, 7 to Exit : \n";  // I am making a very rough sa main right now, jab sab hojayega phir I will add decorations and shit
    }
};
void managerfunc(string ID);
