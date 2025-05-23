
#pragma once
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Bright versions
#define BRED "\033[1;31m"
#define BGREEN "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE "\033[1;34m"
#define BMAGENTA "\033[1;35m"
#define BCYAN "\033[1;36m"
#define BWHITE "\033[1;37m"

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "employee.h"
using namespace std;

class Global
{
private:
    string alert;
    string warning;
    string emergency;

public:
    void sendAlert()
    {
        cout << BCYAN "\n╔══════════════════════════════╗\n";
        cout << "║         SEND ALERT           ║\n";
        cout << "╚══════════════════════════════╝\n"
             << RESET;
        cout << YELLOW << "Enter message here: " << RESET;
        getline(cin, alert);
        fstream o;
        o.open("global.txt", ios::app);
        o << "ALERT : " << alert << endl;
        o.close();
        cout << GREEN << "Alert ADDED!" << endl
             << RESET;
             
    }
    void sendEmergency()
    {
        cout << BCYAN << "\n╔══════════════════════════════╗\n";
        cout << "║         SEND EMERGENCY       ║\n";
        cout << "╚══════════════════════════════╝\n"
             << RESET;
        cout << YELLOW << "Enter message here: " << RESET;
        getline(cin, emergency);
        fstream o;
        o.open("global.txt", ios::app);
        o << "EMERGENCY : " << emergency << endl;
        o.close();
        cout << GREEN << "Emergency DECLARED!" << endl
             << RESET;
    }
    void sendWarning()
    {
        cout << BCYAN << "\n╔══════════════════════════════╗\n";
        cout << "║         SEND WARNING         ║\n";
        cout << "╚══════════════════════════════╝\n"
             << RESET;
        cout << YELLOW << "Enter message here: " << RESET;
        getline(cin, warning);
        fstream o;
        o.open("global.txt", ios::app);
        o << "WARNING : " << alert << endl;
        o.close();
        cout << GREEN << "Warning ANNOUNCED!" << endl
             << RESET;
    }
};

class Tracker
{
private:
    int score;
    string id;

public:
    Tracker() : score(100) {}

    void addscore(string findID, int add = 10)
    {
        string ID[10];
        int ach[10];
        bool found = false;
        ifstream scores("reports.txt");
        if (!scores)
        {
            cout << "Error opening reports.txt" << endl;
            return;
        }

        int i = 0;
        while (scores >> ID[i] >> ach[i] && i < 10)
        {
            i++;
        }

        scores.close();

        for (int j = 0; j < i; j++)
        {
            if (ID[j] == findID)
            {
                found = true;
                score = ach[j] + add;
                ach[j] += add; // Add the achievement score
                cout << RESET << GREEN << "\n╔══════════════════════════════╗\n";
                cout << "║        SCORE UPDATED         ║\n";
                cout << "╚══════════════════════════════╝\n"
                     << RESET;
                break;
            }
        }
        scores.close();
        if (!found)
            cout << RESET << RED << "ID not found. Score unchanged." << endl
                 << RESET;
        else
        {
            ofstream app;
            app.open("reports.txt");
            for (int k = 0; k < i; k++)
            {
                app << ID[k] << " " << ach[k] << endl;
            }
            app.close();
        }
    }

