#ifndef FILE_IO_H
#define FILE_IO_H
	
/*创建了五个文件，
employee是储存所有员工信息的
management是管理层部门的
market是市场部的
develop是开发部的
finance是财务部的*/
typedef struct temp_data
{
	char name[1024];
	int	number;
	char duty[1024];
	char ID[1024];
	int salary;
	char hometown[1024];
	char department[1024];
}Data;

void save_file(const char* filename, Employee* employee);//保存数据

Employee* load_file(const char* filename, Employee* employee);//加载数据


#endif FILE_IO_H


