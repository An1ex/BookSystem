#define _CRT_SECURE_NO_WARNINGS
#include<Basic_Func.h>
#include<Menu_Func.h>
#include<Model.h>
#include<stdio.h>
#include <graphics.h>
#include <conio.h>
#include<string.h>
#include<time.h> //获取时间函数
//借书功能（已完成）
void Book_Borrow(book *head_b, student *head_s, teacher *head_t)
{
	char id[20];
	initgraph(640, 480);//初始化窗口（窗口大小）
	InputBox(id, 100, 0, "请输入您想要借阅的书的书号:", 0, 0, 0, false);
	findbook_id(head_b,id);
	roundrect(250, 220, 410, 260, 30, 30);
	outtextxy(290, 233, "学生借书证");//坐标，输出文字
	roundrect(250, 290, 410, 330, 30, 30);
	outtextxy(290, 303, "教师借书证");//坐标，输出文字
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回主页面");
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();//重新定义一个鼠标信息
		if (msg.x > 250 && msg.x < 410 && msg.y>220 && msg.y < 260)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 220, 410, 260, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				find_student(head_s,head_b,id);
				goto tiaozhuan10;

			}

		}
		else if (msg.x > 250 && msg.x < 410 && msg.y>290 && msg.y < 330)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 290, 410, 330, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				find_teacher(head_t, head_b, id);
				goto tiaozhuan10;
			}

		}
		else if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				goto tiaozhuan10;
			}
		}
		else//当鼠标移动到其他坐标，圆角矩形框架变为白色
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 220, 410, 260, 30, 30);// 画圆角矩形（坐标，圆角大小）
			roundrect(250, 290, 410, 330, 30, 30);// 画圆角矩形（坐标，圆角大小）
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}
	}
tiaozhuan10:;//跳转借书功能页面
}

//还书功能（已完成）
void Book_Return(book *head)
{
	initgraph(640, 480);//初始化窗口（窗口大小）
	char id[20];
	InputBox(id, 100, NULL, "请输入所还书的书号：", 0, 0, 0, false);
	return_book(head,id);//还书函数
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

				goto tiaozhuan20;

			}

		}
		else
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}


	}
tiaozhuan20:;
}

//查询功能（已完成）
void Book_Search(book *head)
{
	char id[20],name[20];
	initgraph(640, 480);//初始化窗口（窗口大小）
tiaozhuan30:;
	roundrect(250, 220, 410, 260, 30, 30);
	outtextxy(300, 233, "书号查询");//坐标，输出文字
	roundrect(250, 290, 410, 330, 30, 30);
	outtextxy(300, 303, "书名查询");//坐标，输出文字
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回主页面");
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();//重新定义一个鼠标信息
		if (msg.x > 250 && msg.x < 410 && msg.y>220 && msg.y < 260)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 220, 410, 260, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				InputBox(id, 100, 0, "请输入您想要的书的书号:", 0, 0, 0, false);
				findbook_id(head, id);//调用按书号查找函数
				goto tiaozhuan30;

			}

		}
		else if (msg.x > 250 && msg.x < 410 && msg.y>290 && msg.y < 330)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 290, 410, 330, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				InputBox(name, 100, 0, "请输入您想要的书的书名:", 0, 0, 0, false);
				findbook_name(head, name);//调用按书名查找函数
				goto tiaozhuan30;


			}

		}
		else if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				goto tiaozhuan00;

			}
		}
		else//当鼠标移动到其他坐标，圆角矩形框架变为白色
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 220, 410, 260, 30, 30);// 画圆角矩形（坐标，圆角大小）
			roundrect(250, 290, 410, 330, 30, 30);// 画圆角矩形（坐标，圆角大小）
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}
	}
tiaozhuan00:;
}

//统计功能（未完成）
void Book_Count(book *head)
{
	initgraph(640, 480);//初始化窗口（窗口大小）
	cleardevice;
tiaozhuan40:;
	roundrect(250, 220, 410, 260, 30, 30);
	outtextxy(290, 233, "借阅排行榜");//坐标，输出文字
	roundrect(250, 290, 410, 330, 30, 30);
	outtextxy(285, 303, "书库可借数目");//坐标，输出文字
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回主页面");
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();//重新定义一个鼠标信息
		if (msg.x > 250 && msg.x < 410 && msg.y>220 && msg.y < 260)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 220, 410, 260, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				book_rank(head);//调用借阅排行榜函数
				goto tiaozhuan40;

			}

		}
		else if (msg.x > 250 && msg.x < 410 && msg.y>290 && msg.y < 330)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 290, 410, 330, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				//Borrow_number();
				goto tiaozhuan40;
			}

		}
		else if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				goto tiaozhuan00;

			}
		}
		else//当鼠标移动到其他坐标，圆角矩形框架变为白色
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 220, 410, 260, 30, 30);// 画圆角矩形（坐标，圆角大小）
			roundrect(250, 290, 410, 330, 30, 30);// 画圆角矩形（坐标，圆角大小）
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}
	}
tiaozhuan00:;
}

//管理员添加功能函数（已完成）
void admin_add(book *head)
{
	
	initgraph(640, 480);//初始化窗口（窗口大小）
	cleardevice();//清屏，相当于刷新页面
	int n;
	char n_c[20];
	InputBox(n_c, 20, 0, "请输入您要新录入图书的数量:", 0, 0, 0, false);//对话框
	n = atoi(n_c);
	add_book(head, n);//调用添加函数
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回上页面");
	//鼠标触发循环
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();//重新定义一个鼠标信息
		if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				goto tiaozhuan1;

			}
		}
		else//当鼠标移动到其他坐标，圆角矩形框架变为白色
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}
	}
tiaozhuan1:;
}

//管理员修改功能函数（未写）
void admin_change(book *head)
{
	cleardevice();
	char s[1000];// 定义字符串缓冲区，并接收用户输入
	InputBox(s, 500, NULL, "请输入相关信息：", NULL, 300, 200, false);
	outtextxy(0, 0, s);
}

//管理员删除功能函数（已完成）
void admin_delete(book *head)
{
	initgraph(640, 480);//初始化窗口（窗口大小）
	cleardevice();//清屏，相当于刷新页面
	delbook_id(head);//调用删除函数
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回上页面");
	//鼠标触发循环
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();//重新定义一个鼠标信息
		if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				goto tiaozhuan1;

			}
		}
		else//当鼠标移动到其他坐标，圆角矩形框架变为白色
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}
	}
tiaozhuan1:;
}


//管理员功能页面(已完成）
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
				admin_delete(head);//实现管理员删除功能
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

