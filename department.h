#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "employee.h"

struct department* create_department();//创建部门函数

void add_department(Employee* new_employee);//添加到部门的函数，将员工添加到部门当中

void delete_department(Employee* employee);//部门删除函数

#endif DEPARTMENT_H