    void subtractscore(string findID)
    {
        bool foundid = false;
        string ID[10];
        int ach[10];
        fstream scores("reports.txt", ios::in);
        if (!scores)
        {
            cout << "Error opening reports.txt" << endl;
            return;
        }

        int i = 0;
        while (scores >> ID[i] >> ach[i] && i < 10)
        {
            scores.get();
            i++;
        }

        scores.close();
        scores.open("reports.txt", ios::out);
        for (int j = 0; j < i; j++)
        {
            if (ID[j] == findID)
            {
                foundid = true;
                score = ach[j] - 10; // Subtract the achievement score
                ach[j] -= 10;
                if (score < 0)
                {
                    score = 0;
                    ach[j] = 0;
                }
            }
            scores << ID[j] << " " << ach[j] << endl;
        }
        if (!foundid)
        cout << "ID not found. Score unchanged." << endl;
    }
    void setid(string emp_id)
    {
        id = emp_id;
    }
    int getScore() const
    {
        return score;
    }
    friend ostream &operator<<(ostream &o, const Tracker &report)
    {
        string checkID;
        int score;
        ifstream in;
        in.open("reports.txt");
        while (getline(in, checkID, ' '))
        {
            in >> score;
            in.get();
            if (checkID == report.id)
            {
                cout << GREEN << "OBTAINED SCORE  : " << score << endl
                     << RESET;
            }
        }
        return o;
    }
    // operator overloading
    void operator+=(int num)
    {
        string ID[10];
        int ach[10];
        ifstream scores("reports.txt");
        if (!scores)
        {
            cout << "Error opening reports.txt" << endl;
            return;
        }

        int i = 0;
        while (scores >> ID[i] >> ach[i] && i < 10)
        {
            i++;
        }

        scores.close();
        for (int j = 0; j < i; j++)
        {
            if (ID[j] == id)
            {
                score = ach[j] - 10; // Subtract the achievement score
                ach[j] -= 10;
                if (score < 0)
                {
                    score = 0;
                    ach[j] = 0;
                }
                cout << RESET << GREEN << "\n╔══════════════════════════════╗\n";
                cout << "║        SCORE UPDATED         ║\n";
                cout << "╚══════════════════════════════╝\n"
                     << RESET;
                return;
            }
        }

        cout << "ID not found. Score unchanged." << endl;
    }
};
class Audit
{
public:
    static void logAction(const string &username, const string &action, const string &status)
    {
        ofstream fout("audit.txt", ios::app);
        if (!fout)
        {
            cerr << "Error opening audit log file." << endl;
            return;
        }

        time_t now = time(0);
        string timestamp = string(ctime(&now)); // Convert to std::string

        // if i dont do this to aadhi line next line mein ati hai bec ctime(&now) automatically nextline add kardeta hai at the end
        if (timestamp.length() > 0 && timestamp[timestamp.length() - 1] == '\n')
        {
            timestamp = timestamp.substr(0, timestamp.length() - 1); // this function will remover \n taakay aik pura sentence aye aik line mein
        }

        fout << "[" << timestamp << "] " << username << " " << action << " " << status << "\n";
        fout.close();
    }
    friend std::ostream &operator<<(std::ostream &o, const Audit &other)
    {
        std::ifstream in("audit.txt");
        std::string line;
        while (std::getline(in, line, '\n'))
        {
            o << CYAN << line << '\n'
              << RESET;
        }
        return o;
    }
};
// audit.txt foramt
//[Tue May 06 00:51:29 2025] ali LOGIN FAILURE
//[Tue May 06 00:51:29 2025] ali LOGIN FAILURE
//[Tue May 06 00:52:23 2025] ali LOGIN FAILURE
//[Tue May 06 00:52:23 2025] ali LOGIN FAILURE

class Time_Manager
{
public:
    static bool checkExpiry(time_t creationTime, int ttlSeconds)
    {
        time_t now = time(0);
        return difftime(now, creationTime) >= ttlSeconds;
    }
    int convertToSeconds(int hours, int minutes, int seconds)
    {
        return hours * 3600 + minutes * 60 + seconds;
    }
};
class Message
{
private:
    Tracker report;
    string type;

public:
    void sendmsg(string emp_id, string T_id, string msgtype)
    {
        string msg;
        cout << BCYAN << "\n╔══════════════════════════════╗\n";
        cout << "║         SEND MESSAGE         ║\n";
        cout << "╚══════════════════════════════╝\n"
             << RESET;
        cout << YELLOW << "Enter the message: ";
        cin.ignore();
        getline(cin, msg);
        if (msgtype == "PRIVATE")
            msg = encrypt(msg);

        fstream app;
        app.open("inbox.txt", ios::app);
        app << msg << "|" << T_id << "|" << emp_id << "|" << msgtype << "|" << "Unread" << endl;
        cout << GREEN << "Message Sent! " << endl
             << RESET;
        app.close();
        report.setid(emp_id);
        report += 2;

        Audit::logAction(emp_id, "MESSAGE", "SENT");
    }

    string encrypt(const string &plain)
    {
        string cipher = plain;
        for (size_t i = 0; i < cipher.size(); ++i)
        {
            cipher[i] = cipher[i] + 3;
        }
        return cipher;
    }

