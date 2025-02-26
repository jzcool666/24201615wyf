#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "employee.h"

#include "department.h"

Employee* list_employee = NULL;
Department* list_department = NULL;
Employee* total_tail = NULL;



struct employee* create_employee()
{
	Employee* new_employee = (Employee*)malloc(sizeof(Employee));
	new_employee->next = NULL;
	new_employee->prev = NULL;
	if (!new_employee)
	{
		printf("创建员工失败！错误码2");
		//此处有一个退回到上一个界面的函数
		return NULL;
	}
	if (list_employee == NULL)
	{
		list_employee= new_employee;
		total_tail = new_employee;
	}
	return new_employee;
}

Employee* add_employee()//添加员工的函数
{
	Employee* new_employee = create_employee();
	
	printf("添加员工信息\n");//后续的ege设计当中会把所有的printf修改掉，改成可视化的界面
	
	printf("请输入姓名：\n");
	scanf("%1023s", new_employee->name);
	
	printf("请输入工号：\n");
	scanf("%d", &new_employee->number);
	
	printf("请输入职位：\n");
	scanf("%1023s", new_employee->duty);
	
	printf("请输入部门：\n");
	scanf("%1023s", new_employee->department);
	
	printf("请输入籍贯：\n");
	scanf("%1023s", new_employee->hometown);
	
	printf("请输入薪水：\n");
	scanf("%d", &new_employee->salary);
	
	if (list_employee->next = NULL)
	{
		list_employee = new_employee;
		total_tail = new_employee;
		return new_employee;
	}
	else
	{
		total_tail->next = new_employee;//双向链表，让前一个的后缀指向当前的
		new_employee->prev = total_tail;//让后一个的前缀指向前一个
		new_employee->next = NULL;//尾插法，后面是空的
		total_tail = new_employee;
		return new_employee;
	}
	//注意在设计的后续的菜单的时候，员工添加操作应当和部门添加操作同时进行

}

void delete_employee(Employee* employee)//删除操作，这里可能需要先查找到员工后再删除，后续改进
{
		if (employee->prev != NULL)//删除头结点的特殊情况
		{
			employee->prev->next = employee->next;
		}
		else
		{
			list_employee = employee->next;
		}

		if (employee->next != NULL)//删除尾节点的特殊情况
		{
			employee->next->prev = employee->prev;
		}
		else
		{
			total_tail = employee->prev;
		}

		free(employee);
		printf("删除成功");
		//注意在设计的后续的菜单的时候，员工删除操作应当和部门删除操作同时进行
}

Employee* find_employee(int flag)//flag=1是姓名查找，flag=2是工号查找
{
	if (flag == 1)
	{
		Employee* head = list_employee;
		char temp[1024];
		printf("请输入员工姓名：\n");//	后续再另一个函数里面再输出这个
		scanf("%s", temp);
		while (head != NULL)
		{
			if (strcmp(head->name, temp) == 0)
			{
				printf("姓名：%s\n工号：%d\n职位：%s\n部门：%s\n籍贯：%s\n薪水：%d\n",head->name,head->number,head->duty,head->department,head->hometown,head->salary);
				//后续再另一个函数里面再输出信息
				return head;
			}
		}
		printf("该员工不存在！");
		return NULL;
	}
	else if (flag == 2)
	{
		Employee* head = list_employee;
		int temp;
		printf("请输入员工工号：\n");
		scanf("%d", &temp);
		while (head != NULL)
		{
			if (head->number==temp)
			{
				printf("姓名：%s\n工号：%d\n职位：%s\n部门：%s\n籍贯：%s\n薪水：%d\n", head->name, head->number, head->duty, head->department, head->hometown, head->salary);
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

void show_employee(Employee* employee)//员工信息展示
{
	printf("姓名：%s\n工号：%d\n职位：%s\n部门：%s\n籍贯：%s\n薪水：%d\n", employee->name, employee->number, employee->duty, employee->department, employee->hometown, employee->salary);
}

void show_total()//整个单位的信息展示，展示的信息有人员，平均工资，最高工资和最低工资，工资方差
{

}