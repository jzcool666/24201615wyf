#include <graphics.h>		//����EGE��ͷ�ļ�

int main()
{
	initgraph(720, 600,INIT_RENDERMANUAL);	//��ʼ��ͼ�λ������������Ϊ640x480�Ĵ���

	setbkcolor(EGERGB(0xFA, 0x2D, 0xFF));

	getch();				//��ͣ���ȴ�����

	closegraph();			//�رմ���

	return 0;
}
