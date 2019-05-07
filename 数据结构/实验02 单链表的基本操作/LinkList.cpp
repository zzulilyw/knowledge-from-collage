
#include "LinkList.h"

void menu()
{
    printf("\t\t\t   单链表基本操作\n\n");
    printf("\t\t\t1.建  立  单  链  表\n");
    printf("\t\t\t2.遍  历  单  链  表\n");
    printf("\t\t\t3.计  算  链 表 长 度\n");
    printf("\t\t\t4.链  表  逆  置\n");
    printf("\t\t\t5.删  除  偶 数 节 点\n");
    printf("\t\t\t6.生 成 值 有 序 单 链 表\n");
    printf("\t\t\t7.合  并 生 成 降  序  链 表\n");
    printf("\t\t\t8.合  并 生 成 升  序  链 表\n");
    printf("\t\t\t9.分  解  链  表\n");
    printf("\t\t\t0.退          出\n\n");
}

/*初始化空表*/
Status Init_Linklist(LinkList &L)
{
    L=(LinkList)malloc(sizeof(Lnode));
    if(!L) return ERROR;
	L->next=NULL;
	return OK;
}

/*尾插法建立单链表*/
Status Creat_Linklist(LinkList &L)
{
    int x;
    LinkList p,rear;
    Init_Linklist(L);
    rear = L;
    printf("输入-1表示输入结束\n");
    while(scanf("%d",&x),x != -1)
    {
        p = (LinkList)malloc(sizeof(Lnode));
        if(!p) return ERROR;
        p->data = x;
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
    return OK;
}

/*单链表遍历*/
void Disp_Linklist(LinkList L)
{
    LinkList p;
    p = L->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/*计算单链表长度*/
int length_Linklist(LinkList L)
{
    int count = 0;   /*count表示单链表长度*/
    LinkList p;
    while(L->next!=NULL){
    	count++;
    	L = L->next;
	}
    return count;
}

/*单链表逆置*/
void Reverse_Linklist(LinkList &L)
{
    LinkList p, q, r;
    q = L->next->next;
    p = L->next;
    p->next = NULL;
    while(q->next!=NULL){
    	r = q;
    	q->next = p;
    	q = r->next;
    	p = r;
	}
	L = p;
}

/*删除值为偶数的结点*/
void DelEven_Linklist(LinkList L)
{
    LinkList p, q;
	if(L->next!=NULL){
		q = L->next;
		p = L;
		while(q->next!=NULL){
			if(!(q->data)%2){
				p->next = q->next;
				q = q->next;
				free(p->next);
			}else{
				p = q;
				q = q->next;
			}
		}
		if(!(q->data)%2){
			free(q);
			p->next = NULL;
		}
	}
}

/*在有序单链表中插入元素，链表仍然有序，插入成功返回OK，插入失败返回ERROR*/
Status Insert_Linklist(LinkList L, int x)
{
    ;
}

/*创建非递减有序单链表，创建成功返回OK，创建失败返回ERROR*/
Status CreatOrder_Linklist(LinkList &L)
{
    
}

/*两个非递减有序单链表La和Lb合并成一个非递增有序链表Lc*/
void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc)
{
    
}

/*两个非递减有序单链表La和Lb合并成一个非递减有序链表Lc*/
void MergeAscend_Linklist(LinkList La, LinkList Lb, LinkList &Lc)
{
    LinkList pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
    pc = Lc = La;
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc->next = pa; pc = pa; pa = pa->next;
        }
        else
        {
            pc->next = pb; pc = pb; pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
}

/*链表La按值分解成两个链表，La全部为奇数，Lb全部为偶数*/
void Split_Linklist(LinkList La, LinkList &Lb)
{
    
}

