#pragma oncce
#include<string>
using namespace std;
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
            task->appendtask("M5");
        }
    }
    void delegate_task(){}
    void displayTask()
    {
        if (!task)
        {
            delete task; //recheck any memory issue here
        }
        task = new Task;
         task->displayTask("J4");
    }
