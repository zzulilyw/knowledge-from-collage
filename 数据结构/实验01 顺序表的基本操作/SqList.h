#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#include "DS.h"

typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
    SqList_sort(int *a){
    	sort(a, a + listsize);
	}
}SqList;

void menu();
Status InitList_Sq(SqList &L, int n);/*��ʼ��˳���*/
Status CreateList_Sq(SqList &L);/*����˳���*/
void PrintList_Sq(SqList L);/*���˳���*/
Status DeleteList_Sq(SqList &L,int i,ElemType &e);/*ɾ����i��Ԫ��*/
Status DeleteListX_Sq(SqList &L,ElemType x);/*ɾ��ֵΪx��Ԫ��*/
Status AdjustList_Sq(SqList &L);/*��������ż��֮ǰ*/
Status OrderList_sq(SqList &L, int n);/*���뷨���ɵ��������*/
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc );/*�����ǵݼ������A��B���������Ǻϲ���һ���ǵݼ������C*/

#endif // SQLIST_H_INCLUDED

