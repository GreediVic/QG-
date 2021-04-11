#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/AQueue.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    extern char type;                                           /* 引入全局type，方便使用 */
    void menu();                                                /* 声明菜单 */
    AQueue *Q = NULL;                                           /*  */
    int times = 0;
    int c;
    char cases[10] = {'\0'};
    Q = (AQueue *)malloc(sizeof(AQueue));
    Q->data[0]=NULL;
    while(1)
    {   
        menu();
        scanf("%s",cases);
        while(!(cases[0]>='0'&&cases[0]<='9'))                   
        {
            printf("请输入合法字符：");
            scanf("%s",cases);
        }
        if (cases[1] != '\0')
        {
            c = 10;
        }
        else if(cases[1] == '\0')
            c = cases[0]-48;                                                            
        getchar();
        switch (c)
        {
            case 0:
            {
                if(times == 0)
                {
                    InitAQueue(Q);
                    printf("初始化成功\n");
                    times = 1;
                }
                else
                {
                    printf("您已经初始化！需要先销毁才能执行此操作\n");
                }

                system("pause");
                system("cls");
                break;
            }

            case 1:
            {
                def(Q);
                system("pause");
                system("cls");
                break;
            }

            case 2:
            {
                if (DeAQueue(Q))
                {
                    printf("操作成功!");
                }
                system("pause");
                system("cls");
                break;
            }       
            case 3:
            {
                if (TraverseAQueue(Q, APrint))
                {
                    printf("操作成功！\n");
                }
                else
                    printf("操作失败!\n");
                system("pause");
                system("cls");
                break;
            }

            case 4:
            {
                if (IsEmptyAQueue(Q))
                {
                    printf("操作成功！\n");
                }
                else
                {
                    printf("有数据\n");
                }
                system("pause");
                system("cls");
                break;
            }           

            case 5:
            {
                if (IsFullAQueue(Q))
                {
                    printf("操作成功！\n");
                }
                else
                    printf("队列未满!\n");
                system("pause");
                system("cls");
                break;
            }   

            case 6:
            {
                ClearAQueue(Q);
                system("pause");
                system("cls");
                break;
            }   

            case 7:
            {
                int a = -1;
                a = LengthAQueue(Q);
                printf("队列长度：%d\n",a);
                system("pause");
                system("cls");
                break;
            }    

            case 8:
            {
                void *e = malloc(21); 
                if (GetHeadAQueue(Q, e))
                {
                    type = datatype[Q->front];
                    APrint(e);
                }
                free(e);
                e = NULL;
                system("pause");
                system("cls");
                break;
            }      

            case 9:
            {
                if(times == 1)
                {
                    DestoryAQueue(Q);
                    printf("销毁成功");
                    Q->length = 0;
                    times = 0;
                }
                else
                {
                    printf("您尚未初始化队列，请先初始化\n");
                }
                
                system("pause");
                system("cls");
                break;
            }     
            case 10:
                break;
        }
        if (c == 10)
        {
            printf("您即将退出！\n");
            system("pause");
            break;
        }
    }123

    return 0;
}


void menu()                                                                             
{
    printf("\t=====================\n");
    printf("\t*[0]初始化队列       *\n");
    printf("\t*[1]队尾储存数据     *\n");
    printf("\t*[2]删除队头数据     *\n");
    printf("\t*[3]遍历队列数据     *\n");
    printf("\t*[4]检测是否有数据   *\n");
    printf("\t*[5]检测是否满数据   *\n");    
    printf("\t*[6]清空队列数据     *\n");
    printf("\t*[7]获取队列长度     *\n");
    printf("\t*[8]获取队头数据     *\n");
    printf("\t*[9]销毁队列数据     *\n");        
    printf("\t=====================\n");
    printf("请选择操作: ");
}

