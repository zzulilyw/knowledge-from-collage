#include "LinkList.h"

int main()
{
    int choice, length;
    LinkList L, La, Lb, Lc;
    while(1)
    {
        menu();
        printf("ѡ����Ĳ�����");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(Creat_Linklist(L))
                    printf("���������ɹ�\n");
                else
                    printf("��������ʧ��\n");
                break;
            case 2:
                Disp_Linklist(L);
                break;
            case 3:
                length = length_Linklist(L);
                printf("��������Ϊ��%d\n",length);
                break;
            case 4:
                Reverse_Linklist(L);
                printf("���ú������Ϊ��\n");
                Disp_Linklist(L);
                break;
            case 5:
                DelEven_Linklist(L);
                printf("������Ϊ��\n");
                Disp_Linklist(L);
                break;
            case 6:
                if(CreatOrder_Linklist(L))
                {
                    printf("ֵ��������Ϊ��\n");
                    Disp_Linklist(L);
                }
                else
                    printf("��������ʧ��\n");
                break;
            case 7:
                CreatOrder_Linklist(La);
                CreatOrder_Linklist(Lb);
                MergeDescend_Linklist(La, Lb, Lc);
                printf("�ϲ����������Ϊ��\n");Disp_Linklist(Lc);
                break;
            case 8:
                CreatOrder_Linklist(La);
                CreatOrder_Linklist(Lb);
                MergeAscend_Linklist(La, Lb, Lc);
                printf("�ϲ����������Ϊ��\n");Disp_Linklist(Lc);
                break;
            case 9:
                Creat_Linklist(L);
                Split_Linklist(L, Lb);
                printf("���Ѻ��������Ϊ��\n");
                Disp_Linklist(L);
                Disp_Linklist(Lb);
                break;
            case 0:
                return 0;
            default:
                printf("�����������������\n");
        }
    }
}

