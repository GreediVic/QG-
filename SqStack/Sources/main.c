#include "../Headers/SqStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack = 0;
int main()
{
    Status check_name(char *na_me);                                            /* 删除或者清空前的询问安全功能 */
    void name(char *na_me);                                                    /* 输入用户姓名 */
    void menu();                                                               /* 菜单展示 */                            
    void how(Status hw);                                                       /* 操作状态提示 */
    ElemType *e = NULL;                                                        /* 用来传递栈顶元素  */
    ElemType *data = NULL;                                                     /* 用来传递出栈元素 */
    ElemType data_data = 0;                                                    /* 用来传递压栈元素 */
    Status hw;                                                                 /* 用来承接函数返回状态 */
    SqStack *s = NULL;                                                         /* 是整个栈的起源 */
    int *length = NULL;                                                        /* 用来检测栈的长度 */
    int sizes = 0;                                                             /* 用来表示创建时需要的大小 */
    int times = 0;                                                             /* 来标记是否已经有初始化的栈，避免内存泄露 */
    int c;                                                                     /* 用于增强代码健壮性的变量 */
    char cases[200000];                                                        /* 承接用户输入的选项 */
    char na_me[100000];                                                        /* 用户名称变量 */
    int stack_leth = 0;                                                        /* 用来存储栈长度 */
    name(na_me);              
    while (1)
    {
        printf("Welcome:%s\n\n",na_me);                                            /* 用户名称 */
        menu();                                                                    /* 菜单展示 */ 
        scanf("%s",cases);
        while(!(cases[0]>='0'&&cases[0]<='7'&&cases[1]=='\0'))                     /* 检测用户是否合法输入 */
        {
            printf("输入非法请重新输入：");
            scanf("%s",cases);
        }
        c = cases[0]-48;                                                            /* 只检测第一位，将字符转换成整型 */
        
        
        switch (c)
        {
            case 0:
            {
                if(times == 0)                                                      /* 检测是否已经有初始化的栈 */
                {
                    s = (SqStack *)malloc(sizeof(SqStack));
                    printf("请问您需要初始化多大的储存空间呢？（尽可能节省空间呀）\n");
                    scanf("%d",&sizes);     
                    while(sizes >= 1058971097 || sizes < 0)                         /* 检测恶意输入 */                
                    {   
                        system("cls");
                        if(sizes < 0)
                        {
                            printf("哦噢？好像是负值，可能数值太大了,\
                            或者您输入了一个负值忽悠我的，对不对（斜眼笑）\n");
                            printf("请重新输入：\n");
                            system("pause");
                            printf("请问您需要初始化多大的储存空间呢？\n");
                        }

                        scanf("%d",&sizes); 
                    }
                    stack_leth = sizes; 
                    how(initStack(s, sizes));                                        /* 栈初始化 */
                    times++;                                                         /* 证明有一次初始化 */                                     
                }
                else
                {
                    printf("您已经初始化了栈，若要重新初始化，请移步先进行摧毁原来的哦！\n");
                }
                
                system("pause");
                system("cls");
                break;
            }  


            case 1:
            {
                while (1)
                {
                    if(s != NULL && s->top+2 <= sizes)                                /* 先检查是否未初始化或者栈满 */          
                    {
                        printf("请输入想要记录的值(若数值太大会变成其他值哦)：");
                        scanf("%d",&data_data);
                        if(data_data <= -200000000 || data_data >= 200000000)         /* 保护系统机制 */
                        {
                            printf("对不起，当前版本不支持极端数值（太大或者太小）\n");
                            system("cls");
                        }
                        else
                        {
                            how(pushStack(s, data_data));                              /* 压栈 */
                            break;
                        }
                    }  
                    else 
                    {
                        printf("栈满(或未初始化)");
                        break;
                    }
                    
                }
                
            
                system("pause");
                system("cls");
                break;
            }


            case 2:
            {
                data = (ElemType *)malloc(sizeof(ElemType));                            
                how(hw = popStack(s, data));                                           /* 出栈 */
                if(data != NULL && hw)                                                 /* 条件：出栈成功 */
                {
                    printf("已删除:%d\n",*data);
                }
            
                system("pause");
                system("cls");
                free(data);                                                            /* 释放空间 */
                data = NULL;
                break;
            }


            case 3:
            {
                length = (int *)malloc(sizeof(int));
                how(stackLength(s, length));                                           /* 检测存储长度 */
                printf("已经储存内容数量:%d\n栈的长度是:%d\n", *length, stack_leth);

                system("pause");    
                system("cls");
                free(length);
                length = NULL;
                break;
            }


            case 4:
            {
                
                e = (ElemType *)malloc(sizeof(ElemType));
                how(hw = getTopStack(s, e));                                            /* 得到栈顶元素 */
                if(hw)                                                                  /* 条件：询问栈顶元素成功 */
                printf("最后一次存入的是:%d\n", *e);
                free(e);
                e = NULL;

                system("pause");
                system("cls");
                break;
            }


            case 5:
            {
                if(isEmptyStack(s) == 1)                                                /* 判断栈是为空 */
                {
                    printf("储存空间已经为空，可以重新记录内容\n");
                }
                else
                {
                    printf("储存空间尚存有内容。\n");
                }
            
                system("pause");    
                system("cls");
                break;
            }


            case 6:
            {
                if(isEmptyStack(s) == 0)                                                 /* 判断不为空 */
                {
                    if(check_name(na_me)==1)                                             /* 清除数据之前再次询问操作者 */
                    {
                        printf("身份确认!");
                        how(clearStack(s));                                              /* 进行clear，并且返回成功提示 */
                    }
                }
            
                system("cls");
                break;
            }
            
            
            case 7:
            {
                if(isEmptyStack(s) == 0)                                                 /* 判断存储内容不为空 */
                {
                    if(check_name(na_me)==1)                                             /* 清除数据之前再次询问操作者 */ 
                    {
                        printf("身份确认!");
                        how(destroyStack(s));                                            /* 摧毁栈，返回并表现状态 */
                        times = 0;                                                       /* 相当于没有初始化的栈，允许初始化 */
                        stack_leth = 0;
                        sizes = 0;
                        s = NULL;
                    }
                }
                else                                                                     /* 存储内容为空，可以摧毁栈 */
                {
                    how(destroyStack(s));
                    times = 0;
                    stack_leth = 0;
                    s = NULL;
                }
            
                system("cls");
                break;    
            }


            default:
                system("cls");
                break;
        }    
    }
    return 0;
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
        system("pause");
    }
    return ERROR;
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

void how(Status hw)                                                                        /* 函数运行状态 */
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
