#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Login {
    string username;
    string input_pw;
    string hashed_input_pw;
    bool success;

public:
    Login(string user, string pw) : username(user), input_pw(pw), success(false) {
        hashed_input_pw = hashpw(pw);
        checkCredentials();
    }

    bool isSuccess() const { return success; }

private:
    string hashpw(string pw) {
    string hash = "";
    for (int i = 0; i < pw.length(); i++) {
        char shifted = pw[i] + 3;  // Shift character 3 positions forward
        hash += shifted;
    }
    return hash;
}

    void checkCredentials() {
        ifstream fin("users.txt");
        string user, hash_pw;

        while (fin >> user >> hash_pw) {
            if (user == username && hash_pw == hashed_input_pw) {
                success = true;
                break;
            }
        }

        fin.close();
        Audit::logAction(username, "LOGIN", success ? "SUCCESS" : "FAILURE");
    }
};

    //credentials in users.txt
   // Username	Hashed Password	Original Password
   // alice	    sdvv456	         pass123
   // bob       vxvvg	         sussd
   // admin	    dplq456     	 amin123
    
    //users.txt file format
    //alice sdvv456     //name and hashed pw with a space in between
    //bob vxvvg
    //admin dplq456


class PolicyEngine {   //abhi i will ad more conditions in it 
public:
    // Delegation rule
    static bool can_delegate(int from_clearance, int to_clearance) {    // is allowed ki jagah i have made seperate functions for msg, delegation etc
        return from_clearance <= to_clearance;
    }

    // Messaging rule
    static bool canSendMessage(int senderClearance, int recipientClearance, string type) {
        if (type == "PRIVATE")
            return true; // Anyone can send private messages up

        if (type == "ALERT")
            return senderClearance >= 3 && recipientClearance >= 3;

        if (type == "INFO")
            return true;

        if (type == "WARNING" || type == "EMERGENCY")
            return senderClearance >= 2; // Manager and Executive only

        return false;
    }
};

class Time {
public:
    static bool checkExpiry(time_t creationTime, int ttlSeconds) {
        time_t now = time(0);
        return difftime(now, creationTime) >= ttlSeconds;
    }
};

class Audit {
public:
    static void logAction(const string& username, const string& action, const string& status) {
        ofstream fout("audit.txt", ios::app);
        if (!fout) {
            cerr << "Error opening audit log file." << endl;
            return;
        }

        time_t now = time(0);
        string timestamp = string(ctime(&now)); // Convert to std::string

        // if i dont do this to aadhi line next line mein ati hai bec ctime(&now) automatically nextline add kardeta hai at the end
        if (timestamp.length() > 0 && timestamp[timestamp.length() - 1] == '\n') {
            timestamp = timestamp.substr(0, timestamp.length() - 1);  //this function will remover \n taakay aik pura sentence aye aik line mein 
        }

        fout << "[" << timestamp << "] " << username << " " << action << " " << status << "\n";
        fout.close();
    }
};
      //audit.txt foramt
      //[Tue May 06 00:51:29 2025] ali LOGIN FAILURE
      //[Tue May 06 00:51:29 2025] ali LOGIN FAILURE
      //[Tue May 06 00:52:23 2025] ali LOGIN FAILURE
      //[Tue May 06 00:52:23 2025] ali LOGIN FAILURE

class Global
{
private:
    string alert;
    string warning;
    string emergency;

public:
    void sendAlert()
    {
        cout << "Enter message here: ";
        getline(cin, alert);
        fstream o;
        o.open("global.txt", ios::app);
        o << "ALERT FROM HIGHER-UPS : " << alert << endl;
        o.close();
        cout << "Alert added!" << endl;
    }
    void sendEmergency()
    {
        cout << "Enter message here: ";
        getline(cin, emergency);
        fstream o;
        o.open("global.txt", ios::app);
        o << "EMERGENCY FROM HIGHER-UPS : " << emergency << endl;
        o.close();
        cout << "Emergency declared!" << endl;
    }
    void sendWarning()
    {
        cout << "Enter message here: ";
        getline(cin, warning);
        fstream o;
        o.open("global.txt", ios::app);
        o << "WARNING FROM HIGHER-UPS : " << alert << endl;
        o.close();
        cout << "Warning announced!" << endl;
    }
};
class Date
{
};

