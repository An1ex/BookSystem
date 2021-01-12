#ifndef _MODEL_H

#define _MODEL_H

/**********************
链表结构体
**********************/
//定义图书结构体
typedef struct book {
	char id[20];  //图书编号
	char name[40];  //书名
	char author[40];//作者
	char publish[40]; //出版社
    int year, month, day; //年、月、日
	double price; //价格
	char type[20]; // 类别
	int state = 1; //书籍状态，1为可借，0为不可借，初始状态为可借
	struct book *next;
}Book;

//已借出图书结构体，仅用在统计功能中
typedef struct bwbook { 
	//char id[20];  //图书编号
	char name[50];  //书名
	char author[50];//作者
	char publish[50]; //出版社
	int year, month, day; //年、月、日
	double price; //价格
	char type[30]; // 类别
	int num = 0;//已借出数量
	//int state = 1; //书籍状态，1为可借，0为不可借，初始状态为可借
	struct bwbook *next;
}bwbook;

//定义读者_学生结构体
typedef struct student {
	char id[20];  //借书证号
	char name[20];  //姓名
	char stuclass[20]; //班级
	char stuid[20];  //学号
	int canb = 5;//可借阅5本
	int cant = 7;//可借阅7天
	double fine = 0;
	struct student *next;
}Student;

//定义读者_老师结构体
typedef struct teacher {
	char id[20];  // 借书证号
	char name[20];  //姓名
	char teaid[20];  // 学工号
	int canb = 10;//可借阅10本
	int cant = 14;//可借阅14天
	double fine = 0;
	struct teacher *next;
}Teacher;

// 定义管理员结构体 
typedef struct admin {
	char id[20];  //管理员工号
	char name[20];  //姓名
	char paswd[40]; //密码
	struct admin *next;
}Admin;

//创立链表并把图书信息文件读入链表
book *create_bklink();

//创立链表并把学生信息文件读入链表
student *create_stulink();

//创立链表并把老师信息文件读入链表
teacher *create_tealink();

//创立链表并把管理员信息文件读入链表
admin *create_admlink();

//输出图书链表到屏幕和文件output.txt 
void outlink(book *head);

//输出学生链表到屏幕和文件output.txt 
void outlink(student *head);

//输出老师链表到屏幕和文件output.txt 
void outlink(teacher *head);

//输出管理员链表到屏幕和文件output.txt 
void outlink(admin *head);

//输出排行榜链表到屏幕
void outrank(bwbook *head);

#endif
