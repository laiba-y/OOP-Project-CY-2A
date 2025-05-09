#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "employee.h"
#include "classes.h"
#include "executive.h"
using namespace std;
class Director : public HigherUp
{
public:
    Director(string id)
    {
        emp_id = id;
        grade = 3;
    }
    void showmenu()
    {
    }
};
void directorfunc(string ID);
