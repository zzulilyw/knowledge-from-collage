#include "SqList.h"

int main()
{
    int choice, n, i, x;
    SqList L, La, Lb, Lc;
    while(1)
    {
        menu();
        printf("选择你的操作：");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(CreateList_Sq(L))
                    printf("顺序表创建成功\n");
                else
                    printf("顺序表创建失败\n");
                break;
            case 2:
                PrintList_Sq(L);
                break;
            case 3:
                printf("请输入删除元素的位置：");
                scanf("%d", &i);
                if(DeleteList_Sq(L, i, x))
                    printf("被删除元素值为：%d\n",x);
                else
                    printf("删除失败\n");
                break;
            case 4:
                printf("请输入删除元素值：");
                scanf("%d", &x);
                if(DeleteListX_Sq(L, x))
                    printf("删除成功\n");
                else
                    printf("删除失败\n");
                PrintList_Sq(L);
                break;
            case 5:
                AdjustList_Sq(L);
                printf("新链表为：\n");
                PrintList_Sq(L);
                break;
            case 6:
                printf("请输入顺序表长度：");
                scanf("%d", &n);
                if(OrderList_sq(L, n))
                {
                    printf("值有序顺序表为：\n");
                    PrintList_Sq(L);
                }
                else
                    printf("顺序表创建失败\n");
                break;
            case 7:
                printf("请输入顺序表La的长度：");
                scanf("%d", &n);
                OrderList_sq(La, n);
                printf("请输入顺序表Lb的长度：");
                scanf("%d", &n);
                OrderList_sq(Lb, n);
                MergeList_Sq(La, Lb, Lc);
                printf("合并后的顺序表为：\n");
                PrintList_Sq(Lc);
                break;
            case 0:
                return 0;
            default:
                printf("输入错误，请重新输入\n");
        }
    }
}