class Message
{
};
class Task
{
    int TaskID;
    string task;
    string T_ID; // I added this extra member for noting down the ID of the target member
    string status;
    char priority;
    Date date;
    Time time;

public:
    void appendtask(string emp_id) // jo user task assign kar raha hai uski ID in parameter so I can note it in the file
    {

        cin.ignore();
        cout << "Access permitted!\nEnter the Receiver's ID: ";
        std::getline(cin, T_ID); // I will check yahan par ke given ID exist karti hai ya nahi by going through users.txt, first I will notice how you write in that file uske hisaab se ill make a logic for the file handling

        cout << "Type the Task: ";
        std::getline(cin, task); // taking the task

        cout << "Enter priority (H/M/L): ";
        cin >> priority;

        cout << "Enter task ID: ";
        cin >> TaskID;
        if (priority == 'L') // making sure the higher priority tasks stay up in the file
        {
            fstream note;
            note.open("tasks.txt", ios::app);
            note << task << "|" << T_ID << "|" << emp_id << "|" << priority << "|" << TaskID << "|" << "Assigned" << endl;
            note.close();
            // deadline ki input kis format mai hogi wo bata dena and le lena yahan par
            //  pehle goes the task in the file then the target id then the sender id phir priority and then taskID and then deadline which I didnt add yet and then status
            //  I will use this sequence for when im reading and displaying from the file, pehle bar tak read kar ke task phenk dungi then so on
            //  baki saare status update karna meri zimmedaari hai but you have to come up with the logic of "expired" wala because you're dealing with deadlines
            //  to once wo ban jaaye you can make a function of "isexpired" wahan se mai check kar ke expire kar dungi task ko
            cout << "Task Assigned!\n"
                 << endl;
        }
        else
        {
            char tasks[10][50], users[10][5], assignee[10][5], priorities[10], tid[10][5], status[10][15];
            int i = 0;
            ifstream note;
            note.open("tasks.txt", ios::in);
            while (note.getline(tasks[i], 50, '|'))
            {
                note.getline(users[i], 5, '|');
                note.getline(assignee[i], 5, '|');
                note >> priorities[i];
                note.getline(tid[i], 5, '|');
                note.getline(tid[i], 5, '|');
                note.getline(status[i], 15, '\n');
                i++;
            }
            note.close();
            // appending higher priority tasks first
            ofstream app;
            app.open("tasks.txt");
            if (priority == 'H')
            {
                app << task << "|" << T_ID << "|" << emp_id << "|" << priority << "|" << TaskID << "|" << "Assigned" << endl;
            }
            for (int j = 0; j < i; j++)
            {
                if (priorities[j] == 'H')
                {
                    app << tasks[j] << "|" << users[j] << "|" << assignee[j] << "|" << priorities[j] << "|" << tid[j] << "|" << status[j] << endl;
                }
            }
            // appending medium priority tasks
            if (priority == 'M')
            {
                app << task << "|" << T_ID << "|" << emp_id << "|" << priority << "|" << TaskID << "|" << "Assigned" << endl;
            }
            for (int j = 0; j < i; j++)
            {
                if (priorities[j] == 'M')
                {
                    app << tasks[j] << "|" << users[j] << "|" << assignee[j] << "|" << priorities[j] << "|" << tid[j] << "|" << status[j] << endl;
                }
            }
            for (int j = 0; j < i; j++)
            {
                if (priorities[j] == 'L')
                {
                    app << tasks[j] << "|" << users[j] << "|" << assignee[j] << "|" << priorities[j] << "|" << tid[j] << "|" << status[j] << endl;
                }
            }
        }
    }
    void displayTask(string emp_id)
    {
        cout << " ------------------- TASKS ----------------------\n";
        char task[50], user[5], assignee[5], status[15], priority[2], tid[5], trash[70];
        bool hastask = false;
        ifstream note;
        note.open("tasks.txt");
        while (note.getline(task, 50, '|'))
        {
            note.getline(user, 5, '|');
            if (user == emp_id)
            {
                hastask = true;
                note.getline(assignee, 5, '|');
                note.getline(priority, 2, '|');
                note.getline(tid, 5, '|');
                note.getline(status, 15, '\n');
                cout << "Task " << tid << " : " << task << endl;
                cout << "Assigned by : " << assignee << "    Priority: " << priority << "     Status: " << status << endl
                     << endl;
            }
            else
            {
                note.getline(trash, 70, '\n');
                continue;
            }
        }
        note.close();
        if (!hastask)
        {
            cout << "No pending tasks right now " << endl;
        }
        else
        {
            int option, taskComp;
            char test;
            cout << "Press 1 to Start working on task, 2 to Exit";
            cin >> option;
            if (option == 1)
            {
                cout << "Enter task ID: ";
                cin >> taskComp;
                cout << "Press 'Y' to complete task : ";
                cin >> test;
                if (test == 'Y')
                {
                    cout << "Task Completed!" << endl;
                    //call update function here
                }
                else
                {
                    cout << "Task failed! " << endl;
                }
            }
        }
    }
    void delegateTask(string emp_id)
    {
        char takeID[5], giveID[5], specificID[5];
        ;
        cout << "Enter the ID of Role you want to delegate the task FROM : ";
        cin.ignore();
        cin.getline(takeID, 5, '\n');
        cout << "Enter the ID of Role you want to delegate task TO : ";
        cin.getline(giveID, 5, '\n');

        cout << "-------------- CHOOSE THE TASK ID TO BE DELEGATED TO OTHER USER -------------\n";
        displayTask(takeID);
        cout << "Enter the TASK ID: ";
        cin.getline(specificID, 5, '\n');
        cout << "----" << specificID << endl;
        char tasks[10][50], users[10][5], assignee[10][5], priorities[10], tid[10][5], status[10][15];
        int i = 0;
        ifstream note;
        note.open("tasks.txt", ios::in);
        while (note.getline(tasks[i], 50, '|'))
        {
            note.getline(users[i], 5, '|');
            note.getline(assignee[i], 5, '|');
            note >> priorities[i];
            note.getline(tid[i], 5, '|');
            note.getline(tid[i], 5, '|');
            note.getline(status[i], 15, '\n');
            i++;
        }
        note.close();

        for (int j = 0; j < i; j++)
        {
            if (!strcmp(tid[j], specificID))
            {
                strcpy(users[j], giveID);
                strcpy(status[j], "Delegated");
            }
        }

        ofstream app;
        app.open("tasks.txt");
        for (int k = 0; k < i; k++)
        {
            app << tasks[k] << "|" << users[k] << "|" << assignee[k] << "|" << priorities[k] << "|" << tid[k] << "|" << status[k] << endl;
        }
    }
};


