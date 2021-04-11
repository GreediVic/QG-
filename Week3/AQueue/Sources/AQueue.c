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
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    int i;
	Q->length = MAXQUEUE;                               /* 设置长度为十的队列 */
    for(i = 0; i < MAXQUEUE; i++)
    {
        Q->data[i] = (void *)malloc(21);                /* 队列中的每个单位开辟一个较大的空间 */
    }    
	Q->front = Q->rear = -1;                             /* 调整队尾对头位置 */
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
    if(Q->data[0] == NULL)                              /* 检查是否有初始化好的队列 */
    {
        printf("无队列，操作失败\n");                    /* 没有则提示失败 */
        return;
    }
	for(int i = 0; i < MAXQUEUE; i++)                   /* 若有，则逐个清空 */
    {
            free(Q->data[i]);                           /* 清空操作 */
    }
	Q->data[0] = NULL;                                  /* 清空后将对头指向NULL */
    printf("操作成功！\n");
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(AQueue *Q)
{
    if(Q->data[0] == NULL)                              /* 判断是否已经初始化 */
    {
        printf("队列尚未初始化\n");
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("队列目前未初始化！请先初始化队列！\n");
        return FALSE;
    }
    return (Q->front == Q->rear == -1 ? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if (IsEmptyAQueue(Q))
	{
		printf("队列为空！\n");
		return FALSE;
	}
	memcpy(e, Q->data[Q->front],20);                    /* 将当前队头地址的20个字节复制给e */
    return TRUE;
}		


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    if(Q->data[0] == NULL)                              /* 若头部为空，则没初始化 */
    {
        printf("队列尚未初始化！\n");
        return 0;
    }
    return (Q->length + Q->rear - Q->front) % Q->length ;
}	


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
    if (IsFullAQueue(Q))
	{
		printf("队列已满！\n");
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列为空！\n");
        return FALSE;
    }
    Q->front = (Q->front+1) % Q->length;                  /* 队头后移一个单位 */ 
    return TRUE;
}	


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    if (IsEmptyAQueue(Q))
	{
		printf("队列空！\n");
		return;
	}
    Q->front = Q->rear = 0;                             /* 清空，队头和队尾相同为初始0位置 */
    printf("操作成功！\n");
}	


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(AQueue *Q, void (*foo)(void *q))
{
    if (IsEmptyAQueue(Q))
    {
        printf("队列为空!\n");
        return FALSE;
    }
    int i = 0;
    int time = MAXQUEUE;
    // while (i < Q->front + Q->rear)
    while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE)              /* 只要i不大于队头队尾之间的距离，就能继续遍历 */
    {
        type = datatype[(Q->front+i )% MAXQUEUE];
        foo(Q->data[(Q->front+i) % MAXQUEUE]);                                       /* 输出函数，需要判断类型 */
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}


/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
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
        printf("请先初始化列表\n");
        return;
    }
    printf("请输入入队类型？:\n");
    printf("d. 整型 s. 字符(串)型 f. 浮点型 \n");
    scanf("%c", &type);
    while(type != 'd' && type != 's' && type != 'f')
    {
     	printf("应输入以上选项！\n请重输：");
      	scanf("%c", &type);
    }
	printf("想入队的数据 :");
    switch(type)
    {
     	case 'd':
        {
			int a;
			scanf("%d", &a);                                             /* 按照格式输入 */
            if (EnAQueue(Q, &a))
                // if (IsEmptyAQueue(Q))
                //     datatype[Q->front] = 'd';
                // else
            {
                datatype[Q->rear] = 'd';                                 /* 记录类型 */
                printf("输入成功！\n");
            }   
		    break;
		}                                                                /* 下同 */

		case 's':
        {
			char a[20];
			printf("不可大于20个字符~\n");
			scanf("%s", a);
            if (EnAQueue(Q, a))
                // if (IsEmptyAQueue(Q))
                //     datatype[Q->front] = 's';
                // else
            {
                datatype[Q->rear] = 's';
                printf("输入成功！\n");
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
                   printf("输入成功！\n");
            }
			break;
		}
       
    }
}