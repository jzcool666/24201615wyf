#include "employee.h"
#include "department.h"

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct department* create_department()//��ʼ�����ţ����첿��
{
	Department* new_department = (Department*)malloc(sizeof(Department));
	if (!new_department)
	{
		printf("��������ʧ�ܣ�������3");
		//�˴�Ҳ��һ�����ص���һ������ĺ���
		return NULL;
	}
	if (list_department == NULL)
	{
		list_department->next = new_department;
		new_department->next = NULL;
	}
	return new_department;
}

void add_department(Employee* new_employee)
{
	Department* head = list_department;//������Ӻ���
	while (strcmp(head->name, new_employee->department) != 0 && head->next != NULL)
	{
		head = head->next;
	}
	if (head->next == NULL)
	{
		head->next = create_department();
		head = head->next;
		strcpy(head->name, new_employee->department);
	}
	else
	{
		head->employee->prev = new_employee;
		new_employee->next = head->employee;
		new_employee->prev = NULL;
		head->employee = new_employee;
	}

}

void delete_department(Employee* employee)//����ɾ������
{
	Department* head = list_department;
	while (strcmp(head->name, employee->department) != 0 && head->next != NULL)
	{
		head = head->next;
	}
	if (head->next == NULL)
	{
		printf("���Ų����ڻ�ϵͳ���󣬴�����4��");
		return;
	}
	else
	{
		delete_employee(employee);
		return;
	}

}