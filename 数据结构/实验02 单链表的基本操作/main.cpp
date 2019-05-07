#include "LinkList.h"

int main()
{
    int choice, length;
    LinkList L, La, Lb, Lc;
    while(1)
    {
        menu();
        printf("选择你的操作：");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(Creat_Linklist(L))
                    printf("单链表创建成功\n");
                else
                    printf("单链表创建失败\n");
                break;
            case 2:
                Disp_Linklist(L);
                break;
            case 3:
                length = length_Linklist(L);
                printf("单链表长度为：%d\n",length);
                break;
            case 4:
                Reverse_Linklist(L);
                printf("逆置后的链表为：\n");
                Disp_Linklist(L);
                break;
            case 5:
                DelEven_Linklist(L);
                printf("新链表为：\n");
                Disp_Linklist(L);
                break;
            case 6:
                if(CreatOrder_Linklist(L))
                {
                    printf("值有序链表为：\n");
                    Disp_Linklist(L);
                }
                else
                    printf("单链表创建失败\n");
                break;
            case 7:
                CreatOrder_Linklist(La);
                CreatOrder_Linklist(Lb);
                MergeDescend_Linklist(La, Lb, Lc);
                printf("合并后的新链表为：\n");Disp_Linklist(Lc);
                break;
            case 8:
                CreatOrder_Linklist(La);
                CreatOrder_Linklist(Lb);
                MergeAscend_Linklist(La, Lb, Lc);
                printf("合并后的新链表为：\n");Disp_Linklist(Lc);
                break;
            case 9:
                Creat_Linklist(L);
                Split_Linklist(L, Lb);
                printf("分裂后的新链表为：\n");
                Disp_Linklist(L);
                Disp_Linklist(Lb);
                break;
            case 0:
                return 0;
            default:
                printf("输入错误，请重新输入\n");
        }
    }
}