    string decrypt(const string &cipher)
    {
        string plain = cipher;
        for (size_t i = 0; i < plain.size(); ++i)
        {
            plain[i] = plain[i] - 3;
        }
        return plain;
    }
    bool operator==(string &compare)
    {
        if (type == compare)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void receivemsg(string emp_id)
    {
        cout << BMAGENTA << "\n╔══════════════════════════════════════════════════╗\n";
        cout << "║                    INBOX                         ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n\n"
             << RESET;
        ifstream in("inbox.txt");
        if (!in)
        {
            std::cerr << "Cannot open file.\n";
            return;
        }

        std::string line;
        while (std::getline(in, line))
        {
            std::stringstream ss(line);
            std::string message, receiver, sender, msgType, status;
            std::getline(ss, message, '|');
            std::getline(ss, receiver, '|');
            std::getline(ss, sender, '|');
            std::getline(ss, msgType, '|');
            std::getline(ss, status, '|');

            if (receiver == emp_id && status == "Unread") // only showing unread messages
            {
                // Decrypt if the message is PRIVATE
                if (msgType == "PRIVATE")
                {
                    message = decrypt(message);
                }
                std::cout << BCYAN << "╔══════════════════════════════════╗\n";
                cout << " Message:  " << message << "\n";
                cout << " Sender:   " << sender << "\n";
                cout << " Type:     " << msgType << "\n";
                cout << " Status:   " << status << "\n";
                cout << "╚══════════════════════════════════╝\n\n"
                     << RESET;
            }
        }

        in.close();
    }
};
class Task
{
    int TaskID;
    string task;
    string T_ID; // I added this extra member for noting down the ID of the target member
    string status;
    char priority;
    Time_Manager Time;
    Tracker report;

public:
    void Expired(int index = 0)
    {
        string task, emp, sender, status, priority;
        char taskid[10];
        time_t create;
        int ttl;
        ifstream in;
        in.open("tasks.txt");

        string line;
        for (int i = 0; i < index; ++i)
        {
            if (!getline(in, line))
                return; // base case: no more lines
        }

        if (getline(in, task, '|'))
        {
            getline(in, emp, '|');
            getline(in, sender, '|');
            getline(in, priority, '|');
            in.getline(taskid, 10, '|');
            getline(in, status, '|');
            in >> create;
            in >> ttl;
            if (Time.checkExpiry(create, ttl) && status != "Expired")
            {
                Audit::logAction(emp, "TASK", "EXPIRED");
                updatestatus(taskid, "Expired");
                report.subtractscore(emp);
            }
        }
        else
            return;

        return Expired(index + 1);
    }
    void updatestatus(const char *taskComp, const char *newstatus)
    {
        char tasks[10][50];
        char users[10][5];
        char assignee[10][5];
        char priorities[10];
        char tid[10][5];
        char status[10][15];
        time_t catchcreate[10];
        int ttls[10];
        int i = 0;

        std::ifstream note("tasks.txt", std::ios::in);
        if (!note.is_open())
        {
            std::cerr << "Cannot open tasks.txt for reading\n";
            return;
        }

        // Read each record
        while (i < 10 && note.getline(tasks[i], 50, '|'))
        {
            note.getline(users[i], 5, '|');
            note.getline(assignee[i], 5, '|');

            // read single-char priority + delimiter
            note >> priorities[i];
            note.get(); // consume the '|' after priority

            note.getline(tid[i], 5, '|');
            note.getline(status[i], 15, '|');
            note >> catchcreate[i];
            note >> ttls[i];
            note.get();
            i++;
        }
        note.close();

        std::ofstream app("tasks.txt", std::ios::trunc);
        if (!app.is_open())
        {
            std::cerr << "Cannot open tasks.txt for writing\n";
            return;
        }

        // Update matching task and rewrite file
        for (int j = 0; j < i; ++j)
        {
            if (std::strcmp(tid[j], taskComp) == 0)
            {
                // safely copy newstatus into status[j]
                strcpy(status[j], newstatus);
            }
            app
                << tasks[j] << '|'
                << users[j] << '|'
                << assignee[j] << '|'
                << priorities[j] << '|'
                << tid[j] << '|'
                << status[j] << '|' << catchcreate[j] << " " << ttls[j] << endl;
        }
        app.close();
    }

