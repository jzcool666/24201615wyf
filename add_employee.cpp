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
		printf("创建员工失败！");
		//此处有一个退回到上一个界面的函数
	}
	return new_employee;
}
void add_employee(Employee* new_employee)
{
	
	printf("添加员工信息\n");
	printf("请输入姓名：");
	scanf("%s", new_employee->name);
	printf("请输入工号：")
	
}