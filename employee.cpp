#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "employee.h"

#include "department.h"

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

void add_employee(Employee* last_employee)//���Ա���ĺ���
{
	Employee* new_employee = create_employee();
	
	printf("���Ա����Ϣ\n");//������ege��Ƶ��л�����е�printf�޸ĵ����ĳɿ��ӻ��Ľ���
	
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
	//ע������Ƶĺ����Ĳ˵���ʱ��Ա����Ӳ���Ӧ���Ͳ�����Ӳ���ͬʱ����

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
		//ע������Ƶĺ����Ĳ˵���ʱ��Ա��ɾ������Ӧ���Ͳ���ɾ������ͬʱ����
}

Employee* find_employee(int flag)//flag=1���������ң�flag=2�ǹ��Ų���
{
	if (flag == 1)
	{
		Employee* head = list_employee;
		char temp[1024];
		//printf("������Ա��������\n");	��������һ������������������
		scanf("%s", temp);
		while (head->next != NULL)
		{
			if (strcmp(head->name, temp) == 0)
			{
				//printf("������%s\n���ţ�%d\nְλ��%s\n���ţ�%s\n���᣺%\nнˮ��%d\n",head->name,head->number,head->duty,head->department,head->hometown,head->salary);
				//��������һ�����������������Ϣ
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
		//printf("������Ա��������\n");
		scanf("%d", temp);
		while (head->next != NULL)
		{
			if (head->number==temp)
			{
				//printf("������%s\n���ţ�%d\nְλ��%s\n���ţ�%s\n���᣺%\nнˮ��%d\n", head->name, head->number, head->duty, head->department, head->hometown, head->salary);
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