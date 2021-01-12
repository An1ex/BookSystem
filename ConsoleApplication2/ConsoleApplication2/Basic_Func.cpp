#define _CRT_SECURE_NO_WARNINGS
#include<Model.h>
#include<Basic_Func.h>
#include<Menu_Func.h>
#include<stdio.h>
#include <graphics.h>
#include <conio.h>
#include<string.h>
#include<time.h> //获取时间函数

// 录入图书(管理员操作）   
//在链表结尾添加新节点
void add_book(book *head,int n) {
	book *newhead = (book*)malloc(sizeof(book));
	book *newp = (book*)malloc(sizeof(book));
	newhead->next = newp;
	char year_c[10],month_c[10],day_c[10],price_c[10];
	FILE *w = fopen("F:\\codespace\\c&c++\\C Design homework\\repo\\BookSystem\\book.txt", "a+");//添加图书的同时写入txt信息文件
	//fprintf(w, "\n");
	for (int i = 0; i < n; i++) {
		InputBox(newp->id, 100, 0, "请输入您要录入图书的信息，书号:", 0, 0, 0, false);
		InputBox(newp->name, 100, 0, "请输入您要录入图书的信息，书名:", 0, 0, 0, false);
		InputBox(newp->author, 100, 0, "请输入您要录入图书的信息，作者:", 0, 0, 0, false);
		InputBox(newp->publish, 100, 0, "请输入您要录入图书的信息，出版社:", 0, 0, 0, false);
		InputBox(year_c, 100, 0, "请输入您要录入图书的信息，出版日期(年):", 0, 0, 0, false);
		InputBox(month_c, 100, 0, "请输入您要录入图书的信息，出版日期(月):", 0, 0, 0, false);
		InputBox(day_c, 100, 0, "请输入您要录入图书的信息，出版日期(日):", 0, 0, 0, false);
		InputBox(price_c, 100, 0, "请输入您要录入图书的信息，价格:", 0, 0, 0, false);
		InputBox(newp->type, 100, 0, "请输入您要录入图书的信息，类型:", 0, 0, 0, false);
		newp->year = atoi(year_c);
		newp->month = atoi(month_c);
		newp->day = atoi(day_c);
		newp->price = atof(price_c);
		newp->state = 1;
		
		
		fprintf(w, "%s %s %s %s %4d %02d %02d %.2lf %s\n", newp->id, newp->name,newp->author, newp->publish, newp->year, newp->month, newp->day, newp->price, newp->type);//更新录入信息到.txt文件

		if (i == n - 1) newp->next = NULL;
		else {
			newp->next = (book*)malloc(sizeof(book));
			newp = newp->next;
		}
	}
	fclose(w);//关闭文件
	book *p = head->next;
	while (p != NULL) {
		p = p->next;
	}//  找到图书库链表的最后一个节点 
	p = newhead->next;//将新录入的图书链表接上
	//free(newp);
	//free(p);
	outtext("录入完成");
}

//根据书号修改图书(管理员操作） 
book *change_book(book *head,char id[]) {
	char name[20], author[40], publish[40], type[20],year_c[10],month_c[10],day_c[10],price_c[10],state_c[5];
	int year, month, day, state;
	double price;
	book *p = head->next;
	if (p == NULL) {//链表为空链表
		outtext("图书库中没有图书");
	}
	while (p) {
		if (strcmp(p->id, id) == 0) { //找到要修改的这本书
			InputBox(name, 100, 0, "请输入您要修改图书的信息，书名:", 0, 0, 0, false);
			InputBox(author, 100, 0, "请输入您要修改图书的信息，作者:", 0, 0, 0, false);
			InputBox(publish, 100, 0, "请输入您要修改图书的信息，出版社:", 0, 0, 0, false);
			InputBox(year_c, 100, 0, "请输入您要修改图书的信息，出版日期(年):", 0, 0, 0, false);
			InputBox(month_c, 100, 0, "请输入您要修改图书的信息，出版日期(月):", 0, 0, 0, false);
			InputBox(day_c, 100, 0, "请输入您要修改图书的信息，出版日期(日):", 0, 0, 0, false);
			InputBox(price_c, 100, 0, "请输入您要修改图书的信息，价格:", 0, 0, 0, false);
			InputBox(p->type, 100, 0, "请输入您修改图书的信息，类型:", 0, 0, 0, false);
			InputBox(state_c, 100, 0, "请输入您修改图书的信息，状态(1或0）:", 0, 0, 0, false);
			strcpy(p->name, name);
			strcpy(p->author, author);
			strcpy(p->publish, publish);
			p->year = atoi(year_c);
			p->month = atoi(month_c);
			p->day = atoi(day_c);
			p->price = atof(price_c);
			p->state = atoi(state_c);
			outtext("修改完成");
			break;
		}
		p = p->next;
	}
	if(p == NULL) outtext("未找到这本书");
	return head;
}

