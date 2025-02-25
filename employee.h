#ifndef EMPLOYEE_H
#define EMPLOYEE_H
typedef struct employee//Ա�������ݽṹ����
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
typedef struct department//���ŵ����ݽṹ����
{
	char name[1024];//��������
	Employee* employee;
	struct department* next;
}Department;

extern Employee* list_employee;//��employee.cpp��ʹ��
extern Department* list_department;//ͬ��
extern Employee* total_last_employee;//������Ա���������¼���ĵ��Ǹ�

void add_employee(Employee* last_employee);

struct employee* create_employee();

Employee* find_employee(int flag);
//�����flag��Ҫ��ͼ�ν��洦���ݣ����û�ѡ��������ѯ��flagΪ1����֮Ϊ2��������Ϊ1ʱ�ڴ˺����鿴ԭ��

void delete_employee(Employee* employee)��

#endif