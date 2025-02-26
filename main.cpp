#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "employee.h"
#include "department.h"
#include "file_io.h"

int main()
{
	for (int i = 0; i < 2; i++)
	{
		add_employee();
	}
	Employee* head = list_employee;
	while (head != NULL)
	{
		show_employee(head);
		printf("------------------\n");
		head = head->next;
	}
	find_employee(1);



	
	
}