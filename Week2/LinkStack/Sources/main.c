#include "../Headers/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    
    void name(char *na_me);                                                     /* �����û����� */ 
    void how(Status hw);                                                        /* ����״̬��ʾ */ 
    void menu();                                                                /* չʾ�˵� */
    Status check_name(char *na_me);                                             /* ɾ���������ǰ��ѯ�ʰ�ȫ���� */
    ElemType *e = NULL;                                                         /* ��������ջ��Ԫ��  */
    LinkStack *s = NULL;                                                        /* ������ջ����Դ */
    ElemType *data;                                                             /* �������ݳ�ջԪ�� */
    ElemType data_data;                                                         /* ��������ѹջԪ�� */
    Status hw;                                                                  /* �����нӺ�������״̬ */
    char cases[200000];                                                         /* �н��û������ѡ�� */
    char na_me[100000];                                                         /* �û����Ʊ��� */
    int *length = NULL;
    int c;                                                                      /* ������ǿ���뽡׳�Եı��� */
    int times = 0;                                                              /* ����Ƿ��Ѿ���ʼ����0���� 1���ǣ� */
    name(na_me);
    while (1)
    {
        printf("Welcome:%s\n\n",na_me);                                          /* �û����� */
        menu();                                                                  /* �˵�չʾ */ 
        scanf("%s",cases);
        while(!(cases[0]>='0'&&cases[0]<='7'&&cases[1]=='\0'))                   /* ����û��Ƿ�Ϸ����� */
        {
            printf("����Ƿ����������룺");
            scanf("%s",cases);
        }
        c = cases[0]-48;


        switch (c)
        {
            case 0:
            {
                if (times == 0)                                                   /* �ж��Ƿ���γ�ʼ�� */
                {
                    s = (LinkStack *)malloc(sizeof(LinkStack));
                    how(initLStack(s));
                    times++;
                }
                else
                {
                    printf("���Ѿ���ʼ����ջ����Ҫ���³�ʼ�������Ʋ��Ƚ�������ԭ����Ŷ��\n");
                }
                
                system("pause");
                system("cls");
                break; 
            }


            case 1:
            {
                if(s!=NULL)                                                           /* �����Ϊ�� */
                {
                    printf("��������Ҫ��¼��ֵ(����ֵ̫���������ֵŶ)��");
                    scanf("%d",&data_data);
                    if(data_data <= -200000000 || data_data >= 200000000)              /* ����ϵͳ���� */
                    {
                        printf("�Բ��𣬵�ǰ�汾��֧�ּ�����ֵ��̫�����̫С��\n");
                    }
                    else
                    {
                        how(pushLStack(s, data_data));                                  /* ѹջ */
                    }    
                }
                else
                {
                    printf("���ȳ�ʼ��ջ\n");
                }
                

                system("pause");
                system("cls");
                break;
            }


            case 2:
            {
                hw = isEmptyLStack(s);                                                  /* �ж�ջ�Ƿ�Ϊ�� */              
                if(hw)
                {
                    printf("ջΪ�գ�û��Ԫ�ؿ��Գ�ջ��\n");
                }
                else
                {
                    data = (ElemType *)malloc(sizeof(ElemType));
                    how(popLStack(s, data));                                            /*  */
                    printf("��ջԪ��Ϊ%d\n",*data);
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
                how(hw = LStackLength(s, length));                                      /* ���ջ���ȣ������ؼ��״̬��ʾ */
                if(hw)
                printf("ջ�ĳ���Ϊ��%d\n",*length);                                     /* ��ʾ���� */
                
                free(length);
                length = NULL;
                system("pause");
                system("cls");
                break;
            }
            
            case 4:
            {
                e = (ElemType *)malloc(sizeof(ElemType));
                how(hw = getTopLStack(s, e));                                            /* ������ɺ���ȡջ����ֵ���񣬲���ʾ״̬ */
                if (hw)                                                                  /* ���ɹ������֪ջ��Ԫ����ʲô */
                {
                   printf("���һ���������%d\n",*e);
                }
                
                free(e);
                e = NULL;
                system("pause");
                system("cls");
                break;
            }
            
            case 5:
            {
                hw = isEmptyLStack(s);                                                     /* �ж�ջ�Ƿ�Ϊ�� */              
                if(hw)
                {
                    printf("ջΪ�գ�\n");
                }
                else
                {
                    printf("ջ��Ϊ�գ�\n");
                }
                
                system("pause");
                system("cls");
                break;
            }
            
            case 6:
            {
                if(isEmptyLStack(s) == 0)                                                 /* �жϲ�Ϊ�� */
                {
                    if(check_name(na_me)==1)                                             /* �������֮ǰ�ٴ�ѯ�ʲ����� */
                    {
                        printf("���ȷ��!");
                        how(clearLStack(s));                                             /* ����clear�����ҷ��سɹ���ʾ */
                    }
                }

                system("pause");
                system("cls");
                break;
            }
            
            case 7:
            {
                if(isEmptyLStack(s) == 0)                                                 /* �жϴ洢���ݲ�Ϊ�� */
                {
                    if(check_name(na_me)==1)                                             /* �������֮ǰ�ٴ�ѯ�ʲ����� */ 
                    {
                        printf("���ȷ��!");
                        how(destroyLStack(s));                                            /* �ݻ�ջ�����ز�����״̬ */
                        times = 0;                                                       /* �൱��û�г�ʼ����ջ�������ʼ�� */
                        s = NULL;
                    }
                }
                else                                                                     /* �洢����Ϊ�գ����Դݻ�ջ */
                {
                    destroyLStack(s);
                    printf("�����ɹ���\n");
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

void how(Status hw)                                                            /* ��������״̬ */
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
    }
    return ERROR;
}