    void DoTask(string emp_id)
    {
        int option;
        char taskComp[5];
        char test;
        cout << BCYAN;
        cout << "╔══════════════════════════════════════╗\n";
        cout << "║              PRESS                   ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║ 1. Start working                     ║\n";
        cout << "║ 2. EXIT                              ║\n";
        cout << "╚══════════════════════════════════════╝\n";
        cout << RESET;

        cout << YELLOW << "ENTER HERE: " << RESET;
        cin >> option;
        cin.ignore();
        if (option == 1)
        {
            cout << YELLOW << "Enter task ID: ";
            cin.getline(taskComp, 5, '\n');
            updatestatus(taskComp, "In Progress");
            cout << YELLOW << "Press 'Y' to complete task : ";
            cin >> test;
            if (test == 'Y')
            {
                cout << RESET << GREEN << "^^^^^^^^TASK COMPLETED^^^^^^^^^^^^" << endl
                     << RESET;
                report.addscore(emp_id);
                updatestatus(taskComp, "Completed");
                Audit::logAction(emp_id, "TASK", "COMPLETED");
            }
            else
            {
                cout << RESET << RED << "Task failed! Try process again... " << endl
                     << RESET;
                report.subtractscore(emp_id);
                updatestatus(taskComp, "In Progress");
                Audit::logAction(emp_id, "TASK", "IN PROGRESS");
            }
        }
    }
    void appendtask(string emp_id, string T_ID) // jo user task assign kar raha hai uski ID in parameter so I can note it in the file
    {
        cout << BMAGENTA << "\n╔══════════════════════════════╗\n";
        cout << "║         TASK MANAGER         ║\n";
        cout << "╚══════════════════════════════╝\n"
             << RESET;
        int hour, minutes, seconds;
        // I will check yahan par ke given ID exist karti hai ya nahi by going through users.txt, first I will notice how you write in that file uske hisaab se ill make a logic for the file handling

        cout << YELLOW << "ENTER TASK: ";
        std::getline(cin, task); // taking the task

        cout << "Enter priority (H/M/L): ";
        cin >> priority;

        cout << "Enter deadline in hours: ";
        cin >> hour;

        cout << "Enter deadline in minutes: ";
        cin >> minutes;

        cout << "Enter deadline in seconds: ";
        cin >> seconds;

        int ttl = Time.convertToSeconds(hour, minutes, seconds);
        time_t create = time(0);
        cout << "Enter task ID: ";
        cin >> TaskID;
        if (priority == 'L') // making sure the higher priority tasks stay up in the file
        {
            fstream note;
            note.open("tasks.txt", ios::app);
            note << task << "|" << T_ID << "|" << emp_id << "|" << priority << "|" << TaskID << "|" << "Assigned" << "|" << create << " " << ttl << endl;
            note.close();
            // deadline ki input kis format mai hogi wo bata dena and le lena yahan par
            //  pehle goes the task in the file then the target id then the sender id phir priority and then taskID and then deadline which I didnt add yet and then status
            //  I will use this sequence for when im reading and displaying from the file, pehle bar tak read kar ke task phenk dungi then so on
            //  baki saare status update karna meri zimmedaari hai but you have to come up with the logic of "expired" wala because you're dealing with deadlines
            //  to once wo ban jaaye you can make a function of "isexpired" wahan se mai check kar ke expire kar dungi task ko
            cout << RESET << GREEN << "^^^^^^^^^^^^^ TASK ASSIGNED ^^^^^^^^^^^^^^^!\n"
                 << endl
                 << RESET;
        }
        else
        {
            char tasks[10][50], users[10][5], assignee[10][5], priorities[10], tid[10][5], status[10][15];
            time_t catchcreate[10];
            int catchttl[10];
            int i = 0;
            ifstream note;
            note.open("tasks.txt", ios::in);
            while (note.getline(tasks[i], 50, '|'))
            {
                note.getline(users[i], 5, '|');
                note.getline(assignee[i], 5, '|');
                note >> priorities[i];
                note.get(); // <— eat the '|' delimiter here
                note.getline(tid[i], 5, '|');
                note.getline(status[i], 15, '|');
                note >> catchcreate[i];
                note >> catchttl[i];
                note.get();//catch \n character
                i++;
            }
            note.close();
            // appending higher priority tasks first
            ofstream app;
            app.open("tasks.txt");
            if (priority == 'H')
            {
                app << task << "|" << T_ID << "|" << emp_id << "|" << priority << "|" << TaskID << "|" << "Assigned" << "|" << create << " " << ttl << endl;
            }
            for (int j = 0; j < i; j++)
            {
                if (priorities[j] == 'H')
                {
                    app << tasks[j] << "|" << users[j] << "|" << assignee[j] << "|" << priorities[j] << "|" << tid[j] << "|" << status[j] << "|" << catchcreate[j] << " " << catchttl[j] << endl;
                }
            }
            // appending medium priority tasks
            if (priority == 'M')
            {
                app << task << "|" << T_ID << "|" << emp_id << "|" << priority << "|" << TaskID << "|" << "Assigned" << "|" << create << " " << ttl << endl;
            }
            for (int j = 0; j < i; j++)
            {
                if (priorities[j] == 'M')
                {
                    app << tasks[j] << "|" << users[j] << "|" << assignee[j] << "|" << priorities[j] << "|" << tid[j] << "|" << status[j] << "|" << catchcreate[j] << " " << catchttl[j] << endl;
                }
            }
            for (int j = 0; j < i; j++)
            {
                if (priorities[j] == 'L')
                {
                    app << tasks[j] << "|" << users[j] << "|" << assignee[j] << "|" << priorities[j] << "|" << tid[j] << "|" << status[j] << "|" << catchcreate[j] << " " << catchttl[j] << endl;
                }
            }
        }
        cout << RESET << GREEN << "^^^^^^^^^^^^^ TASK ASSIGNED ^^^^^^^^^^^^^^^!\n"
             << endl
             << RESET;
    }
    bool displayTask(string emp_id, string type = "assign")
    {
        Expired();
        int expirecount = 0;
        if (type == "assign")
        {
            cout << BMAGENTA << "\n╔══════════════════════════════════════════════════════╗\n";
            cout << "║                   ASSIGNED TASKS                     ║\n";
            cout << "╚══════════════════════════════════════════════════════╝\n"
                 << RESET;
        }
        char task[50], user[5], assignee[5], status[15], priority[2], tid[5], trash[70];
        time_t catchcreate;
        int ttl;
        bool hastask = false;
        ifstream note;
        note.open("tasks.txt");
        while (note.getline(task, 50, '|'))
        {
            note.getline(user, 5, '|');
            note.getline(assignee, 5, '|');
            note.getline(priority, 2, '|');
            note.getline(tid, 5, '|');
            note.getline(status, 15, '|');
            note >> catchcreate;
            note >> ttl;
            if (strcmp(status, "Expired") == 0)
                expirecount++;
            if (user == emp_id and strcmp(status, "Expired") != 0)
            {
                hastask = true;
                cout << BCYAN;
                cout << "╔════════════════════════════════════════════════════════╗\n";
                cout << "║ Task ID: " << left << setw(46) << tid << "║\n";
                cout << "╠════════════════════════════════════════════════════════╣\n";
                cout << "║ Task:        " << left << setw(42) << task << "║\n";
                cout << "║ Assigned by: " << left << setw(42) << assignee << "║\n";
                cout << "║ Priority:    " << left << setw(42) << priority << "║\n";
                cout << "║ Status:      " << left << setw(42) << status << "║\n";
                cout << "║ Time:      " << left << setw(42) << ctime(&catchcreate) << "\n";
                cout << "╚════════════════════════════════════════════════════════╝\n\n";
                cout << RESET;
            }
        }
        note.close();
        cout << RED << "\n╔══════════════════════════════════════════════════════╗\n";
        cout << "║            " << expirecount << "       EXPIRED TASKS                     ║\n";
        cout << "╚══════════════════════════════════════════════════════╝\n"
             << RESET;
        if (!hastask)
        {
            cout << RED << "⚠ NO PENDING TASKS!\n"
                 << RESET;
            return false;
        }
        else
        {
            if (type == "assign")
                DoTask(emp_id);
        }
        return true;
    }
    void delegateTask(string emp_id)
    {
        string takeID;
        char giveID[5], specificID[5];
        takeID = emp_id;
        time_t catchcreate[10];
        int catchttl[10];
        cout << YELLOW << "Enter the ID of Role you want to delegate task TO : " << RESET;
        cin.ignore();
        cin.getline(giveID, 5, '\n');

        cout << BMAGENTA << "\n----------------------- CHOOSE THE TASK ID TO BE DELEGATED TO OTHER USER -----------------------\n"
             << RESET;
        if (displayTask(takeID, "display"))
        {
            cout << YELLOW << "Enter the TASK ID: ";
            cin.getline(specificID, 5, '\n');
            char tasks[10][50], users[10][5], assignee[10][5], priorities[10], tid[10][5], status[10][15];
            int i = 0;
            ifstream note;
            note.open("tasks.txt", ios::in);
            while (note.getline(tasks[i], 50, '|'))
            {
                note.getline(users[i], 5, '|');
                note.getline(assignee[i], 5, '|');
                note >> priorities[i];
                note.get(); 
                note.getline(tid[i], 5, '|');
                note.getline(status[i], 15, '|');
                note >> catchcreate[i];
                note >> catchttl[i];
                note.get();//catch \n character
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
                app << tasks[k] << "|" << users[k] << "|" << assignee[k] << "|" << priorities[k] << "|" << tid[k] << "|" << status[k] << "|" << catchcreate[k] << " " << catchttl[k] << endl;
            }
            cout << RESET << GREEN << "^^^^^^^^^^^^ TASK DELEGATED ^^^^^^^^^^" << endl
                 << RESET;
        }
        else
        {
            return;
        }
    }
};

class PolicyEngine
{ // abhi i will add more conditions in it
public:
    static bool can_assign(int from_clearance, int to_clearance)
    {
        return from_clearance >= to_clearance;
    }
    // Delegation rule
    static bool can_delegate(int from_clearance, int to_clearance)
    { // is allowed ki jagah i have made seperate functions for msg, delegation etc
        return from_clearance <= to_clearance;
    }

