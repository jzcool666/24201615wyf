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
	while (list_employee != NULL)
	{
		show_employee(list_employee);
		printf("------------------\n");
		list_employee = list_employee->next;
	}



	
	
}