#define _CRT_SECURE_NO_WARNINGS
#include"../Headers/AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern char type;
/**************************************************************
 *    Prototype Realize Section
 **************************************************************/

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    int i;
	Q->length = MAXQUEUE;                               /* ���ó���Ϊʮ�Ķ��� */
    for(i = 0; i < MAXQUEUE; i++)
    {
        Q->data[i] = (void *)malloc(21);                /* �����е�ÿ����λ����һ���ϴ�Ŀռ� */
    }    
	Q->front = Q->rear = -1;                             /* ������β��ͷλ�� */
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
    if(Q->data[0] == NULL)                              /* ����Ƿ��г�ʼ���õĶ��� */
    {
        printf("�޶��У�����ʧ��\n");                    /* û������ʾʧ�� */
        return;
    }
	for(int i = 0; i < MAXQUEUE; i++)                   /* ���У��������� */
    {
            free(Q->data[i]);                           /* ��ղ��� */
    }
	Q->data[0] = NULL;                                  /* ��պ󽫶�ͷָ��NULL */
    printf("�����ɹ���\n");
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(AQueue *Q)
{
    if(Q->data[0] == NULL)                              /* �ж��Ƿ��Ѿ���ʼ�� */
    {
        printf("������δ��ʼ��\n");
        return FALSE;
    }  
    if (LengthAQueue(Q) == MAXQUEUE - 1)
    {
        return TRUE;
    }
    else
        return FALSE;
}


/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("����Ŀǰδ��ʼ�������ȳ�ʼ�����У�\n");
        return FALSE;
    }
    return (Q->front == Q->rear == -1 ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if (IsEmptyAQueue(Q))
	{
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front],20);                    /* ����ǰ��ͷ��ַ��20���ֽڸ��Ƹ�e */
    return TRUE;
}		


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    if(Q->data[0] == NULL)                              /* ��ͷ��Ϊ�գ���û��ʼ�� */
    {
        printf("������δ��ʼ����\n");
        return 0;
    }
    return (Q->length + Q->rear - Q->front) % Q->length ;
}	


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data)
{
    if (IsFullAQueue(Q))
	{
		printf("����������\n");
		return FALSE;
	}
    if ((Q->rear == Q->front)&&(Q->front == -1))
    {
        Q->rear = Q->front = 0;
        memcpy(Q->data[Q->front], data, 20);
    }
    else
    {
        Q->rear = (Q->rear + 1) % MAXQUEUE;
        memcpy(Q->data[Q->rear], data, 20);
    }
    return TRUE;
}


/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("����Ϊ�գ�\n");
        return FALSE;
    }
    Q->front = (Q->front+1) % Q->length;                  /* ��ͷ����һ����λ */ 
    return TRUE;
}	


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    if (IsEmptyAQueue(Q))
	{
		printf("���пգ�\n");
		return;
	}
    Q->front = Q->rear = 0;                             /* ��գ���ͷ�Ͷ�β��ͬΪ��ʼ0λ�� */
    printf("�����ɹ���\n");
}	


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(AQueue *Q, void (*foo)(void *q))
{
    if (IsEmptyAQueue(Q))
    {
        printf("����Ϊ��!\n");
        return FALSE;
    }
    int i = 0;
    int time = MAXQUEUE;
    // while (i < Q->front + Q->rear)
    while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE)              /* ֻҪi�����ڶ�ͷ��β֮��ľ��룬���ܼ������� */
    {
        type = datatype[(Q->front+i )% MAXQUEUE];
        foo(Q->data[(Q->front+i) % MAXQUEUE]);                                       /* �����������Ҫ�ж����� */
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}


/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void* q) 
{
    printf("\n");
    if (type == 'd') 
    {
        printf(">>%d\n", *(int*)q);
    }
    else if (type == 'f') 
    {
        printf(">>%lf\n", *(double*)q);
    }
    else if (type == 's') 
    {
        printf(">>%s\n", (char*)q);
    }
}

void def(AQueue *Q)
{
    if (Q->data[0] == NULL)
    {
        printf("���ȳ�ʼ���б�\n");
        return;
    }
    printf("������������ͣ�:\n");
    printf("d. ���� s. �ַ�(��)�� f. ������ \n");
    scanf("%c", &type);
    while(type != 'd' && type != 's' && type != 'f')
    {
     	printf("Ӧ��������ѡ�\n�����䣺");
      	scanf("%c", &type);
    }
	printf("����ӵ����� :");
    switch(type)
    {
     	case 'd':
        {
			int a;
			scanf("%d", &a);                                             /* ���ո�ʽ���� */
            if (EnAQueue(Q, &a))
                // if (IsEmptyAQueue(Q))
                //     datatype[Q->front] = 'd';
                // else
            {
                datatype[Q->rear] = 'd';                                 /* ��¼���� */
                printf("����ɹ���\n");
            }   
		    break;
		}                                                                /* ��ͬ */

		case 's':
        {
			char a[20];
			printf("���ɴ���20���ַ�~\n");
			scanf("%s", a);
            if (EnAQueue(Q, a))
                // if (IsEmptyAQueue(Q))
                //     datatype[Q->front] = 's';
                // else
            {
                datatype[Q->rear] = 's';
                printf("����ɹ���\n");
            }
            
			break;
		}
        
        case 'f':
        {
			double a ;
			scanf("%lf", &a);
            if (EnAQueue(Q, &a))
                // if (IsEmptyAQueue(Q))
                //     datatype[Q->front] = 'f';
                // else
            {
                datatype[Q->rear] = 'f';
                   printf("����ɹ���\n");
            }
			break;
		}
       
    }
}