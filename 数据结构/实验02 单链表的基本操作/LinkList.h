#include "DS.h"

typedef int Elemtype;

typedef struct Node
{
    Elemtype  data;
	struct Node *next;
}Lnode,*LinkList;

void menu();                            /*�˵�*/
Status Init_Linklist(LinkList &L);           /*��ʼ���ձ�*/
Status Creat_Linklist(LinkList &L);         /*β�巨����������*/
void Disp_Linklist(LinkList L);             /*���������*/
int length_Linklist(LinkList L);             /*���㵥������*/
void Reverse_Linklist(LinkList &L);         /*����������*/
void DelEven_Linklist(LinkList L);         /*ɾ��ֵΪż���Ľ��*/
Status Insert_Linklist(LinkList L, int x);     /*����������L�в���Ԫ��x��������Ȼ����*/
Status CreatOrder_Linklist(LinkList &L);   /*�����ǵݼ���������*/
void MergeDescend_Linklist(LinkList La, LinkList Lb, LinkList &Lc);  /*�����ǵݼ���������La��Lb�ϲ���һ���ǵ�����������Lc*/
void MergeAscend_Linklist(LinkList La, LinkList Lb, LinkList &Lc); /*�����ǵݼ���������La��Lb�ϲ���һ���ǵݼ���������Lc*/
void Split_Linklist(LinkList La, LinkList &Lb);  /*����La��ֵ�ֽ����������Laȫ��Ϊ������Lbȫ��Ϊż��*/

