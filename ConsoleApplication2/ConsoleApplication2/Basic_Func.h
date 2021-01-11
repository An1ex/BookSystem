#ifndef _BASIC_FUNC_H

#define _BASIC_FUNC_H

#include <Model.h>
#include<Basic_Func.h>
#include<Menu_Func.h>

// 录入图书(管理员操作）   
//在链表结尾添加新节点
void add_book(book *head,int n);

//按书号查询图书（管理员操作、借书操作）
//原则上书号应该唯一，所以此函数也提供查询书号录入错误的书的功能，之后可用删除函数进行删除
void findbook_id(book *head);

//按书名查询图书（管理员操作、借书操作）
void findbook_name(book *head);

//根据书号删除图书（管理员操作、借书操作可调用）
void delbook_id(book *head);

//根据书名删除图书（管理员操作、清除由于输错书号的书的信息）
void delbook_name(book *head);

//根据管理员账号密码匹配管理员
void find_admin(admin *head1, book *head2);

#endif