//根据书号删除图书（管理员操作） 
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
	outtext("删除完成");
}

//按书号查询图书（管理员操作、借书操作）
//原则上书号应该唯一，所以此函数也提供查询书号录入错误的书的功能，之后可用删除函数进行删除
void findbook_id(book *head,char id[]) {
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
			find_q->state = p->state;
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
		outtextxy(0,0,"您的查找结果为:");
		outtextxy(0,20,"书号   书名    作者      出版社   （出版日期）年   月   日   价格   类别    状态");
		outlink(head_find);
	}
}

//按书名查询图书（管理员操作、借书操作）
void findbook_name(book *head,char name[]) {
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
			find_q->state = p->state;
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
		outtextxy(0, 0, "您的查找结果为:");
		outtextxy(0, 20, "书号   书名    作者      出版社   （出版日期）年   月   日   价格   类别    状态");
		outlink(head_find);
	}
}


//管理员登陆函数(根据管理员账号密码匹配管理员)
void find_admin(admin *head_a, book *head_b) {
	char input[40], *ptr;
	char id[20], paswd[20];
	InputBox(input, 100, 0, "请输入您的账号和密码（中间以空格分隔）:", 0, 0, 0, false);
	//进行字符串分割
	ptr = strtok(input, " ");
	strcpy(id, ptr);
	ptr = strtok(NULL, " ");
	strcpy(paswd, ptr);
	admin *p = head_a->next;
	while (p != NULL) {
		if (strcmp(p->id, id) == 0)
		{ //找到相同账号的管理员
			if (strcmp(p->paswd, paswd) == 0)
			{
				//密码正确
				//在这跳转管理员功能主界面
				admin_function(head_b);
			}
			else
			{
				//outtext("登陆失败，密码错误");
				//在这里添加返回主页面
				goto tiaozhuan51;
			}
		}
		p = p->next;
	}
	//outtext("登陆失败，账号错误");
	//在这里添加返回主页面
	goto tiaozhuan51;
tiaozhuan51:;
}

//根据学生借书证号匹配学生
void find_student(student *head_s,book *head_b,char book_id[]) {
	initgraph(640, 480);//初始化窗口（窗口大小）
	cleardevice;//清屏

	char id[20];
	InputBox(id, 100, 0, "请输入您的借书证号:", 0, 0, 0, false);
	student *p = head_s->next;
	if (head_s == NULL)//链表为空链表
	{
		outtext("学生信息库中没有信息");
		return;
	}
	while (p != NULL) {
		if (strcmp(p->id, id) == 0) {//找到了这个学生
			if (p->canb > 0) {
				p->canb -= 1;//他的可借数目减一
				borrow_book(head_b, book_id);//成功调用借书函数
				break;
			}
			else {
				outtext("您的可借数目已达上限");
				break;
			}
		}
		p = p->next;
	}
	if (p == NULL) {
		outtext("您的借书证输入错误");
	}

	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回主页面");
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();//重新定义一个鼠标信息
		if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				goto tiaozhuan12;

			}
		}
		else//当鼠标移动到其他坐标，圆角矩形框架变为白色
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}
	}
tiaozhuan12:;//跳转学生借书功能页面
}

