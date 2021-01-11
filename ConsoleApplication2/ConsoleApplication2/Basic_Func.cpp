#define _CRT_SECURE_NO_WARNINGS
#include<Model.h>
#include<Basic_Func.h>
#include<Menu_Func.h>
#include<stdio.h>
#include <graphics.h>
#include <conio.h>
#include<stdbool.h> //布尔型，把书的已借/在库状态用布尔型存储
#include<string.h>
#include<time.h> //获取时间函数

// 录入图书(管理员操作）   
//在链表结尾添加新节点
void add_book(book *head,int n) {
	book *newhead = (book*)malloc(sizeof(book));
	book *newp = (book*)malloc(sizeof(book));
	newhead->next = newp;
	char year_c[4],month_c[2],day_c[2],price_c[10];
	for (int i = 0; i < n; i++) {
		//sprintf(str, "%s %s %s %s %4d %02d %02d %.2lf %s", newp->id, newp->name, newp->author, newp->publish, newp->date.year, newp->date.month, newp->date.day, newp->price, newp->type);
		InputBox(newp->id, 100, 0, "请输入您要录入图书的信息，书号:", 0, 0, 0, false);
		InputBox(newp->name, 100, 0, "请输入您要录入图书的信息，书名:", 0, 0, 0, false);
		InputBox(newp->author, 100, 0, "请输入您要录入图书的信息，作者:", 0, 0, 0, false);
		InputBox(newp->publish, 100, 0, "请输入您要录入图书的信息，出版社:", 0, 0, 0, false);
		InputBox(year_c, 100, 0, "请输入您要录入图书的信息，出版日期(年):", 0, 0, 0, false);
		InputBox(month_c, 100, 0, "请输入您要录入图书的信息，出版日期(月):", 0, 0, 0, false);
		InputBox(day_c, 100, 0, "请输入您要录入图书的信息，出版日期(日):", 0, 0, 0, false);
		InputBox(price_c, 100, 0, "请输入您要录入图书的信息，价格:", 0, 0, 0, false);
		InputBox(newp->type, 100, 0, "请输入您要录入图书的信息，价格:", 0, 0, 0, false);
		newp->year = atoi(year_c);
		newp->month = atoi(month_c);
		newp->day = atoi(day_c);
		newp->price = atof(price_c);
		if (i == n - 1) newp->next = NULL;
		else {
			newp->next = (book*)malloc(sizeof(book));
			newp = newp->next;
		}
	}
	book *p = head->next;
	while (p->next != NULL) {
		p = p->next;
	}//  找到图书库链表的最后一个节点 
	p->next = newhead->next;//将新录入的图书链表接上
	outtext("录入完成，更新后图书库信息为:");
	outlink(head);
}

//按书号查询图书（管理员操作、借书操作）
//原则上书号应该唯一，所以此函数也提供查询书号录入错误的书的功能，之后可用删除函数进行删除
void findbook_id(book *head) {
	char id[20];
	InputBox(id, 100, 0, "请输入您想要查询的书的书号:", 0, 0, 0, false);
	book *p = head->next;
	book *head_find = (book*)malloc(sizeof(book));
	book *find_q, *find_p;
	find_p = find_q = head_find;
	if (head == NULL)//链表为空链表
	{
		outtext("图书库中没有图书");
		return;
	}
	while (p != NULL) {
		if (strcmp(p->id, id) == 0) { //找到相同书号的书
			book *find_q = (book*)malloc(sizeof(book));
			strcpy(find_q->id, p->id);
			strcpy(find_q->name, p->name);
			strcpy(find_q->author, p->author);
			strcpy(find_q->publish, p->publish);
			find_q->year = p->year;
			find_q->month = p->month;
			find_q->day = p->day;
			find_q->price = p->price;
			strcpy(find_q->type, p->type);
			find_p->next = find_q;
			find_p = find_q;
		}
		p = p->next;
	}
	find_p->next = NULL;
	if (head_find->next == NULL) {
		outtext("未找到相关图书");
	}
	else {
		outtext("您的查找结果为:");
		outlink(head_find);
	}
}

//按书名查询图书（管理员操作、借书操作）
void findbook_name(book *head) {
	char name[50];
	InputBox(name, 100, 0, "请输入您想要查询的书的书名:", 0, 0, 0, false);
	book *p = head->next;
	book *head_find = (book*)malloc(sizeof(book));
	book *find_q, *find_p;
	find_p = find_q = head_find;
	if (head == NULL)//链表为空链表
	{
		outtext("图书库中没有图书");
		return;
	}
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) { //找到相同书名的书
			book *find_q = (book*)malloc(sizeof(book));
			strcpy(find_q->id, p->id);
			strcpy(find_q->name, p->name);
			strcpy(find_q->author, p->author);
			strcpy(find_q->publish, p->publish);
			find_q->year = p->year;
			find_q->month = p->month;
			find_q->day = p->day;
			find_q->price = p->price;
			strcpy(find_q->type, p->type);
			find_p->next = find_q;
			find_p = find_q;
		}
		p = p->next;
	}
	find_p->next = NULL;
	if (head_find->next == NULL) {
		outtext("未找到相关图书");
	}
	else {
		outtext("您的查找结果为:");
		outlink(head_find);
	}
}

//根据书号删除图书（管理员操作、借书操作可调用）
void delbook_id(book *head) {
	char id[20];
	InputBox(id, 100, 0, "请输入您想要删除的书的书号:", 0, 0, 0, false);
	book *p_front = head;
	book *p = head->next;
	if (p == NULL) {//链表为空链表
		outtext("图书库中没有图书");
	}
	while (p->next != NULL) {
		if (strcmp(p->id, id) == 0) {
			p_front->next = p->next;
			free(p);
			p = p_front->next;
		}
		else {
			p_front = p_front->next;
			p = p->next;
		}
	}
	outtext("删除完成，更新后图书库信息为:");
	outlink(head);
}

//根据书名删除图书（管理员操作、清除由于输错书号的书的信息）
void delbook_name(book *head) {
	char name[20];
	InputBox(name, 100, 0, "请输入您想要删除的书的书名:", 0, 0, 0, false);
	book *p_front = head;
	book *p = head->next;
	if (p == NULL) {//链表为空链表
		outtext("图书库中没有图书");
	}
	while (p->next != NULL) {
		if (strcmp(p->name, name) == 0) {
			p_front->next = p->next;
			free(p);
			p = p_front->next;
		}
		else {
			p_front = p_front->next;
			p = p->next;
		}
	}
	outtext("删除完成，更新后图书库信息为:");
	outlink(head);
}
//管理员登陆函数
//根据管理员账号密码匹配管理员
void find_admin(admin *head1,book *head2) {
	char input[40],*ptr;
	char id[20], paswd[20];
	InputBox(input, 100, 0, "请输入您的账号和密码（中间以空格分隔）:", 0, 0, 0, false);
	//进行字符串分割
	ptr = strtok(input, " ");
	strcpy(id, ptr);
	ptr = strtok(NULL, " ");
	strcpy(paswd, ptr);
	admin *p = head1->next;
	while (p != NULL) {
		if (strcmp(p->id,id) == 0) 
		{ //找到相同账号的管理员
			if (strcmp(p->paswd, paswd) == 0) 
			{ 
				//密码正确
				break;
				outtext("管理员登陆成功");
				//在这跳转管理员功能主界面
				admin_function(head2);
			}
			else 
			{
				break;
				outtext("登陆失败，密码错误");
				//在这里添加返回主页面
			}
		}
	}
	outtext("登陆失败，账号错误");
	//在这里添加返回主页面
}