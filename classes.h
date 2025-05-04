
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
        
        fstream note;
        note.open("tasks.txt", ios:: app);
        note << task << "|" << T_ID << "|" << emp_id << "|" << priority <<  "|" << TaskID  << "|" << "Assigned" << endl;
        note.close(); 
        //deadline ki input kis format mai hogi wo bata dena and le lena yahan par
        // pehle goes the task in the file then the target id then the sender id phir priority and then taskID and then deadline which I didnt add yet and then status
        // I will use this sequence for when im reading and displaying from the file, pehle bar tak read kar ke task phenk dungi then so on 
        // baki saare status update karna meri zimmedaari hai but you have to come up with the logic of "expired" wala because you're dealing with deadlines
        // to once wo ban jaaye you can make a function of "isexpired" wahan se mai check kar ke expire kar dungi task ko 
   }
};
class PolicyEngine {
  public:
  bool isAllowed(char sender, char target) // im sending two grades there for you to compare and check the permission from 
  {
    return true; //for my ease, yahan you make the permission logic 
  }
};
class Audit {

};
class Employee {
    protected:
    string emp_id;
    string pw;
    char grade;
    Message* msg;
    Task* task;
    PolicyEngine allowed;
    Audit audit;
    
    public:
    void sendmsg();
    void receivemsg();
    void CreateTask()
    {
        
        grade = 'M'; // for my ease, iski assignment you will do once you update the data in users.txt
        char target;
        cout << "Enter the grade of the person you want to Assign a Task to: ";
        cin >> target;
        if (allowed.isAllowed(grade, target))
        {
            task = new Task; //dynamically allocating space for a new task
            task->appendtask("emp_id");
        }
    }
    void delegate_task();
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

