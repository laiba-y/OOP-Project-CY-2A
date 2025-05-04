
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Date{

};
class Time{

};
class Message {

};
class Task {
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
    std::getline(cin, task); //taking the task

    cout << "Enter priority (H/M/L): ";
    cin >> priority; 

    cout << "Enter task ID: ";
    cin >> TaskID;
        if (priority == 'L') //making sure the higher priority tasks stay up in the file 
        {
        fstream note;
        note.open("tasks.txt", ios:: app);
        note << task << "|" << T_ID << "|" << emp_id << "|" << priority <<  "|" << TaskID  << "|" << "Assigned" << endl;
        note.close(); 
        //deadline ki input kis format mai hogi wo bata dena and le lena yahan par
        // pehle goes the task in the file then the target id then the sender id phir priority and then taskID and then deadline which I didnt add yet and then status
        // I will use this sequence for when im reading and displaying from the file, pehle bar tak read kar ke task phenk dungi then so on 
        // baki saare status update karna meri zimmedaari hai but you have to come up with the logic of "expired" wala because you're dealing with deadlines
        // to once wo ban jaaye you can make a function of "isexpired" wahan se mai check kar ke expire kar dungi task ko 
        cout << "Task Assigned!\n" << endl;
        }
        else
        {
            char tasks[10][50], users[10][5], assignee[10][5], priorities[10], tid[10][5], status[10][15];
            int i = 0;
            ifstream note;
            note.open("tasks.txt", ios::in);
            while(note.getline(tasks[i], 50, '|'))
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
            //appending higher priority tasks first 
            ofstream app;
            app.open("tasks.txt");
            if (priority == 'H')
                {
                    app << task << "|" << T_ID << "|" << emp_id << "|" << priority <<  "|" << TaskID  << "|" << "Assigned" << endl;
                }
            for (int j = 0; j < i; j++)
            {
                if (priorities[j] == 'H')
                {
                    app << tasks[j] << "|" << users[j] << "|" << assignee[j] << "|" << priorities[j] << "|" << tid[j] << "|" << status[j] << endl;
                }
            }
            //appending medium priority tasks
            if (priority == 'M')
                {
                    app << task << "|" << T_ID << "|" << emp_id << "|" << priority <<  "|" << TaskID  << "|" << "Assigned" << endl;
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
                cout << "Assigned by : " << assignee << "    Priority: " << priority << "     Status: " << status << endl << endl; 
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
   }
};
class PolicyEngine {
  public:
  bool isAllowed(char sender, char target)
  {
    return true; //for my ease, yahan you make the permission logic 
  }
};
class Audit {

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
//     void delegate_task(){}
//     void displayTask()
//     {
//         if (!task)
//         {
//             delete task; //recheck any memory issue here
//         }
//         task = new Task;
//          task->displayTask("J4");
//     }
    void Login();
    string hashpw();
    virtual void showMenu() = 0;
    ~Employee()
    {
        delete task;
    }
    };
    
class Manager : public Employee{
    private:

    public:
    void showMenu()
    {
        cout << "------------------------ MENU --------------------------------";
        cout << "\nPRess 1 for assigning tasks, 2 for viewing tasks, 3 for delegating tasks : \n";  // I am making a very rough sa main right now, jab sab hojayega phir I will add decorations and shit
    }
};
