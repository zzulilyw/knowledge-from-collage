#include "SqList.h"

int main()
{
    int choice, n, i, x;
    SqList L, La, Lb, Lc;
    while(1)
    {
        menu();
        printf("ѡ����Ĳ�����");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(CreateList_Sq(L))
                    printf("˳������ɹ�\n");
                else
                    printf("˳�����ʧ��\n");
                break;
            case 2:
                PrintList_Sq(L);
                break;
            case 3:
                printf("������ɾ��Ԫ�ص�λ�ã�");
                scanf("%d", &i);
                if(DeleteList_Sq(L, i, x))
                    printf("��ɾ��Ԫ��ֵΪ��%d\n",x);
                else
                    printf("ɾ��ʧ��\n");
                break;
            case 4:
                printf("������ɾ��Ԫ��ֵ��");
                scanf("%d", &x);
                if(DeleteListX_Sq(L, x))
                    printf("ɾ���ɹ�\n");
                else
                    printf("ɾ��ʧ��\n");
                PrintList_Sq(L);
                break;
            case 5:
                AdjustList_Sq(L);
                printf("������Ϊ��\n");
                PrintList_Sq(L);
                break;
            case 6:
                printf("������˳����ȣ�");
                scanf("%d", &n);
                if(OrderList_sq(L, n))
                {
                    printf("ֵ����˳���Ϊ��\n");
                    PrintList_Sq(L);
                }
                else
                    printf("˳�����ʧ��\n");
                break;
            case 7:
                printf("������˳���La�ĳ��ȣ�");
                scanf("%d", &n);
                OrderList_sq(La, n);
                printf("������˳���Lb�ĳ��ȣ�");
                scanf("%d", &n);
                OrderList_sq(Lb, n);
                MergeList_Sq(La, Lb, Lc);
                printf("�ϲ����˳���Ϊ��\n");
                PrintList_Sq(Lc);
                break;
            case 0:
                return 0;
            default:
                printf("�����������������\n");
        }
    }
}

