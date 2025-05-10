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
    void showMenu() override
    {
        cout << BMAGENTA;
        cout << "╔════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                        DASH BOARD                                                  ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << RESET;

        // Options Box
        cout << BCYAN;
        cout << "╔════════════════════════════════════════════════════╗\n";
        cout << "║ Press                                              ║\n";
        cout << "║ 1. VIEW TASKS                                      ║\n";
        cout << "║ 2. DELEGATE TASKS                                  ║\n";
        cout << "║ 3. SEND MESSAGE                                    ║\n";
        cout << "║ 4. VIEW MESSAGES                                   ║\n";
        cout << "║ 5. VIEW YOUR PERFORMANCE REPORT                    ║\n";
        cout << "║ 6. EXIT                                            ║\n";
        cout << "╚════════════════════════════════════════════════════╝\n";
        cout << RESET;
        cout << YELLOW << "ENTER HERE : " << RESET;
    }
};
void juniorfunc(string ID);
