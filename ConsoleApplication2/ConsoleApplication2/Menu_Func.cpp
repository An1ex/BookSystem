#define _CRT_SECURE_NO_WARNINGS
#include<Basic_Func.h>
#include<Menu_Func.h>
#include<Model.h>
#include<stdio.h>
#include <graphics.h>
#include <conio.h>
#include<stdbool.h> //布尔型，把书的已借/在库状态用布尔型存储
#include<string.h>
#include<time.h> //获取时间函数
//借书功能
void Book_Borrow(book *head)
{
	initgraph(640, 480);//初始化窗口（窗口大小）
	findbook_id(head);
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回主页面");
	while (1)
	{
		MOUSEMSG msg = GetMouseMsg();//定义一个鼠标并获取鼠标信息(消息分发)
		if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				goto tiaozhuan1;
			}
		}
		else
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}
	}
tiaozhuan1:;

}

//还书功能
void Book_Return(book *head)
{
	initgraph(640, 480);//初始化窗口（窗口大小）
	char s[1000];
	InputBox(s, 100, NULL, "请输入相关信息：", NULL, 300, 200, false);
	outtextxy(0, 0, s);
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回主页面");
	while (1)
	{
		MOUSEMSG msg = GetMouseMsg();//定义一个鼠标并获取鼠标信息(消息分发)
		if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				goto tiaozhuan1;

			}

		}
		else
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}


	}
tiaozhuan1:;
}

//查询功能
void Book_Search(book *head)
{
	initgraph(640, 480);//初始化窗口（窗口大小）
	findbook_id(head);
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回主页面");
	while (1)
	{
		MOUSEMSG msg = GetMouseMsg();//定义一个鼠标并获取鼠标信息(消息分发)
		if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				goto tiaozhuan1;

			}

		}
		else
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}


	}
tiaozhuan1:;

}

//统计功能
void Book_Count(book *head)
{
	initgraph(640, 480);//初始化窗口（窗口大小）
	char s[1000];
	InputBox(s, 100, NULL, "请输入相关信息：", NULL, 300, 200, false);
	outtextxy(0, 0, s);
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回主页面");
	while (1)
	{
		MOUSEMSG msg = GetMouseMsg();//定义一个鼠标并获取鼠标信息(消息分发)
		if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				goto tiaozhuan1;

			}

		}
		else
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}


	}
tiaozhuan1:;
}

//管理员添加功能函数
void admin_add(book *head)
{
	cleardevice();
	int n;
	char n_c[20];
	InputBox(n_c, 20, 0, "请输入您要新录入图书的数量:", 0, 0, 0, false);//对话框
	n = atoi(n_c);
	//char s[1000];// 定义字符串缓冲区，并接收用户输入
	//InputBox(s, 500, NULL, "请输入相关信息：", NULL, 300, 200, false);
	add_book(head, n);
	//outtextxy(0, 0, s);
}

//管理员修改功能函数
void admin_change(book *head)
{
	cleardevice();
	char s[1000];// 定义字符串缓冲区，并接收用户输入
	InputBox(s, 500, NULL, "请输入相关信息：", NULL, 300, 200, false);
	outtextxy(0, 0, s);
}

//管理员删除功能函数
void admin_delete(book *head)
{
	cleardevice();
	char s[1000];// 定义字符串缓冲区，并接收用户输入
	InputBox(s, 500, NULL, "请输入相关信息：", NULL, 300, 200, false);//显示输入框
	outtextxy(0, 0, s);
}
//管理员查询功能函数 

//管理员功能页面
void admin_function(book *head)
{
    tiaozhuan1:;//跳出循环，返回管理员功能页面，重新绘画管理员页面
	initgraph(640, 480);//初始化窗口（窗口大小）
	cleardevice();//清屏，相当于刷新页面
	outtextxy(290, 20, "管理员功能:");
	roundrect(250, 80, 410, 120, 30, 30);
	outtextxy(315, 93, "添加");
	roundrect(250, 150, 410, 190, 30, 30);
	outtextxy(315, 163, "修改");
	roundrect(250, 220, 410, 260, 30, 30);
	outtextxy(315, 233, "删除");
	roundrect(250, 290, 410, 330, 30, 30);
	outtextxy(290, 303, "返回主页面");
	//鼠标触发循环
	while (true)
	{
		MOUSEMSG ms = GetMouseMsg();//重新定义一个鼠标信息
		if (ms.x > 250 && ms.x < 410 && ms.y>80 && ms.y < 120)
		{//鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条为红色
			roundrect(250, 80, 410, 120, 30, 30);
			if (ms.uMsg == WM_LBUTTONDOWN)
			{
				admin_add(head);//实现管理员添加功能
				goto tiaozhuan1;
			}
		}
		else if (ms.x > 250 && ms.x < 410 && ms.y>150 && ms.y < 190)
		{//鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RGB(255, 0, 0));//设置（绘画）线条为红色
			roundrect(250, 150, 410, 190, 30, 30);
			if (ms.uMsg == WM_LBUTTONDOWN)
			{
				admin_change(head);//实现管理员修改功能
				goto tiaozhuan1;//功能实现返回管理员页面
			}
		}
		else if (ms.x > 250 && ms.x < 410 && ms.y>220 && ms.y < 260)
		{//鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RGB(255, 0, 0));//设置（绘画）线条为红色
			roundrect(250, 220, 410, 260, 30, 30);
			if (ms.uMsg == WM_LBUTTONDOWN)
			{
				admin_delete(head);//设置（绘画）线条为红色
				goto tiaozhuan1;//功能实现返回管理员页面

			}
		}
		else if (ms.x > 250 && ms.x < 410 && ms.y>290 && ms.y < 330)
		{
			setlinecolor(RGB(255, 0, 0));
			roundrect(250, 290, 410, 330, 30, 30);
			if (ms.uMsg == WM_LBUTTONDOWN)
			{
				goto tiaozhuan0;//跳转到主页面
			}
		}
		else
		{
			setlinecolor(WHITE);
			roundrect(250, 80, 410, 120, 30, 30);
			roundrect(250, 150, 410, 190, 30, 30);
			roundrect(250, 220, 410, 260, 30, 30);
			roundrect(250, 290, 410, 330, 30, 30);
		}
	}
tiaozhuan0:;//跳出管理员页面，返回主页面
}