//根据教师借书证号匹配教师
void find_teacher(teacher *head_t,book *head_b, char book_id[]) {
	initgraph(640, 480);//初始化窗口（窗口大小）
	cleardevice;//清屏

	char id[20];
	InputBox(id, 100, 0, "请输入您的借书证号:", 0, 0, 0, false);
	teacher *p = head_t->next;
	if (head_t == NULL)//链表为空链表
	{
		outtext("教师信息库中没有信息");
		return;
	}
	while (p != NULL) {
		if (strcmp(p->id, id) == 0) {//找到了这个教师
			if (p->canb > 0) {
				p->canb -= 1;//他的可借数目减一
				borrow_book(head_b, book_id);//成功调用借书函数
				break;
			}
			else {
				outtext("您的可借数目已达上限");
				break;
			}
		}
		p = p->next;
	}
	if (p == NULL) outtext("您的借书证输入错误");

	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回主页面");
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();//重新定义一个鼠标信息
		if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				goto tiaozhuan12;

			}
		}
		else//当鼠标移动到其他坐标，圆角矩形框架变为白色
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}
	}
tiaozhuan12:;//跳转教师借书功能页面
}


//借书函数（主要是查找并将状态改为不可借false）
void borrow_book(book *head, char id[]) {
	book *p = head->next;
	if (head == NULL)//链表为空链表
	{
		outtext("图书库中没有图书");
		return;
	}
	while (p != NULL) {
		if (strcmp(p->id, id) == 0) {//找到了这本书
			if (p->state == 1) {
				p->state = 0;
				outtext("借书成功");
				break;
			}
			else {
				outtext("这本书已被借走");
				break;
			}
		}
		p = p->next;
	}
	if (p == NULL) outtext("您所借的书不存在");
}

//还书函数（主要是查找并将状态改为可借true）
void return_book(book *head, char id[]) {
	book *p = head->next;
	if (head == NULL)//链表为空链表
	{
		outtext("图书库中没有图书");
		return;
	}
	while (p != NULL) {
		if (strcmp(p->id, id) == 0) {//找到了这本书
			if(p->state == false){
				p->state = true;
				outtext("还书成功");
				break;
			}
			else {
				outtext("还书失败");
				break;
			}
		}
		p = p->next;
	}
	if (p == NULL) outtext("还书失败");
}

//排行榜查询是否重名函数
bwbook* rank_exists(char name[40], bwbook *head) {
	bwbook *p = head->next;
	while (p) {
		if (strcmp(name, p->name) == 0) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

//借阅排行榜函数（当前总的已出借图书排行榜）
void book_rank(book *head) {
	book *p = head->next;
	bwbook *head_rank = (bwbook*)malloc(sizeof(bwbook));//已借出图书结构体
	head_rank->next = NULL;
	bwbook *q = head_rank;
	bwbook *tmp;
	if (head == NULL)//链表为空链表
	{
		outtext("图书库中没有图书");
		return;
	}
	while (p != NULL) {
		if (p->state == 0)//找到已借出的书
			if (head_rank->next && (tmp = rank_exists(p->name, head_rank)))
				tmp->num += 1;
			else
			{
				q->next = (bwbook *)malloc(sizeof(bwbook));
				q = q->next;
				q->next = NULL;
				strcpy(q->name, p->name);
				strcpy(q->author, p->author);
				strcpy(q->publish, p->publish);
				q->year = p->year;
				q->month = p->month;
				q->day = p->day;
				q->price = p->price;
				q->num = 1;
				strcpy(q->type, p->type);
			}
		p = p->next;
	}
	initgraph(640, 480);//初始化窗口（窗口大小）
	cleardevice;
	outrank(head_rank);//借阅排行榜输出函数
	roundrect(250, 360, 410, 400, 30, 30);
	outtextxy(290, 370, "返回上页面");
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg();//重新定义一个鼠标信息
		if (msg.x > 250 && msg.x < 410 && msg.y>360 && msg.y < 400)
		{// 鼠标移动到上条件坐标，圆角矩形框变红色
			setlinecolor(RED);//设置（绘画）线条颜色为红色
			roundrect(250, 360, 410, 400, 30, 30);
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				goto tiaozhuan41;

			}
		}
		else//当鼠标移动到其他坐标，圆角矩形框架变为白色
		{
			setlinecolor(WHITE);//设置线条为白色
			roundrect(250, 360, 410, 400, 30, 30);// 画圆角矩形（坐标，圆角大小）
		}
	}
tiaozhuan41:;
}