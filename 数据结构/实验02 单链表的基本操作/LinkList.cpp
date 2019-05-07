
#include "LinkList.h"

void menu()
{
    printf("\t\t\t   �������������\n\n");
    printf("\t\t\t1.��  ��  ��  ��  ��\n");
    printf("\t\t\t2.��  ��  ��  ��  ��\n");
    printf("\t\t\t3.��  ��  �� �� �� ��\n");
    printf("\t\t\t4.��  ��  ��  ��\n");
    printf("\t\t\t5.ɾ  ��  ż �� �� ��\n");
    printf("\t\t\t6.�� �� ֵ �� �� �� �� ��\n");
    printf("\t\t\t7.��  �� �� �� ��  ��  �� ��\n");
    printf("\t\t\t8.��  �� �� �� ��  ��  �� ��\n");
    printf("\t\t\t9.��  ��  ��  ��\n");
    printf("\t\t\t0.��          ��\n\n");
}

/*��ʼ���ձ�*/
Status Init_Linklist(LinkList &L)
{
    L=(LinkList)malloc(sizeof(Lnode));
    if(!L) return ERROR;
	L->next=NULL;
	return OK;
}

/*β�巨����������*/
Status Creat_Linklist(LinkList &L)
{
    int x;
    LinkList p,rear;
    Init_Linklist(L);
    rear = L;
    printf("����-1��ʾ�������\n");
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

/*���������*/
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

/*���㵥������*/
int length_Linklist(LinkList L)
{
    int count = 0;   /*count��ʾ��������*/
    LinkList p;
    while(L->next!=NULL){
    	count++;
    	L = L->next;
	}
    return count;
}

/*����������*/
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

/*ɾ��ֵΪż���Ľ��*/
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

/*�����������в���Ԫ�أ�������Ȼ���򣬲���ɹ�����OK������ʧ�ܷ���ERROR*/
Status Insert_Linklist(LinkList L, int x)
{
    ;
}

/*�����ǵݼ��������������ɹ�����OK������ʧ�ܷ���ERROR*/
Status CreatOrder_Linklist(LinkList &L)
{
    
}

/*�����ǵݼ���������La��Lb�ϲ���һ���ǵ�����������Lc*/
void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc)
{
    
}

/*�����ǵݼ���������La��Lb�ϲ���һ���ǵݼ���������Lc*/
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

/*����La��ֵ�ֽ����������Laȫ��Ϊ������Lbȫ��Ϊż��*/
void Split_Linklist(LinkList La, LinkList &Lb)
{
    
}

