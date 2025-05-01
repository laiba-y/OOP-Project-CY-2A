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
	void CreateTask();
	void delegate_task();
	void Login();
	string hashpw();
	virtual void showMenu() = 0;
};

