#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "employee.h"
using namespace std;
class Junior : public Employee{
    private:

    public:
    Junior(string id){
        emp_id = id;
        grade = 1;
    }
    void showMenu()
    {
        cout << "------------------------ MENU --------------------------------";
        cout << "\nPRess 1 for viewing tasks, 2 for delegating tasks, 3 sending messages, 4 viewing messages, 5 viewing your perfomance report, 6 to exit : \n";  // I am making a very rough sa main right now, jab sab hojayega phir I will add decorations and shit
    }
};
void juniorfunc(string ID);