    // Messaging rule
    static bool canSendMessage(int senderClearance, int recipientClearance, string type)
    {
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

class Login
{
    string username;
    string input_pw;
    string hashed_input_pw;
    bool success;

public:
    Login() {}
    Login(string user, string pw) : username(user), input_pw(pw), success(false)
    {
        hashed_input_pw = hashpw(pw);
        checkCredentials();
    }

    bool isSuccess() const { return success; }

    string generate_otp()
    {
        srand(time(0));
        string otp = "";
        for (int i = 0; i < 4; i++)
        {
            otp += ('0' + rand() % 10); // generates random numbers like 2314
        }
        return otp;
    }
    string hashpw(string pw)
    {
        pw += "x7#"; // Append extra characters (salt)
        string encrypted = "";

        for (int i = 0; i < pw.length(); i++)
        {
            encrypted += pw[i] + 2; // Shift each character by 2
        }

        return encrypted;
    }

    void checkCredentials()
    {
        ifstream fin("users.txt");
        string user, hash_pw;

        while (fin >> user >> hash_pw)
        {
            if (user == username && hash_pw == hashed_input_pw)
            {
                success = true;
                break;
            }
        }

        fin.close();
        Audit::logAction(username, "LOGIN", success ? "SUCCESS" : "FAILURE");
    }
};

class Anomaly
{

private:
    int loginFailures;
    int permissionDenials;

public:
    Anomaly() : loginFailures(0), permissionDenials(0) {}

    static void detect()
    {
        ifstream fin("audit.txt");
        if (!fin)
        {
            cout << "Could not open audit.txt.\n";
            return;
        }

        string line;
        int loginFailures = 0;
        int permissionDenials = 0;

        while (getline(fin, line))
        {
            // Checks if line contains "LOGIN FAILURE"
            if (contains(line, "LOGIN FAILURE"))
            {
                loginFailures++;
                if (loginFailures <= 2)
                {
                     time_t now = time(0);
                fstream app;
                app.open("anomaly.txt", ios::app);
                 app << "[" << ctime(&now) << "]"  << "MULTIPLE LOGIN FAILURES DETECTED" << endl;
                app.close();
                }
            }
            // Checks if line contains "DENIED"
            if (contains(line, "DENIED"))
            {
                permissionDenials++;
                if (permissionDenials <= 2)
                {
                time_t now = time(0);
                fstream app;
                app.open("anomaly.txt", ios::app);
                app << "[" << ctime(&now) << "]" << "MULTIPLE PERMISSION DENIALS DETECTED" << endl;
                app.close();
                }
            }
        }

        fin.close(); 
        if (loginFailures <= 3 && permissionDenials <= 2)
            cout << "No suspicious activity found.\n";
    }

    // function to check if a string contains a substring
    static bool contains(string line, string word)
    {
        int lenText = line.length();
        int lenKey = word.length();

        for (int i = 0; i <= lenText - lenKey; i++)
        { // to prevent incorrect comparison
            bool match = true;
            for (int j = 0; j < lenKey; j++)
            {
                if (line[i + j] != word[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                return true;
        }
        return false;
    }
    // Friend function to overload <<
    friend ostream &operator<<(ostream &out, const Anomaly &a)
    {
        string line;
        bool is = false;
        ifstream in;
        in.open("anomaly.txt");
        while(getline(in, line, '\n'))
        {
            is = true;
            cout << RED << line << RESET << endl;
        }
        if (!is)
        {
           cout << GREEN;
        cout << "╔════════════════════════════════════════════════════════════╗\n";
        cout << "║                    NO SUSPICIOUS ACTIVITY                  ║\n";
        cout << "╚════════════════════════════════════════════════════════════╝\n";
        cout << RESET;
        }
        return out;
    }
};
