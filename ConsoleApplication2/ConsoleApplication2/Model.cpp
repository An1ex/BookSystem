#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <graphics.h>
#include <conio.h>
#include<stdbool.h> //布尔型，把书的已借/在库状态用布尔型存储
#include<string.h>
#include<time.h> //获取时间函数
#include<Model.h>

/************************
创立链表并把所有信息文件读入链表
************************/
//创立链表并把图书信息文件读入链表
book *create_bklink() {
	book *head = (book*)malloc(sizeof(book));
	char fid[20], fname[50], fauthor[50], fpublish[50], ftype[50];
	double fprice;
	int fyear, fmonth, fday;
	book *p;
	book *q;
	p = q = head;
	FILE *r = fopen("F:\\codespace\\c&c++\\C Design homework\\project(divided)\\book.txt", "r");
	if (r == NULL)
	{
		printf("Open input file failed");
		return NULL;
	}
	while (fscanf(r, "%s %s %s %s %d %d %d %lf %s", fid, fname, fauthor, fpublish, &fyear, &fmonth, &fday, &fprice, ftype) != EOF) {
		q = (book*)malloc(sizeof(book));
		strcpy(q->id, fid);
		strcpy(q->name, fname);
		strcpy(q->author, fauthor);
		strcpy(q->publish, fpublish);
		q->year = fyear;
		q->month = fmonth;
		q->day = fday;
		q->price = fprice;
		strcpy(q->type, ftype);
		p->next = q;
		p = q;
	}
	p->next = NULL;
	fclose(r);
	return head;
}

//创立链表并把学生信息文件读入链表
student *create_stulink() {
	student *head = (student*)malloc(sizeof(student));
	char fid[20], fname[20], fstuclass[20], fstuid[20];
	student *p;
	student *q;
	p = q = head;
	FILE *r = fopen("F:\\codespace\\c&c++\\C Design homework\\project(divided)\\student.txt", "r");
	if (r == NULL)
	{
		printf("Open input file failed");
		return NULL;
	}
	while (fscanf(r, "%s %s %s %s", fid, fname, fstuclass, fstuid) != EOF) {
		q = (student*)malloc(sizeof(student));
		strcpy(q->id, fid);
		strcpy(q->name, fname);
		strcpy(q->stuclass, fstuclass);
		strcpy(q->stuid, fstuid);
		p->next = q;
		p = q;
	}
	p->next = NULL;
	fclose(r);
	return head;
}

//创立链表并把老师信息文件读入链表
teacher *create_tealink() {
	teacher *head = (teacher*)malloc(sizeof(teacher));
	char fid[20], fname[20], fteaid[20];
	teacher *p;
	teacher *q;
	p = q = head;
	FILE *r = fopen("F:\\codespace\\c&c++\\C Design homework\\project(divided)\\teacher.txt", "r");
	if (r == NULL)
	{
		printf("Open input file failed");
		return NULL;
	}
	while (fscanf(r, "%s %s %s", fid, fname, fteaid) != EOF) {
		q = (teacher*)malloc(sizeof(teacher));
		strcpy(q->id, fid);
		strcpy(q->name, fname);
		strcpy(q->teaid, fteaid);
		p->next = q;
		p = q;
	}
	p->next = NULL;
	fclose(r);
	return head;
}

//创立链表并把管理员信息文件读入链表
admin *create_admlink() {
	admin *head = (admin*)malloc(sizeof(admin));
	char fid[20], fname[20], fpaswd[20];
	admin *p;
	admin *q;
	p = q = head;
	FILE *r = fopen("F:\\codespace\\c&c++\\C Design homework\\project(divided)\\admin.txt", "r");
	if (r == NULL)
	{
		printf("Open input file failed");
		return NULL;
	}
	while (fscanf(r, "%s %s %s",  fname, fid, fpaswd) != EOF) {
		q = (admin*)malloc(sizeof(admin));
		strcpy(q->id, fid);
		strcpy(q->name, fname);
		strcpy(q->paswd, fpaswd);
		p->next = q;
		p = q;
	}
	p->next = NULL;
	fclose(r);
	return head;
}


/************************
读出链表信息的函数
************************/
//输出图书链表到屏幕和文件output.txt 
void outlink(book *head) {
	book *p = head->next;
	/*FILE *w = fopen("F:\\codespace\\c&c++\\C Design homework\\project\\output.txt", "w");
	if (w == NULL) {
		printf("Open output file falied");
		return;
	}
	*/
	char str[200];
	int line = 25;
	//wchar_t info[200];
	while (p) {
		//mbstowcs(info, str, 200);
		sprintf(str, "%s %s %s %s %4d %02d %02d %.2lf %s", p->id, p->name, p->author, p->publish, p->year, p->month, p->day, p->price, p->type);
		outtextxy(0, line, str);
		p = p->next;
		line += 25;
	}
	//fprintf(w, "\n");
	//fclose(w);
	return;
}

//输出学生链表到屏幕和文件output.txt 
void outlink(student *head) {
	student *p = head->next;
	/*FILE *w = fopen("F:\\codespace\\c&c++\\C Design homework\\project\\output.txt", "w");
	if (w == NULL) {
		printf("Open output file falied");
		return;
	}*/
	char str[200];
	int line = 25;
	//wchar_t info[200];
	while (p) {
		//mbstowcs(info, str, 200);
		sprintf(str, "%s %s %s %s", p->id, p->name, p->stuclass, p->stuid);
		outtextxy(0, line, str);
		p = p->next;
		line += 25;
	}
	//fprintf(w, "\n");
	//fclose(w);
	return;
}


//输出老师链表到屏幕和文件output.txt 
void outlink(teacher *head) {
	teacher *p = head->next;
	/*FILE *w = fopen("F:\\codespace\\c&c++\\C Design homework\\project\\output.txt", "w");
	if (w == NULL) {
		printf("Open output file falied");
		return;
	}*/
	char str[200];
	int line = 25;
	//wchar_t info[200];
	while (p) {
		//mbstowcs(info, str, 200);
		sprintf(str, "%s %s %s", p->id, p->name, p->teaid);
		outtextxy(0, line, str);
		p = p->next;
		line += 25;
	}
	//fprintf(w, "\n");
	//fclose(w);
	return;
}

//输出管理员链表到屏幕和文件output.txt 
void outlink(admin *head) {
	admin *p = head->next;
	/*FILE *w = fopen("F:\\codespace\\c&c++\\C Design homework\\project\\output.txt", "w");
	if (w == NULL) {
		printf("Open output file falied");
		return;
	}
	*/
	char str[200];
	int line = 25;
	//wchar_t info[200];
	while (p) {
		//mbstowcs(info, str, 200);
		sprintf(str, "%s %s %s", p->id, p->name, p->paswd);
		outtextxy(0, line, str);
		p = p->next;
		line += 25;
	}
	//fprintf(w, "\n");
	//fclose(w);
	return;
}
