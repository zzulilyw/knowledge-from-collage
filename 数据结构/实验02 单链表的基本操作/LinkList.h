#include "DS.h"

typedef int Elemtype;

typedef struct Node
{
    Elemtype  data;
	struct Node *next;
}Lnode,*LinkList;

void menu();                            /*菜单*/
Status Init_Linklist(LinkList &L);           /*初始化空表*/
Status Creat_Linklist(LinkList &L);         /*尾插法建立单链表*/
void Disp_Linklist(LinkList L);             /*单链表遍历*/
int length_Linklist(LinkList L);             /*计算单链表长度*/
void Reverse_Linklist(LinkList &L);         /*单链表逆置*/
void DelEven_Linklist(LinkList L);         /*删除值为偶数的结点*/
Status Insert_Linklist(LinkList L, int x);     /*在有序单链表L中插入元素x，链表仍然有序*/
Status CreatOrder_Linklist(LinkList &L);   /*创建非递减有序单链表*/
void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc);  /*两个非递减有序单链表La和Lb合并成一个非递增有序链表Lc*/
void MergeAscend_Linklist(LinkList La, LinkList Lb, LinkList &Lc); /*两个非递减有序单链表La和Lb合并成一个非递减有序链表Lc*/
void Split_Linklist(LinkList La, LinkList &Lb);  /*链表La按值分解成两个链表，La全部为奇数，Lb全部为偶数*/

