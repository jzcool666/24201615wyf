#include<stdio.h>
#include<stdlib.h>

#include "employee.h"

struct Node
{
	struct employee Data;
	struct Node* next;
};
struct employee* create_employee()
{
	Employee* new_employee = (Employee*)malloc(sizeof(Employee));
	if (!new_employee)
	{
		printf("����Ա��ʧ�ܣ�");
		//�˴���һ���˻ص���һ������ĺ���
	}
	return new_employee;
}
void add_employee(Employee* new_employee)
{
	
	printf("���Ա����Ϣ\n");
	printf("������������");
	scanf("%s", new_employee->name);
	printf("�����빤�ţ�")
	
}