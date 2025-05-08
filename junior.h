#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "employee.h"
using namespace std;
class Junior : public Employee
{
private:
public:
    Junior(string id)
    {
        emp_id = id;
        grade = 1;
    }
    void showMenu()
    {
        cout << "-------------------------------------------------- DASH BOARD -------------------------------------------------------------";
        cout << "\nPress \n1. VIEW TASKS \n2. DELEGATE TASKS \n3. SEND MESSAGE \n4. VIEW MESSAGES \n5. VIEW YOUR PERFORMANCE REPORT \n6. EXIT : \n";
    }
};
void juniorfunc(string ID);
