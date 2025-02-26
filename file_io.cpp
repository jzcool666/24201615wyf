#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "employee.h"
#include "department.h"
#include "file_io.h"

void save_file(const char* filename,Employee* employee)
{
	FILE* file = fopen(filename, "wb");

	if (file == NULL)
	{
		perror("打开文件失败");
		return;
	}
	
	Data* temp = (Data*)malloc(sizeof(Data));
	
	strcpy(temp->name, employee->name);
	
	temp->number = employee->number;
	
	strcpy(temp->department, employee->department);

	strcpy(temp->duty, employee->duty);

	strcpy(temp->ID, employee->ID);

	strcpy(temp->hometown, employee->hometown);

	temp->salary = employee->salary;

	fwrite(temp, sizeof(temp), 1, file);

	fclose(file);
		
}

Employee* load_file (const char* filename, Employee* employee)
{
	FILE* file = fopen(filename, "rb");

	if (file == NULL)
	{
		perror("文件打开失败");
		return NULL;
	}
	
	Data* temp = (Data*)malloc(sizeof(Data));

	fread(temp, sizeof(Data), 1, file);

	strcpy(employee->name, temp->name);

	employee->number = temp->number;

	strcpy(employee->department, temp->department);

	strcpy(employee->duty, temp->duty);

	strcpy(employee->ID, temp->ID);

	strcpy(employee->hometown, temp->hometown);

	employee->salary = temp->salary;

	fclose(file);

	return employee;

}