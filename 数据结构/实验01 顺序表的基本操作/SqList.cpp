#include "SqList.h"

void menu()
{
    printf("\t\t\t   ˳����������\n\n");
    printf("\t\t\t1.��  ��  ˳  ��  ��\n");
    printf("\t\t\t2.��  ��  ˳  ��  ��\n");
    printf("\t\t\t3.ɾ �� �� i �� Ԫ ��\n");
    printf("\t\t\t4.ɾ �� ֵ Ϊ x �� Ԫ ��\n");
    printf("\t\t\t5.�� �� �� �� ż �� ֮ ǰ\n");
    printf("\t\t\t6.�� �� �� �� �� �� �� �� �� ��\n");
    printf("\t\t\t7.�����ǵݼ������La��Lb�ϲ��ɷǵݼ������Lc\n");
    printf("\t\t\t0.��          ��\n\n");
}

/*��ʼ��˳���*/
Status InitList_Sq(SqList &L, int n)
{
    L.elem=(ElemType*)malloc(n*sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=n;
    return OK;
}

/*����˳���*/
Status CreateList_Sq(SqList &L)
{
    int n, i;
    printf("������˳����ȣ�");
    scanf("%d", &n);
    if(InitList_Sq(L, n))
    {
        printf("������%d��Ԫ�أ�", n);
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

/*���˳���*/
void PrintList_Sq(SqList L)
{
    int i;
    printf("˳�����Ԫ��Ϊ��\n");
    for(i = 0; i < L.length; i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

/*ɾ����i��Ԫ��*/
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

/*ɾ��ֵΪx��Ԫ�أ�ɾ���ɹ�����OK��ɾ��ʧ�ܷ���ERROR*/
Status DeleteListX_Sq(SqList &L,ElemType x)
{
	ElemType *p, *q;
	

}

/*��������ż��֮ǰ*/
Status AdjustList_Sq(SqList &L)
{
    ElemType *p, *q;
    int temp;
    

    return OK;
}

/*���뷨���ɵ����������������ɳɹ�����OK��ʧ�ܷ���ERROR*/
Status OrderList_sq(SqList &L, int n)
{
    int i, j, x;  /*x��ʾÿ�δ������Ԫ��*/

}

/*�����ǵݼ������A��B���������Ǻϲ���һ���ǵݼ������C*/
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

