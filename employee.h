#ifndef EMPLOYEE_H
#define EMPLOYEE_H
typedef struct employee//员工的数据结构定义
{
	char name[1024];
	int	number;
	char duty[1024];
	char ID[1024];
	int salary;
	char hometown[1024];
	char department[1024];
	struct employee* prev;
	struct employee* next;
}Employee;
typedef struct department//部门的数据结构定义
{
	char name[1024];//部门名称
	Employee* employee;
	struct department* next;
}Department;

extern Employee* list_employee;//在employee.cpp中使用
extern Department* list_department;//同上
extern Employee* total_last_employee;//在所有员工当中最新加入的的那个

void add_employee(Employee* last_employee);

struct employee* create_employee();

Employee* find_employee(int flag);
//这里的flag需要在图形界面处传递，若用户选择姓名查询则flag为1，反之为2，错误码为1时在此函数查看原因

void delete_employee(Employee* employee)；

#endif