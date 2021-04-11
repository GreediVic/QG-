#include<stdio.h>
#include<stdlib.h>
#include"../Headers/LQueue.h"
#define MAXLENGTH 30
#define INT '1'
#define DOUBLE '2'
#define CHAR '3'
#define STRING '4'
/**
 *  @name        : Menu();
 *	@description : menu for users to select
 *	@param		 : None
 *	@return		 : None
 *  @notice      : None
 */

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
    if (Q->front!= NULL && Q->front->next == NULL)
    {
        printf("队列已初始化，无需重复进行！\n");
        return;
    }
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if (Q->front == NULL || Q->rear == NULL) {
		printf("内存分配失败！\n");
		return ;
	}
    Q->front->type = NULL;
	Q->length = 0;
    Q->front->next = NULL;
    printf("初始化完毕！\n");
}
void InitAQueueAtBegining(LQueue* Q) {
    Q->front = Q->rear = (Node*)malloc(sizeof(Node));
    if (Q->front == NULL || Q->rear == NULL) {
        printf("内存分配失败！\n");
        return ;
    }
    Q->front->type = NULL;
    Q->length = 0;
    Q->front->next = NULL;
}
/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
    if (Q->front == NULL) {
        printf("队列已销毁，请先进行初始化！\n");
        return;
    }
    else {
        if(IsEmptyLQueue(Q)==FALSE){
            ClearLQueue(Q);
        }
        free(Q->front);
        Q->front = NULL;
        printf("销毁完毕！\n");
    }
}

/**
 *  @name        : Status isEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
    if (Q->front == NULL) {
        printf("队列已销毁，请先进行初始化！\n");
        return -1;
    }
    else if (Q->front == Q->rear) return TRUE;
    else return FALSE;
    //printf("队列为空！\n");

}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void** e) {
    if (Q->front == NULL) {
        printf("队列已销毁，请先进行初始化！\n");
        return FALSE;
    }
    else if (IsEmptyLQueue(Q)) {
        printf("队列为空，队头元素不存在！\n");
        return FALSE;
    }
    *e = Q->front->next->data;
    printf("队头元素的值为：");
    LPrint(*e,Q->front->next->type);
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {   
    if (Q->front == NULL) {
        printf("队列已销毁，请先进行初始化！\n");
        return -1;
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = (void*)malloc(MAXLENGTH);
    if (p == NULL) {
        printf("内存分配失败！\n");
        return FALSE;
    }
    memcpy(p->data, data, MAXLENGTH);
    p->type = typeEle;
    Q->rear->next = p;
    Q->rear = p;
    Q->rear->next = NULL;
    Q->length++;
    printf("入队成功！\n");
    return TRUE;
}
void typeChoose(LQueue* Q) {
    if (Q->front == NULL) {
        printf("队列已销毁，请先进行初始化！\n");
        return FALSE;
    }
    int flag;
    char type;
    printf("请问入队元素是何种类型？\n");
    printf("1.整型\n2.浮点型\n3.字符型\n4.字符串\n");
    do
    {
        flag = 0;
        type = '0';
        scanf_s("%c", &type, sizeof(char));
        if (getchar() != '\n') {
            printf("不存在该选项，请重试！\n");
            flag = 1;
            while (getchar() != '\n');
        }
        else if (type > '4' || type < '1') {
            printf("不存在该选项，请重试！\n");
            flag = 1;
        }
    } while (flag);
    switch (type)
    {
    case INT: {
        int temp;
        do
        {
            flag = 0;
            printf("请输入元素的值(大小为 -32768 到 32767)：");
            scanf_s("%18d", &temp);
            if (getchar() != '\n') {
                printf("输入有误，请重试！\n");
                flag = 1;
                while (getchar() != '\n');
            }
            else if (!(temp < 32767 && temp > -32768)) {
                flag = 1;
                printf("输入有误，请重试！\n");
            }
        } while (flag);
        typeEle = INT;
        EnLQueue(Q, &temp);
    }; break;
    case DOUBLE: {
        double temp;
        do
        {
            flag = 0;
            printf("请输入一个浮点数作为元素的值：");
            scanf_s("%lf", &temp);
            if (getchar() != '\n') {
                printf("输入有误，请重试！\n");
                flag = 1;
                while (getchar() != '\n');
            }
        } while (flag);
        typeEle = DOUBLE;
        EnLQueue(Q, &temp);
    }; break;
    case CHAR: {
        char temp;
        do
        {
            flag = 0;
            printf("请输入一个字符作为元素的值：");
            scanf_s("%c", &temp, sizeof(char));
            if (getchar() != '\n') {
                printf("输入有误，请重试！\n");
                flag = 1;
                while (getchar() != '\n');
            }
        } while (flag);
        typeEle = CHAR;
        EnLQueue(Q, &temp);
    }; break;
    case STRING: {
        char* temp = (char*)malloc(MAXLENGTH * sizeof(char));
        do
        {
            flag = 0;
            printf("请输入一个字符串(长度小于30字节)作为元素的值：");
            scanf_s("%30s", temp, MAXLENGTH + 2);//最多30字符，+1以除去\0
            if (getchar() != '\n') {
                printf("输入有误，请重试！\n");
                flag = 1;
                while (getchar() != '\n');
            }
        } while (flag);
        typeEle = STRING;
        EnLQueue(Q, temp);
    }; break;
    default:
        break;
    }
}
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
    if (Q->front == NULL) {
        printf("队列已销毁，请先进行初始化！\n");
        return FALSE;
    }
    else if (IsEmptyLQueue(Q)) {
        printf("队列为空，无元素可出列！\n");
        return FALSE;
    }
    else if(Q->front->next == Q->rear){
        free(Q->rear);
        Q->rear = Q->front;
        Q->front->next = NULL;
    }
    else {
        Node* p;
        p = Q->front->next;
        Q->front->next = Q->front->next->next;
        free(p);
    }
    Q->length--;
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status ClearLQueue(LQueue* Q) {
    if (Q->front == NULL) {
        printf("队列已销毁，请先进行初始化！\n");
        return FALSE;
    }
    else if (IsEmptyLQueue(Q)) {
        printf("队列为空，无需重复清空！\n");
        return FALSE;
    }
    else {
        Node* p, * q;
        p = Q->front->next;
        Q->rear= Q->front;
        while (p)
        {
            q = p;
            p = p->next;
            free(q);
        }
        q = NULL;
    }
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
    if (Q->front == NULL) {
        printf("队列已销毁，请先进行初始化！\n");
        return FALSE;
    }
    else if (IsEmptyLQueue(Q)) {
        printf("队列为空，无元素可遍历！\n");
        return FALSE;
    }
    Node* p = Q->front->next;
    int cnt = 0;
    while (p)
    {
        printf("第 %d 个元素为：", ++cnt);
        foo(p->data, p->type);
        p = p->next;
    }
    printf("遍历完成！\n");
    return TRUE;
}
/**
 *  @name        : void LPrint(void *q,char type)
 *    @description : 操作函数
 *    @param         q 指针q,type类型

 *  @notice      : None
 */
void LPrint(void* q,char type) {
    if (type == INT) {
        printf("%d\n", *(int*)q);
    }
    else if (type == DOUBLE) {
        printf("%g\n", *(double*)q);
    }
    else if (type == CHAR) {
        printf("%c\n", *(char*)q);
    }
    else if (type == STRING) {
        printf("%s\n", (char*)q);
    }
}