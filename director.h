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
    void showmenu()
    {
       cout << "Press blah blah" << endl;
    }
};
void directorfunc(string ID);

