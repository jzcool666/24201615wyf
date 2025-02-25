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
		printf("����Ա��ʧ�ܣ�������2");
		//�˴���һ���˻ص���һ������ĺ���
		return NULL;
	}
	if (list_employee == NULL)
	{
		list_employee->next = new_employee;
		list_employee->prev = NULL;
		new_employee->prev = list_employee;
		new_employee->next = NULL;
	}
	return new_employee;
}
struct department* create_department()
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
		new_department ->next = NULL;
	}
	return new_department;
}
void add_employee(Employee* last_employee)//���Ա���ĺ���
{
	Employee* new_employee = create_employee();
	
	printf("���Ա����Ϣ\n");
	
	printf("������������\n");
	scanf("%s", new_employee->name);
	
	printf("�����빤�ţ�\n");
	scanf("%d", &new_employee->number);
	
	printf("������ְλ��\n");
	scanf("%s", new_employee->duty);
	
	printf("�����벿�ţ�\n");
	scanf("%s", new_employee->department);
	
	printf("�����뼮�᣺\n");
	scanf("%s", new_employee->hometown);
	
	printf("������нˮ��\n");
	scanf("%d", &new_employee->salary);
	
	last_employee->next = new_employee;//˫��������ǰһ���ĺ�׺ָ��ǰ��
	new_employee->prev = last_employee;//�ú�һ����ǰ׺ָ��ǰһ��
	new_employee->next = NULL;//β�巨�������ǿյ�
	total_tail = new_employee;

	//���ϲ����ǽ�Ա�����뵽�������У������ǽ�Ա�����뵽����������
	Department* head = list_department;
	while (strcmp(head->name, new_employee->department) != 0&&head->next!=NULL)
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

void delete_employee(Employee* employee)//ɾ�����������������Ҫ�Ȳ��ҵ�Ա������ɾ���������Ľ�
{
		if (employee->prev != NULL)//ɾ��ͷ�����������
		{
			employee->prev->next = employee->next;
		}
		else
		{
			list_employee = employee->next;
		}

		if (employee->next != NULL)//ɾ��β�ڵ���������
		{
			employee->next->prev = employee->prev;
		}
		else
		{
			total_tail = employee->prev;
		}

		free(employee);
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