// class Employee {
//     protected:
//     string emp_id;
//     string pw;
//     char grade;
//     Message* msg;
//     Task* task;
//     PolicyEngine allowed;
//     Audit audit;

//     public:
//     void sendmsg();
//     void receivemsg();
//     void CreateTask()
//     {

//         grade = 'M'; // for my ease, iski assignment you will do once you update the data in users.txt
//         char target;
//         cout << "Enter the grade of the person you want to Assign a Task to: ";
//         cin >> target;
//         if (allowed.isAllowed(grade, target))
//         {
//             task = new Task; //dynamically allocating space for a new task
//             task->appendtask("M5");
//         }
//     }
//     void delegate_task()
//     {
//         grade = 'M'; // for my ease, iski assignment you will do once you update the data in users.txt
//         char target;
//         cout << "Enter the grade of the person you want to Delegate a Task to: ";
//         cin >> target;
//         if (allowed.isAllowed(grade, target))
//         {
//             cout << "Access Permitted! \n";
//             if (!task)
//             {
//                 delete task; //recheck any memory issue here
//             }
//             task = new Task; //dynamically allocating space for a new task
//             task->delegateTask("M2");
//         }
//     }
//     void displayTask()
//     {
//         if (!task)
//         {
//             delete task; //recheck any memory issue here
//         }
//         task = new Task;
//          task->displayTask("J6");
//     }
//     void Login();
//     string hashpw();
//     virtual void showMenu() = 0;
//     ~Employee()
//     {
//         delete task;
//     }
//     };
