#include "SqList.h"

void menu()
{
    printf("\t\t\t   顺序表基本操作\n\n");
    printf("\t\t\t1.建  立  顺  序  表\n");
    printf("\t\t\t2.遍  历  顺  序  表\n");
    printf("\t\t\t3.删 除 第 i 个 元 素\n");
    printf("\t\t\t4.删 除 值 为 x 的 元 素\n");
    printf("\t\t\t5.奇 数 排 在 偶 数 之 前\n");
    printf("\t\t\t6.插 入 法 生 成 递 增 有 序 表\n");
    printf("\t\t\t7.两个非递减有序表La和Lb合并成非递减有序表Lc\n");
    printf("\t\t\t0.退          出\n\n");
}

/*初始化顺序表*/
Status InitList_Sq(SqList &L, int n)
{
    L.elem=(ElemType*)malloc(n*sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=n;
    return OK;
}

/*建立顺序表*/
Status CreateList_Sq(SqList &L)
{
    int n, i;
    printf("请输入顺序表长度：");
    scanf("%d", &n);
    if(InitList_Sq(L, n))
    {
        printf("请输入%d个元素：", n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &L.elem[i]);
            L.length++;
        }
        return OK;
    }
    else
        return ERROR;
}

/*输出顺序表*/
void PrintList_Sq(SqList L)
{
    int i;
    printf("顺序表中元素为：\n");
    for(i = 0; i < L.length; i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

/*删除第i个元素*/
Status DeleteList_Sq(SqList &L,int i,ElemType &e)
{
	ElemType *p, *q;
	if( (i<1) || (i>L.length) ) return ERROR;
	p = &(L.elem[i-1]);
	e = *p;
  	q = L.elem+L.length-1;
	for(++p; p <= q; ++p) *(p-1) = *p;
	--L.length;
	return OK;
}

/*删除值为x的元素，删除成功返回OK，删除失败返回ERROR*/
Status DeleteListX_Sq(SqList &L,ElemType x)
{
	ElemType *p, *q;
	

}

/*奇数排在偶数之前*/
Status AdjustList_Sq(SqList &L)
{
    ElemType *p, *q;
    int temp;
    

    return OK;
}

/*插入法生成递增有序表，有序表生成成功返回OK，失败返回ERROR*/
Status OrderList_sq(SqList &L, int n)
{
    int i, j, x;  /*x表示每次待插入的元素*/

}

/*两个非递减有序表A和B，并把它们合并成一个非递减有序表C*/
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc )
{
    ElemType *pa, *pb, *pc, *pa_last, *pb_last;
    pa = La.elem; pb = Lb.elem;
    Lc.listsize = Lc.length = La.length+Lb.length;
    pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (!Lc.elem) exit (OVERFLOW);
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last)
    {
        if (*pa <= *pb) *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while(pa <= pa_last) *pc++ = *pa++;
    while(pb <= pb_last) *pc++ = *pb++;
}

