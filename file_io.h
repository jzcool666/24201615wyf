#ifndef FILE_IO_H
#define FILE_IO_H
	
/*����������ļ���
employee�Ǵ�������Ա����Ϣ��
management�ǹ���㲿�ŵ�
market���г�����
develop�ǿ�������
finance�ǲ��񲿵�*/
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

void save_file(const char* filename, Employee* employee);//��������

Employee* load_file(const char* filename, Employee* employee);//��������


#endif FILE_IO_H


