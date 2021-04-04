#include "../Headers/SqStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack = 0;
int main()
{
    Status check_name(char *na_me);                                            /* ɾ���������ǰ��ѯ�ʰ�ȫ���� */
    void name(char *na_me);                                                    /* �����û����� */
    void menu();                                                               /* �˵�չʾ */                            
    void how(Status hw);                                                       /* ����״̬��ʾ */
    ElemType *e = NULL;                                                        /* ��������ջ��Ԫ��  */
    ElemType *data = NULL;                                                     /* �������ݳ�ջԪ�� */
    ElemType data_data = 0;                                                    /* ��������ѹջԪ�� */
    Status hw;                                                                 /* �����нӺ�������״̬ */
    SqStack *s = NULL;                                                         /* ������ջ����Դ */
    int *length = NULL;                                                        /* �������ջ�ĳ��� */
    int sizes = 0;                                                             /* ������ʾ����ʱ��Ҫ�Ĵ�С */
    int times = 0;                                                             /* ������Ƿ��Ѿ��г�ʼ����ջ�������ڴ�й¶ */
    int c;                                                                     /* ������ǿ���뽡׳�Եı��� */
    char cases[200000];                                                        /* �н��û������ѡ�� */
    char na_me[100000];                                                        /* �û����Ʊ��� */
    int stack_leth = 0;                                                        /* �����洢ջ���� */
    name(na_me);              
    while (1)
    {
        printf("Welcome:%s\n\n",na_me);                                            /* �û����� */
        menu();                                                                    /* �˵�չʾ */ 
        scanf("%s",cases);
        while(!(cases[0]>='0'&&cases[0]<='7'&&cases[1]=='\0'))                     /* ����û��Ƿ�Ϸ����� */
        {
            printf("����Ƿ����������룺");
            scanf("%s",cases);
        }
        c = cases[0]-48;                                                            /* ֻ����һλ�����ַ�ת�������� */
        
        
        switch (c)
        {
            case 0:
            {
                if(times == 0)                                                      /* ����Ƿ��Ѿ��г�ʼ����ջ */
                {
                    s = (SqStack *)malloc(sizeof(SqStack));
                    printf("��������Ҫ��ʼ�����Ĵ���ռ��أ��������ܽ�ʡ�ռ�ѽ��\n");
                    scanf("%d",&sizes);     
                    while(sizes >= 1058971097 || sizes < 0)                         /* ���������� */                
                    {   
                        system("cls");
                        if(sizes < 0)
                        {
                            printf("Ŷ�ޣ������Ǹ�ֵ��������ֵ̫����,\
                            ������������һ����ֵ�����ҵģ��Բ��ԣ�б��Ц��\n");
                            printf("���������룺\n");
                            system("pause");
                            printf("��������Ҫ��ʼ�����Ĵ���ռ��أ�\n");
                        }

                        scanf("%d",&sizes); 
                    }
                    stack_leth = sizes; 
                    how(initStack(s, sizes));                                        /* ջ��ʼ�� */
                    times++;                                                         /* ֤����һ�γ�ʼ�� */                                     
                }
                else
                {
                    printf("���Ѿ���ʼ����ջ����Ҫ���³�ʼ�������Ʋ��Ƚ��дݻ�ԭ����Ŷ��\n");
                }
                
                system("pause");
                system("cls");
                break;
            }  


            case 1:
            {
                while (1)
                {
                    if(s != NULL && s->top+2 <= sizes)                                /* �ȼ���Ƿ�δ��ʼ������ջ�� */          
                    {
                        printf("��������Ҫ��¼��ֵ(����ֵ̫���������ֵŶ)��");
                        scanf("%d",&data_data);
                        if(data_data <= -200000000 || data_data >= 200000000)         /* ����ϵͳ���� */
                        {
                            printf("�Բ��𣬵�ǰ�汾��֧�ּ�����ֵ��̫�����̫С��\n");
                            system("cls");
                        }
                        else
                        {
                            how(pushStack(s, data_data));                              /* ѹջ */
                            break;
                        }
                    }  
                    else 
                    {
                        printf("ջ��(��δ��ʼ��)");
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
                how(hw = popStack(s, data));                                           /* ��ջ */
                if(data != NULL && hw)                                                 /* ��������ջ�ɹ� */
                {
                    printf("��ɾ��:%d\n",*data);
                }
            
                system("pause");
                system("cls");
                free(data);                                                            /* �ͷſռ� */
                data = NULL;
                break;
            }


            case 3:
            {
                length = (int *)malloc(sizeof(int));
                how(stackLength(s, length));                                           /* ���洢���� */
                printf("�Ѿ�������������:%d\nջ�ĳ�����:%d\n", *length, stack_leth);

                system("pause");    
                system("cls");
                free(length);
                length = NULL;
                break;
            }


            case 4:
            {
                
                e = (ElemType *)malloc(sizeof(ElemType));
                how(hw = getTopStack(s, e));                                            /* �õ�ջ��Ԫ�� */
                if(hw)                                                                  /* ������ѯ��ջ��Ԫ�سɹ� */
                printf("���һ�δ������:%d\n", *e);
                free(e);
                e = NULL;

                system("pause");
                system("cls");
                break;
            }


            case 5:
            {
                if(isEmptyStack(s) == 1)                                                /* �ж�ջ��Ϊ�� */
                {
                    printf("����ռ��Ѿ�Ϊ�գ��������¼�¼����\n");
                }
                else
                {
                    printf("����ռ��д������ݡ�\n");
                }
            
                system("pause");    
                system("cls");
                break;
            }


            case 6:
            {
                if(isEmptyStack(s) == 0)                                                 /* �жϲ�Ϊ�� */
                {
                    if(check_name(na_me)==1)                                             /* �������֮ǰ�ٴ�ѯ�ʲ����� */
                    {
                        printf("���ȷ��!");
                        how(clearStack(s));                                              /* ����clear�����ҷ��سɹ���ʾ */
                    }
                }
            
                system("cls");
                break;
            }
            
            
            case 7:
            {
                if(isEmptyStack(s) == 0)                                                 /* �жϴ洢���ݲ�Ϊ�� */
                {
                    if(check_name(na_me)==1)                                             /* �������֮ǰ�ٴ�ѯ�ʲ����� */ 
                    {
                        printf("���ȷ��!");
                        how(destroyStack(s));                                            /* �ݻ�ջ�����ز�����״̬ */
                        times = 0;                                                       /* �൱��û�г�ʼ����ջ�������ʼ�� */
                        stack_leth = 0;
                        sizes = 0;
                        s = NULL;
                    }
                }
                else                                                                     /* �洢����Ϊ�գ����Դݻ�ջ */
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



Status check_name(char *na_me)                                                             /* �û�����ƥ�䣬ɾ�������Ķ���ѯ�� */     
{
    char answer[100];                                                                                                
    getchar();
    printf("���ռ��Դ�����Ϣ������Ļ�Ҫִ�в�����\n\
        �����򰴻س���\nҪ��գ���������������:");
    gets(answer);
    system("cls");
    if(!strcmp(answer, na_me))                                                             /* �������ƥ�� */
        {
            return SUCCESS;                                                                /* �ɽ���ɾ�� */
        }    

    else
    {
        printf("��ȡ��ȷ��");
        system("pause");
    }
    return ERROR;
}

void menu()                                                                             
{
    printf("\t====================================\n");
    printf("\t*[0]����һ����ջ                   *\n");
    printf("\t*[1]������Ҫ��¼������             *\n");
    printf("\t*[2]ɾ�����һ�μ�¼��ֵ           *\n");
    printf("\t*[3]�鿴�Ѵ�������ռ�ռ�ĳ���     *\n");
    printf("\t*[4]�鿴���һ�μ�¼������         *\n");
    printf("\t*[5]�жϴ���ռ��Ƿ�洢����       *\n");
    printf("\t*[6]�����������                   *\n");
    printf("\t*[7]���ٿռ�                       *\n");
    printf("\t====================================\n");
    printf("Your Order IS: ");
}

void how(Status hw)                                                                        /* ��������״̬ */
{
    if(hw == 1)
    {
        printf("�����ɹ���\n");
    }
    else
    {
        printf("����ʧ��\n");
    }
}

void name(char *na_me)                                                                     /* �û��������� */ 
{
    printf("Please enter your name:");
    gets(na_me);
    system("pause");
    system("cls");
}
