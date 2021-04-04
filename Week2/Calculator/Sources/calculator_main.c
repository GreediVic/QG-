#include"../Headers/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    Status Pop_opt(LinkStack_opt *s_opt,char *e);                       /* 运算符出栈操作 */
    Status Push_opt(LinkStack_opt *s,char e);                           /* 运算符压栈操作 */
    Status isdigit(char E);                                             /* 判断是否为数字 */
    int Prio_opt(char E);                                               /* 判断运算符优先级 */
    void Exprsion_In(char *E);                                          /* 输入表达式 */                                       
    char choice = '0';                                                  /* 选择是否继续使用计算器 */
    char *opr = NULL;                                                   /* 承接操作符的指针 */
    char *E = NULL;                                                     /* 承接表达式的指针 */
    LinkStack *s_num = NULL;                                            /* 堆放数字的栈结构指针 */
    LinkStack_opt *s_opt = NULL;                                        /* 堆放操作符的栈结构指针 */
    s_num = (LinkStack *)malloc(sizeof(LinkStack));                     /* 初始化 */                     
    s_opt = (LinkStack_opt *)malloc(sizeof(LinkStack_opt));
    while(choice != 'b' && choice != 'B')                               /* 选择是否继续使用计算器 */
    {
        s_num->top = NULL;                                              /* 初始化操作 r21~r30 */
        s_num->count = 0;
        s_opt->top = NULL;
        s_opt->count = 0;
        E = NULL;
        E = (char *)malloc(sizeof(char));
        int *num2 = NULL;
        int *num1 = NULL;        
        int i = 0;
        int temp = 0;
        Exprsion_In(E);                                                 /* 输入表达式的函数 */
        while (E[i] != '\0' || s_opt->top != NULL)                      /* 检查是否遍历结束或运算符栈顶没有符号 */
        {
            
            if(!isdigit(E[i]))                                          /* 不是数字 */
            {
                if(s_opt->top==NULL||                                   /* 最初时没有运算符 */  
                (E[i] != ')' && s_opt->top->opr == '(')                 /* 当前不为右括号并且栈顶不是左括号 */
                ||Prio_opt(E[i])>Prio_opt(s_opt->top->opr))             /* 当前优先级大于栈顶优先级 */
                {       
                    Push_opt(s_opt, E[i++]);                            /* 将当前符号压栈，遍历到下一个字符串 */
                    continue;
                }


                if(E[i] == ')' && s_opt->top->opr == '(')               /* 当前是右括号且栈顶是左括号 */
                {
                    opr = (char *)malloc(sizeof(char));
                    Pop_opt(s_opt, opr);                                /* 扔掉没用的括号 */
                    free(opr);
                    opr = NULL;
                    i++;                                                /* 下一个 */
                    continue;
                }


                if((E[i] == '\0' && s_opt != NULL)||                    /* 一般情况，当前未遍历完 */   
                E[i] == ')' && s_opt->top->opr != '('||                 /* 当前右括号，栈顶不为左括号 */
                Prio_opt(E[i]) <= Prio_opt(s_opt->top->opr))            /* 当前优先级小于栈顶的 */
                {
                    num2 = (int *)malloc(sizeof(int));                  /* 准备出栈计算后入栈 */
                    num1 = (int *)malloc(sizeof(int));
                    opr = (char *)malloc(sizeof(char));
                    Pop_opt(s_opt, opr);                                /* 将栈顶运算符取出 */    

                    switch (*opr)                                       /* 选择计算方式 */            
                    {
                    case '+':                   
                        {
                            popLStack(s_num, num2);                     /* 出栈计算后入栈（下同） */
                            popLStack(s_num, num1);
                            pushLStack(s_num, (*num1)+(*num2)); 
                            break;
                        }


                    case '-':
                        {
                            popLStack(s_num, num2);
                            popLStack(s_num, num1);
                            pushLStack(s_num, (*num1)-(*num2)); 
                            break;
                        }


                    case '*':
                        {
                            popLStack(s_num, num2);
                            popLStack(s_num, num1);
                            pushLStack(s_num, (*num1)*(*num2)); 
                            break;
                        }

                    case '/':
                        {
                            popLStack(s_num, num2);
                            popLStack(s_num, num1);
                            pushLStack(s_num, (*num1)/(*num2)); 
                            break;
                        }

                    
                    default:
                        break;
                    }
                }
            }
            else
            {
                temp = 10 * temp + E[i++]-48;                           /* 若遍历到数字，则持续遍历将字符串转化成完整数字 */
                if(!isdigit(E[i]))                                      /* 如果下一个不是数字则将数字入栈 */
                {
                    pushLStack(s_num, temp);
                    temp = 0;                                           /* 准备下次计算 */
                }
            }


        }
        if(s_num->top != NULL)
        printf("计算答案:\n>>%d\n",s_num->top->data);
        free(s_num->top);                                               /* 将申请的空间清空 */
        free(s_opt->top);
        free(num1);
        free(num2);
        free(opr);
        printf("输入B or b：退出\n");
        getchar();                                                      /* 吸收回车 */
        scanf("%c",&choice);
        system("cls");

    }


    return 0;
}

void Exprsion_In(char *E)
{
    printf("欢迎使用简易版加减乘除计算器\n");
    printf("请输入您所需计算的完整表达式:\n>>");
    scanf("%s",E);
    if(E[0]>='A'&&E[0]<='z')
    {
         while(1)
        {
            printf("请输入正确表达式：>>");
            scanf("%s",E);
            if(!(E[0]>='A'&&E[0]<='z'))                                  /* 检测非法输入 */
            break;
            else
            system("cls");
        }
    }
   
    printf("输入成功！");
}

Status isdigit(char E)                                                   /* 判断是否为数字 */
{
    return E>='0'&&E<='9' ? SUCCESS : ERROR;
}

int Prio_opt(char E)                                                     /*优先级判断函数*/
{
    if(E == '+' || E == '-')
    return 1;
    if(E == '*' || E == '/')
    return 2;
    if(E == '(')
    return 3;
    else
    return 0;
}

Status Push_opt(LinkStack_opt *s_opt,char e)                             /* 压栈操作 */
{
	LinkStack_opt_ptr s = NULL;
    s = (LinkStack_opt_ptr)malloc(sizeof(Stack_opt));
	if(s != NULL)                                                        /* 检查是否分配空间 */
    {
        s->opr=e;
        s->next=s_opt->top;                                              /* 连接原来的栈顶 */
        s_opt->top=s;                                                    /* 调整栈顶指针 */
    	return SUCCESS;        
    }
    else
    {
        return ERROR;
    }
    
 } 

 
Status Pop_opt(LinkStack_opt *s_opt,char *e)                             /* 出栈 */
{
	LinkStack_opt_ptr p;
	if(s_opt->top==NULL)
	{
		return ERROR;
	}
	*e=s_opt->top->opr;                                               /* 获取栈顶的值 */
	p=s_opt->top;                                                     /* 接手栈顶位置，准备释放 */
	s_opt->top=s_opt->top->next;    
	free(p);                                                          /* 释放 */
	return SUCCESS; 
}
