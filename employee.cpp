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
		printf("创建员工失败！");
		//此处有一个退回到上一个界面的函数
	}
	if (list_employee == NULL)
	{
		list_employee->next = new_employee;
		list_employee->prev = NULL;
		new_employee->prev = list_employee;
	}
	return new_employee;
}
void add_employee(Employee* last_employee)//添加员工的函数
{
	Employee* new_employee = create_employee();
	
	printf("添加员工信息\n");
	
	printf("请输入姓名：\n");
	scanf("%s", new_employee->name);
	
	printf("请输入工号：\n");
	scanf("%d", new_employee->number);
	
	printf("请输入职位：\n");
	scanf("%s", new_employee->duty);
	
	printf("请输入部门：\n");
	scanf("%s", new_employee->department);
	
	printf("请输入籍贯：\n");
	scanf("%s", new_employee->hometown);
	
	printf("请输入薪水：\n");
	scanf("%d", new_employee->salary);
	
	last_employee->next = new_employee;//双向链表，让前一个的后缀指向当前的
	new_employee->prev = last_employee;//让后一个的前缀指向前一个
	new_employee->next = NULL;//尾插法，后面是空的
}
Employee* find_employee(int flag)//flag=1是姓名查找，flag=2是工号查找
{
	if (flag == 1)
	{
		Employee* head = list_employee;
		char temp[1024];
		printf("请输入员工姓名：\n");
		scanf("%s", temp);
		while (head->next != NULL)
		{
			if (strcmp(head->name, temp) == 0)
			{
				printf("姓名：%s\n工号：%d\n职位：%s\n部门：%s\n籍贯：%\n薪水：%d\n",head->name,head->number,head->duty,head->department,head->hometown,head->salary);
				return head;
			}
		}
		printf("该员工不存在！");
		return NULL;
	}
	else if (flag == 0)
	{
		Employee* head = list_employee;
		int temp;
		printf("请输入员工姓名：\n");
		scanf("%d", temp);
		while (head->next != NULL)
		{
			if (head->number==temp)
			{
				printf("姓名：%s\n工号：%d\n职位：%s\n部门：%s\n籍贯：%\n薪水：%d\n", head->name, head->number, head->duty, head->department, head->hometown, head->salary);
				return head;
			}
		}
		printf("该员工不存在！");
		return NULL;//返回值是NULL的时候需要退回图形界面上一层
	}
	else
	{
		printf("状态有误，请重试\n错误码：1");//错误码1
		return NULL;//返回值是NULL的时候需要退回图形界面上一层
	}
}