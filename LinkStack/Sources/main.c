#include "../Headers/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    
    void name(char *na_me);                                                     /* 输入用户姓名 */ 
    void how(Status hw);                                                        /* 操作状态提示 */ 
    void menu();                                                                /* 展示菜单 */
    Status check_name(char *na_me);                                             /* 删除或者清空前的询问安全功能 */
    ElemType *e = NULL;                                                         /* 用来传递栈顶元素  */
    LinkStack *s = NULL;                                                        /* 是整个栈的起源 */
    ElemType *data;                                                             /* 用来传递出栈元素 */
    ElemType data_data;                                                         /* 用来传递压栈元素 */
    Status hw;                                                                  /* 用来承接函数返回状态 */
    char cases[200000];                                                         /* 承接用户输入的选项 */
    char na_me[100000];                                                         /* 用户名称变量 */
    int *length = NULL;
    int c;                                                                      /* 用于增强代码健壮性的变量 */
    int times = 0;                                                              /* 标记是否已经初始化（0：否 1：是） */
    name(na_me);
    while (1)
    {
        printf("Welcome:%s\n\n",na_me);                                          /* 用户名称 */
        menu();                                                                  /* 菜单展示 */ 
        scanf("%s",cases);
        while(!(cases[0]>='0'&&cases[0]<='7'&&cases[1]=='\0'))                   /* 检测用户是否合法输入 */
        {
            printf("输入非法请重新输入：");
            scanf("%s",cases);
        }
        c = cases[0]-48;


        switch (c)
        {
            case 0:
            {
                if (times == 0)                                                   /* 判断是否初次初始化 */
                {
                    s = (LinkStack *)malloc(sizeof(LinkStack));
                    how(initLStack(s));
                    times++;
                }
                else
                {
                    printf("您已经初始化了栈，若要重新初始化，请移步先进行销毁原来的哦！\n");
                }
                
                system("pause");
                system("cls");
                break; 
            }


            case 1:
            {
                if(s!=NULL)                                                           /* 如果不为空 */
                {
                    printf("请输入想要记录的值(若数值太大会变成其他值哦)：");
                    scanf("%d",&data_data);
                    if(data_data <= -200000000 || data_data >= 200000000)              /* 保护系统机制 */
                    {
                        printf("对不起，当前版本不支持极端数值（太大或者太小）\n");
                    }
                    else
                    {
                        how(pushLStack(s, data_data));                                  /* 压栈 */
                    }    
                }
                else
                {
                    printf("请先初始化栈\n");
                }
                

                system("pause");
                system("cls");
                break;
            }


            case 2:
            {
                hw = isEmptyLStack(s);                                                  /* 判断栈是否为空 */              
                if(hw)
                {
                    printf("栈为空！没有元素可以出栈！\n");
                }
                else
                {
                    data = (ElemType *)malloc(sizeof(ElemType));
                    how(popLStack(s, data));                                            /*  */
                    printf("出栈元素为%d\n",*data);
                    free(data);
                    data = NULL;
                }
                
                system("pause");
                system("cls");
                break;  
            }
            
            case 3:
            {
                length = (int *)malloc(sizeof(int));
                how(hw = LStackLength(s, length));                                      /* 检测栈长度，并返回检测状态提示 */
                if(hw)
                printf("栈的长度为：%d\n",*length);                                     /* 显示长度 */
                
                free(length);
                length = NULL;
                system("pause");
                system("cls");
                break;
            }
            
            case 4:
            {
                e = (ElemType *)malloc(sizeof(ElemType));
                how(hw = getTopLStack(s, e));                                            /* 返回完成函数取栈顶数值任务，并提示状态 */
                if (hw)                                                                  /* 若成功，则告知栈顶元素是什么 */
                {
                   printf("最后一次输入的是%d\n",*e);
                }
                
                free(e);
                e = NULL;
                system("pause");
                system("cls");
                break;
            }
            
            case 5:
            {
                hw = isEmptyLStack(s);                                                     /* 判断栈是否为空 */              
                if(hw)
                {
                    printf("栈为空！\n");
                }
                else
                {
                    printf("栈不为空！\n");
                }
                
                system("pause");
                system("cls");
                break;
            }
            
            case 6:
            {
                if(isEmptyLStack(s) == 0)                                                 /* 判断不为空 */
                {
                    if(check_name(na_me)==1)                                             /* 清除数据之前再次询问操作者 */
                    {
                        printf("身份确认!");
                        how(clearLStack(s));                                             /* 进行clear，并且返回成功提示 */
                    }
                }

                system("pause");
                system("cls");
                break;
            }
            
            case 7:
            {
                if(isEmptyLStack(s) == 0)                                                 /* 判断存储内容不为空 */
                {
                    if(check_name(na_me)==1)                                             /* 清除数据之前再次询问操作者 */ 
                    {
                        printf("身份确认!");
                        how(destroyLStack(s));                                            /* 摧毁栈，返回并表现状态 */
                        times = 0;                                                       /* 相当于没有初始化的栈，允许初始化 */
                        s = NULL;
                    }
                }
                else                                                                     /* 存储内容为空，可以摧毁栈 */
                {
                    destroyLStack(s);
                    printf("操作成功！\n");
                    times = 0;
                    s = NULL;
                }
              
                system("pause");
                system("cls");
                break;
            }

            
            default:
                system("pause");
                system("cls");
                break;
        }
    }
    
    return 0;
}
void menu()                                                                             
{
    printf("\t====================================\n");
    printf("\t*[0]创建一个新栈                   *\n");
    printf("\t*[1]输入想要记录的内容             *\n");
    printf("\t*[2]删除最后一次记录的值           *\n");
    printf("\t*[3]查看已存内容所占空间的长度     *\n");
    printf("\t*[4]查看最后一次记录的内容         *\n");
    printf("\t*[5]判断储存空间是否存储内容       *\n");
    printf("\t*[6]清空所有内容                   *\n");
    printf("\t*[7]销毁空间                       *\n");
    printf("\t====================================\n");
    printf("Your Order IS: ");
}

void how(Status hw)                                                            /* 函数运行状态 */
{
    if(hw == 1)
    {
        printf("操作成功！\n");
    }
    else
    {
        printf("操作失败\n");
    }
}

void name(char *na_me)                                                                     /* 用户输入姓名 */ 
{
    printf("Please enter your name:");
    gets(na_me);
    system("pause");
    system("cls");
}

Status check_name(char *na_me)                                                             /* 用户姓名匹配，删除操作的二次询问 */     
{
    char answer[100];                                                                                                
    getchar();
    printf("检测空间仍存有信息，您真的还要执行操作吗？\n\
        若否定则按回车。\n要清空，请输入您的名字:");
    gets(answer);
    system("cls");
    if(!strcmp(answer, na_me))                                                             /* 如果姓名匹配 */
        {
            return SUCCESS;                                                                /* 可进行删除 */
        }    

    else
    {
        printf("您取消确认");
    }
    return ERROR;
}