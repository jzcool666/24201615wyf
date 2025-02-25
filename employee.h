#ifndef EMPLOYEE_H
#define EMPLOYEE_H
typedef struct employee
{
	char name[1024];
	int	number;
	char duty[1024];
	char ID[1024];
	int salary;
	char hometown[1024];
	char department[1024];
	struct employee* pre;
	struct employee* next;
}Employee;
void add_employee();
struct employee* create_employee();

#endif