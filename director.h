#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "employee.h"
#include "classes.h"
#include "executive.h"
using namespace std;
class Director: public HigherUp{
    public:
    Director(string id)
    {
        emp_id = id;
        grade = 3;
    }
    void showmenu()
    {
       cout << "Press 1 for assigning task, 2 for viewing task, 3 for delegating task, 4 for sending messages, 5 for recieving messages ";
       cout << "6 to Send global messages, 7 for performance reports , 8 to exit " << endl;
    }
};
void directorfunc(string ID);
