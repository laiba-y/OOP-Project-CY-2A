#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "employee.h"
using namespace std;
class Manager : public Employee
{
private:
public:
    Manager(string id)
    {
        emp_id = id;
        grade = 2; // clearance level
    }
    void showMenu()
    {

        cout << BMAGENTA;
        cout << "╔════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                                        DASH BOARD                                                  ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
        cout << RESET;

        // Options Box
        cout << BCYAN;
        cout << "╔════════════════════════════════════════════════════════════╗\n";
        cout << "║ Press                                                      ║\n";
        cout << "║ 1. ASSIGN TASKS                                            ║\n";
        cout << "║ 2. VIEW TASKS                                              ║\n";
        cout << "║ 3. DELEGATE TASKS                                          ║\n";
        cout << "║ 4. SEND MESSAGES                                           ║\n";
        cout << "║ 5. VIEW MESSAGES                                           ║\n";
        cout << "║ 6. CHECK PERFORMANCE REPORT                                ║\n";
        cout << "║ 7. EXIT                                                    ║\n";
        cout << "╚════════════════════════════════════════════════════════════╝\n";
        cout << RESET;
        cout << YELLOW << "ENTER HERE : " << RESET;
    }
};
void managerfunc(string ID);
