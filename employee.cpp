#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "employee.h"

Employee* list_employee = NULL;
Department* list_department = NULL;


struct employee* create_employee()
{
	Employee* new_employee = (Employee*)malloc(sizeof(Employee));
	if (!new_employee)
	{
		printf("����Ա��ʧ�ܣ�");
		//�˴���һ���˻ص���һ������ĺ���
	}
	if (list_employee == NULL)
	{
		list_employee->next = new_employee;
		list_employee->prev = NULL;
		new_employee->prev = list_employee;
	}
	return new_employee;
}
void add_employee(Employee* last_employee)//���Ա���ĺ���
{
	Employee* new_employee = create_employee();
	
	printf("���Ա����Ϣ\n");
	
	printf("������������\n");
	scanf("%s", new_employee->name);
	
	printf("�����빤�ţ�\n");
	scanf("%d", new_employee->number);
	
	printf("������ְλ��\n");
	scanf("%s", new_employee->duty);
	
	printf("�����벿�ţ�\n");
	scanf("%s", new_employee->department);
	
	printf("�����뼮�᣺\n");
	scanf("%s", new_employee->hometown);
	
	printf("������нˮ��\n");
	scanf("%d", new_employee->salary);
	
	last_employee->next = new_employee;//˫��������ǰһ���ĺ�׺ָ��ǰ��
	new_employee->prev = last_employee;//�ú�һ����ǰ׺ָ��ǰһ��
	new_employee->next = NULL;//β�巨�������ǿյ�
}
Employee* find_employee(int flag)//flag=1���������ң�flag=2�ǹ��Ų���
{
	if (flag == 1)
	{
		Employee* head = list_employee;
		char temp[1024];
		printf("������Ա��������\n");
		scanf("%s", temp);
		while (head->next != NULL)
		{
			if (strcmp(head->name, temp) == 0)
			{
				printf("������%s\n���ţ�%d\nְλ��%s\n���ţ�%s\n���᣺%\nнˮ��%d\n",head->name,head->number,head->duty,head->department,head->hometown,head->salary);
				return head;
			}
		}
		printf("��Ա�������ڣ�");
		return NULL;
	}
	else if (flag == 0)
	{
		Employee* head = list_employee;
		int temp;
		printf("������Ա��������\n");
		scanf("%d", temp);
		while (head->next != NULL)
		{
			if (head->number==temp)
			{
				printf("������%s\n���ţ�%d\nְλ��%s\n���ţ�%s\n���᣺%\nнˮ��%d\n", head->name, head->number, head->duty, head->department, head->hometown, head->salary);
				return head;
			}
		}
		printf("��Ա�������ڣ�");
		return NULL;//����ֵ��NULL��ʱ����Ҫ�˻�ͼ�ν�����һ��
	}
	else
	{
		printf("״̬����������\n�����룺1");//������1
		return NULL;//����ֵ��NULL��ʱ����Ҫ�˻�ͼ�ν�����һ��
	}
}