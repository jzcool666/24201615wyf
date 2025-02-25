#include "employee.h"
#include "department.h"

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct department* create_department()//初始化部门，创造部门
{
	Department* new_department = (Department*)malloc(sizeof(Department));
	if (!new_department)
	{
		printf("创建部门失败！错误码3");
		//此处也有一个返回到上一个界面的函数
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
	Department* head = list_department;//部门添加函数
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

void delete_department(Employee* employee)//部门删除函数
{
	Department* head = list_department;
	while (strcmp(head->name, employee->department) != 0 && head->next != NULL)
	{
		head = head->next;
	}
	if (head->next == NULL)
	{
		printf("部门不存在或系统有误，错误码4！");
		return;
	}
	else
	{
		delete_employee(employee);
		return;
	}

}