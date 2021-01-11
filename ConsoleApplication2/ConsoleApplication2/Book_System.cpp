#define _CRT_SECURE_NO_WARNINGS
#include<Model.h>
#include<Basic_Func.h>
#include<Menu_Func.h>
#include<stdio.h>
#include <graphics.h>
#include <conio.h>
#include<string.h>
#include<time.h> //获取时间函数


/***********************
主函数
***********************/
int main() {
	//创立链表并把所有信息文件读入链表
	book *head_book = create_bklink();
	student *head_stu = create_stulink();
	teacher *head_tea = create_tealink();
	admin *head_adm = create_admlink();

	//主界面
tiaozhuan0:;//跳出循环
	initgraph(640, 480);//初始化窗口（窗口大小）
	cleardevice();//清屏，相当于刷新
	outtextxy(290, 20, "杭电图书馆");//坐标，输出文字
	outtextxy(297, 45, "管理系统");//坐标，输出文字
	roundrect(250, 80, 410, 120, 30, 30);// 画圆角矩形（坐标，圆角大小）
	outtextxy(315, 93, "借书");//坐标，输出文字
	roundrect(250, 150, 410, 190, 30, 30);
	outtextxy(315, 163, "还书");//坐标，输出文字
	roundrect(250, 220, 410, 260, 30, 30);
	outtextxy(315, 233, "查询");//坐标，输出文字
	roundrect(250, 290, 410, 330, 30, 30);
	outtextxy(315, 303, "统计");//坐标，输出文字
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(306, 370, "管理员");//坐标，输出文字
	outtextxy(260, 420, "请点击鼠标左键操作");//坐标，输出文字
	while (true)//鼠标触发循环
	{
		MOUSEMSG msg = GetMouseMsg();//定义一个鼠标并获取鼠标信息(消息分发)
		if (msg.x > 250 && msg.x < 410 && msg.y>80 && msg.y < 120)//判断鼠标移动的坐标
		{
			//鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 80, 410, 120, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)//uMsg：判断鼠标消息的类型（左键，右键，移动），WM_LBUTTONDOWN表示左键按下
			{
				Book_Borrow(head_book,head_stu,head_tea);//调用借书功能函数
				goto tiaozhuan0;
			}
		}
		else if (msg.x > 250 && msg.x < 410 && msg.y>150 && msg.y < 190)//判断鼠标移动的坐标
		{//鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);
			roundrect(250, 150, 410, 190, 30, 30);//设置（绘画）线条颜色为红色
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				Book_Return(head_book);//调用还书功能函数
				goto tiaozhuan0;
			}
		}
		else if (msg.x > 250 && msg.x < 410 && msg.y>220 && msg.y < 260)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 220, 410, 260, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				Book_Search(head_book);
				goto tiaozhuan0;

			}

		}
		else if (msg.x > 250 && msg.x < 410 && msg.y>290 && msg.y < 330)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 290, 410, 330, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				Book_Count(head_book);
				goto tiaozhuan0;


			}

		}
		else if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				find_admin(head_adm,head_book);//管理员登录函数
				goto tiaozhuan0;

			}
		}
		else//当鼠标移动到其他坐标，圆角矩形框架变为白色
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 80, 410, 120, 30, 30);// 画圆角矩形（坐标，圆角大小）
			roundrect(250, 150, 410, 190, 30, 30);// 画圆角矩形（坐标，圆角大小）
			roundrect(250, 220, 410, 260, 30, 30);// 画圆角矩形（坐标，圆角大小）
			roundrect(250, 290, 410, 330, 30, 30);// 画圆角矩形（坐标，圆角大小）
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}
	}
	getchar();
	closegraph();//关闭窗口
	return 0;
}