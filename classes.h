#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
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

class Tracker
{
private:
    int score;

public:
    Tracker() : score(100) {}

    void addscore(string findID)
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
                score = ach[j] + 10;
                ach[j] += 10; // Add the achievement score
                cout << "Score updated. New score: " << score << endl;
                break;
            }
        }
        scores.close();
        if (!found)
            cout << "ID not found. Score unchanged." << endl;
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
            if (ID[j] == findID)
            {
                score = ach[j] - 10; // Subtract the achievement score
                ach[j] -= 10;
                if (score < 0)
                {
                    score = 0;
                    ach[j] = 0;
                }
                cout << "Score updated. New score: " << score << endl;
                return;
            }
        }

        cout << "ID not found. Score unchanged." << endl;
    }

    int getScore() const
    {
        return score;
    }
};
class Date
{
};

class Time_Manager {
public:
    static bool checkExpiry(time_t creationTime, int ttlSeconds) {
        time_t now = time(0);
        return difftime(now, creationTime) >= ttlSeconds;
    }
};
class Message
{
    public:
    void sendmsg(string emp_id, string T_id, string msgtype)
    {
        string msg;
        cout << "Enter the message: ";
        cin.ignore();
        getline(cin, msg);
        if (msgtype == "PRIVATE")
        msg = encrypt();

        fstream app;
        app.open("inbox.txt", ios::app);
        app << msg << "|" << T_id << "|" << emp_id << "|" << msgtype << endl;
        cout << "Message Sent! " << endl;
        app.close();
    }
    string encrypt()
    {
           return "This is a private message";
    }
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
    Tracker report;

public:
#include <iostream>
#include <fstream>
#include <cstring>

void updatestatus(const char* taskComp, const char* newstatus)
{
    char tasks[10][50];
    char users[10][5];
    char assignee[10][5];
    char priorities[10];
    char tid[10][5];
    char status[10][15];
    int i = 0;

    std::ifstream note("tasks.txt", std::ios::in);
    if (!note.is_open()) {
        std::cerr << "Cannot open tasks.txt for reading\n";
        return;
    }

    // Read each record
    while (i < 10 && note.getline(tasks[i], 50, '|')) {
        note.getline(users[i], 5,   '|');
        note.getline(assignee[i],5, '|');

        // read single-char priority + delimiter
        note.get(priorities[i]);
        note.get();  // consume the '|' after priority

        note.getline(tid[i],    5,   '|');
        note.getline(status[i], 15,  '\n');
        ++i;
    }
    note.close();

    std::ofstream app("tasks.txt", std::ios::trunc);
    if (!app.is_open()) {
        std::cerr << "Cannot open tasks.txt for writing\n";
        return;
    }

    // Update matching task and rewrite file
    for (int j = 0; j < i; ++j) {
        if (std::strcmp(tid[j], taskComp) == 0) {
            // safely copy newstatus into status[j]
            std::strncpy(status[j], newstatus, sizeof(status[j]) - 1);
            status[j][sizeof(status[j]) - 1] = '\0';
        }
        app
          << tasks[j]    << '|'
          << users[j]    << '|'
          << assignee[j] << '|'
          << priorities[j] << '|'
          << tid[j]      << '|'
          << status[j]   << '\n';
    }
    app.close();
}

    void DoTask(string emp_id)
    {
        int option;
        char taskComp[5];
        char test;
        cout << "Press 1 to Start working on task, 2 to Exit";
        cin >> option;
        cin.ignore();
        if (option == 1)
        {
            cout << "Enter task ID: ";
            cin.getline(taskComp, 5, '\n');
            updatestatus(taskComp, "In Progress");
            cout << "Press 'Y' to complete task : ";
            cin >> test;
            if (test == 'Y')
            {
                cout << "Task Completed!" << endl;
                report.addscore(emp_id);
                updatestatus(taskComp, "Completed");
            }
            else
            {
                cout << "Task failed! Try process again... " << endl;
                report.subtractscore(emp_id);
                updatestatus(taskComp, "In Progress");
            }
        }
    }
    void appendtask(string emp_id) // jo user task assign kar raha hai uski ID in parameter so I can note it in the file
    {
        cin.ignore();
        cout << "Access permitted!\nEnter the Receiver's ID: ";
        cin.ignore();
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
    bool displayTask(string emp_id, string type = "assign")
    {
        if (type == "assign")
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
        char takeID[5], giveID[5], specificID[5];
        cout << "Enter the ID of Role you want to delegate the task FROM : ";
        cin.ignore();
        cin.getline(takeID, 5, '\n');
        cout << "Enter the ID of Role you want to delegate task TO : ";
        cin.getline(giveID, 5, '\n');

        cout << "-------------- CHOOSE THE TASK ID TO BE DELEGATED TO OTHER USER -------------\n";
        if (displayTask(takeID, "display"))
        {
            cout << "Enter the TASK ID: ";
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
            cout << "Task Delegated!" << endl;
            report.addscore(emp_id);
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
        return true;
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
};
class Anomaly {
public:
    static void detect() {
        ifstream fin("audit.txt");
        if (!fin) {
            cout << "Could not open audit.txt.\n";
            return;
        }

        string line;
        int loginFailures = 0;
        int permissionDenials = 0;

        while (getline(fin, line)) {
            // Checks if line contains "LOGIN FAILURE"
            if (contains(line, "LOGIN FAILURE"))
                loginFailures++;

            // Checks if line contains "DENIED"
            if (contains(line, "DENIED"))
                permissionDenials++;
        }

        fin.close();

        cout << "\n===== ANOMALY REPORT =====\n";
        if (loginFailures > 3)
            cout << "??  More than 3 failed logins detected.\n";
        if (permissionDenials > 2)
            cout << "??  More than 2 permission denials detected.\n";
        if (loginFailures <= 3 && permissionDenials <= 2)
            cout << "No suspicious activity found.\n";
    }

    // function to check if a string contains a substring
    static bool contains(string line, string word) {
        int lenText = line.length();
        int lenKey = word.length();

        for (int i = 0; i <= lenText - lenKey; i++) {  //to prevent incorrect comparison
            bool match = true;
            for (int j = 0; j < lenKey; j++) {
                if (line[i + j] != word[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }
};

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
     string generate_otp() {
    srand(time(0));
    string otp = "";
    for (int i = 0; i < 4; i++) {
        otp += ('0' + rand() % 10); // generates random numbers like 2314
    }
    return otp;
    }
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
