#include"../Headers/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    Status Pop_opt(LinkStack_opt *s_opt,char *e);                       /* �������ջ���� */
    Status Push_opt(LinkStack_opt *s,char e);                           /* �����ѹջ���� */
    Status isdigit(char E);                                             /* �ж��Ƿ�Ϊ���� */
    int Prio_opt(char E);                                               /* �ж���������ȼ� */
    void Exprsion_In(char *E);                                          /* ������ʽ */                                       
    char choice = '0';                                                  /* ѡ���Ƿ����ʹ�ü����� */
    char *opr = NULL;                                                   /* �нӲ�������ָ�� */
    char *E = NULL;                                                     /* �нӱ��ʽ��ָ�� */
    LinkStack *s_num = NULL;                                            /* �ѷ����ֵ�ջ�ṹָ�� */
    LinkStack_opt *s_opt = NULL;                                        /* �ѷŲ�������ջ�ṹָ�� */
    s_num = (LinkStack *)malloc(sizeof(LinkStack));                     /* ��ʼ�� */                     
    s_opt = (LinkStack_opt *)malloc(sizeof(LinkStack_opt));
    while(choice != 'b' && choice != 'B')                               /* ѡ���Ƿ����ʹ�ü����� */
    {
        s_num->top = NULL;                                              /* ��ʼ������ r21~r30 */
        s_num->count = 0;
        s_opt->top = NULL;
        s_opt->count = 0;
        E = NULL;
        E = (char *)malloc(sizeof(char));
        int *num2 = NULL;
        int *num1 = NULL;        
        int i = 0;
        int temp = 0;
        Exprsion_In(E);                                                 /* ������ʽ�ĺ��� */
        while (E[i] != '\0' || s_opt->top != NULL)                      /* ����Ƿ���������������ջ��û�з��� */
        {
            
            if(!isdigit(E[i]))                                          /* �������� */
            {
                if(s_opt->top==NULL||                                   /* ���ʱû������� */  
                (E[i] != ')' && s_opt->top->opr == '(')                 /* ��ǰ��Ϊ�����Ų���ջ������������ */
                ||Prio_opt(E[i])>Prio_opt(s_opt->top->opr))             /* ��ǰ���ȼ�����ջ�����ȼ� */
                {       
                    Push_opt(s_opt, E[i++]);                            /* ����ǰ����ѹջ����������һ���ַ��� */
                    continue;
                }


                if(E[i] == ')' && s_opt->top->opr == '(')               /* ��ǰ����������ջ���������� */
                {
                    opr = (char *)malloc(sizeof(char));
                    Pop_opt(s_opt, opr);                                /* �ӵ�û�õ����� */
                    free(opr);
                    opr = NULL;
                    i++;                                                /* ��һ�� */
                    continue;
                }


                if((E[i] == '\0' && s_opt != NULL)||                    /* һ���������ǰδ������ */   
                E[i] == ')' && s_opt->top->opr != '('||                 /* ��ǰ�����ţ�ջ����Ϊ������ */
                Prio_opt(E[i]) <= Prio_opt(s_opt->top->opr))            /* ��ǰ���ȼ�С��ջ���� */
                {
                    num2 = (int *)malloc(sizeof(int));                  /* ׼����ջ�������ջ */
                    num1 = (int *)malloc(sizeof(int));
                    opr = (char *)malloc(sizeof(char));
                    Pop_opt(s_opt, opr);                                /* ��ջ�������ȡ�� */    

                    switch (*opr)                                       /* ѡ����㷽ʽ */            
                    {
                    case '+':                   
                        {
                            popLStack(s_num, num2);                     /* ��ջ�������ջ����ͬ�� */
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
                temp = 10 * temp + E[i++]-48;                           /* �����������֣�������������ַ���ת������������ */
                if(!isdigit(E[i]))                                      /* �����һ������������������ջ */
                {
                    pushLStack(s_num, temp);
                    temp = 0;                                           /* ׼���´μ��� */
                }
            }


        }
        if(s_num->top != NULL)
        printf("�����:\n>>%d\n",s_num->top->data);
        free(s_num->top);                                               /* ������Ŀռ���� */
        free(s_opt->top);
        free(num1);
        free(num2);
        free(opr);
        printf("����B or b���˳�\n");
        getchar();                                                      /* ���ջس� */
        scanf("%c",&choice);
        system("cls");

    }


    return 0;
}

void Exprsion_In(char *E)
{
    printf("��ӭʹ�ü��װ�Ӽ��˳�������\n");
    printf("�����������������������ʽ:\n>>");
    scanf("%s",E);
    if(E[0]>='A'&&E[0]<='z')
    {
         while(1)
        {
            printf("��������ȷ���ʽ��>>");
            scanf("%s",E);
            if(!(E[0]>='A'&&E[0]<='z'))                                  /* ���Ƿ����� */
            break;
            else
            system("cls");
        }
    }
   
    printf("����ɹ���");
}

Status isdigit(char E)                                                   /* �ж��Ƿ�Ϊ���� */
{
    return E>='0'&&E<='9' ? SUCCESS : ERROR;
}

int Prio_opt(char E)                                                     /*���ȼ��жϺ���*/
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

Status Push_opt(LinkStack_opt *s_opt,char e)                             /* ѹջ���� */
{
	LinkStack_opt_ptr s = NULL;
    s = (LinkStack_opt_ptr)malloc(sizeof(Stack_opt));
	if(s != NULL)                                                        /* ����Ƿ����ռ� */
    {
        s->opr=e;
        s->next=s_opt->top;                                              /* ����ԭ����ջ�� */
        s_opt->top=s;                                                    /* ����ջ��ָ�� */
    	return SUCCESS;        
    }
    else
    {
        return ERROR;
    }
    
 } 

 
Status Pop_opt(LinkStack_opt *s_opt,char *e)                             /* ��ջ */
{
	LinkStack_opt_ptr p;
	if(s_opt->top==NULL)
	{
		return ERROR;
	}
	*e=s_opt->top->opr;                                               /* ��ȡջ����ֵ */
	p=s_opt->top;                                                     /* ����ջ��λ�ã�׼���ͷ� */
	s_opt->top=s_opt->top->next;    
	free(p);                                                          /* �ͷ� */
	return SUCCESS; 
}
