#include <graphics.h>		//包含EGE的头文件

int main()
{
	initgraph(720, 600,INIT_RENDERMANUAL);	//初始化图形环境，创建宽高为640x480的窗口

	setbkcolor(EGERGB(0xFA, 0x2D, 0xFF));

	getch();				//暂停，等待按键

	closegraph();			//关闭窗口

	return 0;
}
