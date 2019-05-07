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
Status InitList_Sq(SqList &L, int n);/*初始化顺序表*/
Status CreateList_Sq(SqList &L);/*建立顺序表*/
void PrintList_Sq(SqList L);/*输出顺序表*/
Status DeleteList_Sq(SqList &L,int i,ElemType &e);/*删除第i个元素*/
Status DeleteListX_Sq(SqList &L,ElemType x);/*删除值为x的元素*/
Status AdjustList_Sq(SqList &L);/*奇数排在偶数之前*/
Status OrderList_sq(SqList &L, int n);/*插入法生成递增有序表*/
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc );/*两个非递减有序表A和B，并把它们合并成一个非递减有序表C*/

#endif // SQLIST_H_INCLUDED

