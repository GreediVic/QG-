#define _CRT_SECURE_NO_WARNINGS
#include "../Headers/AQueue.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    extern char type;                                           /* ����ȫ��type������ʹ�� */
    void menu();                                                /* �����˵� */
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
            printf("������Ϸ��ַ���");
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
                    printf("��ʼ���ɹ�\n");
                    times = 1;
                }
                else
                {
                    printf("���Ѿ���ʼ������Ҫ�����ٲ���ִ�д˲���\n");
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
                    printf("�����ɹ�!");
                }
                system("pause");
                system("cls");
                break;
            }       
            case 3:
            {
                if (TraverseAQueue(Q, APrint))
                {
                    printf("�����ɹ���\n");
                }
                else
                    printf("����ʧ��!\n");
                system("pause");
                system("cls");
                break;
            }

            case 4:
            {
                if (IsEmptyAQueue(Q))
                {
                    printf("�����ɹ���\n");
                }
                else
                {
                    printf("������\n");
                }
                system("pause");
                system("cls");
                break;
            }           

            case 5:
            {
                if (IsFullAQueue(Q))
                {
                    printf("�����ɹ���\n");
                }
                else
                    printf("����δ��!\n");
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
                printf("���г��ȣ�%d\n",a);
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
                    printf("���ٳɹ�");
                    Q->length = 0;
                    times = 0;
                }
                else
                {
                    printf("����δ��ʼ�����У����ȳ�ʼ��\n");
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
            printf("�������˳���\n");
            system("pause");
            break;
        }
    }123

    return 0;
}


void menu()                                                                             
{
    printf("\t=====================\n");
    printf("\t*[0]��ʼ������       *\n");
    printf("\t*[1]��β��������     *\n");
    printf("\t*[2]ɾ����ͷ����     *\n");
    printf("\t*[3]������������     *\n");
    printf("\t*[4]����Ƿ�������   *\n");
    printf("\t*[5]����Ƿ�������   *\n");    
    printf("\t*[6]��ն�������     *\n");
    printf("\t*[7]��ȡ���г���     *\n");
    printf("\t*[8]��ȡ��ͷ����     *\n");
    printf("\t*[9]���ٶ�������     *\n");        
    printf("\t=====================\n");
    printf("��ѡ�����: ");
}

