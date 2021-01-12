#ifndef _BASIC_FUNC_H

#define _BASIC_FUNC_H

#include <Model.h>
#include<Basic_Func.h>
#include<Menu_Func.h>

// 录入图书(管理员操作）   
//在链表结尾添加新节点
void add_book(book *head,int n);

//根据书号修改图书(管理员操作） 
book *change_book(book *head,char id[]);

//按书号查询图书（管理员操作、查询操作）
//原则上书号应该唯一，所以此函数也提供查询书号录入错误的书的功能，之后可用删除函数进行删除
void findbook_id(book *head,char id[]);

//按书名查询图书（管理员操作、借书操作）
void findbook_name(book *head,char name[]);

//根据书号删除图书（管理员操作、借书操作可调用）
void delbook_id(book *head);

//根据管理员账号密码匹配管理员
void find_admin(admin *head1, book *head2);

//根据学生借书证号匹配学生
void find_student(student *head_s, book *head_b, char book_id[]);

//根据教师借书证号匹配教师
void find_teacher(teacher *head_t, book *head_b, char book_id[]);

//借阅排行榜函数（当前总的借书排行榜
void book_rank(book *head);

//排行榜查询是否重名函数
bwbook* rank_exists(char name[40], bwbook *head);

//当前书库可借图书函数（不显示书号，只显示其他信息，加上数量


//借书函数（主要是查找并将状态改为false
void borrow_book(book *head,char id[]);

//还书函数（主要是查找并将状态改为true
void return_book(book *head,char id[]);



#endif