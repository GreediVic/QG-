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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
    if (Q->front!= NULL && Q->front->next == NULL)
    {
        printf("�����ѳ�ʼ���������ظ����У�\n");
        return;
    }
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if (Q->front == NULL || Q->rear == NULL) {
		printf("�ڴ����ʧ�ܣ�\n");
		return ;
	}
    Q->front->type = NULL;
	Q->length = 0;
    Q->front->next = NULL;
    printf("��ʼ����ϣ�\n");
}
void InitAQueueAtBegining(LQueue* Q) {
    Q->front = Q->rear = (Node*)malloc(sizeof(Node));
    if (Q->front == NULL || Q->rear == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        return ;
    }
    Q->front->type = NULL;
    Q->length = 0;
    Q->front->next = NULL;
}
/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
    if (Q->front == NULL) {
        printf("���������٣����Ƚ��г�ʼ����\n");
        return;
    }
    else {
        if(IsEmptyLQueue(Q)==FALSE){
            ClearLQueue(Q);
        }
        free(Q->front);
        Q->front = NULL;
        printf("������ϣ�\n");
    }
}

/**
 *  @name        : Status isEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
    if (Q->front == NULL) {
        printf("���������٣����Ƚ��г�ʼ����\n");
        return -1;
    }
    else if (Q->front == Q->rear) return TRUE;
    else return FALSE;
    //printf("����Ϊ�գ�\n");

}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue* Q, void** e) {
    if (Q->front == NULL) {
        printf("���������٣����Ƚ��г�ʼ����\n");
        return FALSE;
    }
    else if (IsEmptyLQueue(Q)) {
        printf("����Ϊ�գ���ͷԪ�ز����ڣ�\n");
        return FALSE;
    }
    *e = Q->front->next->data;
    printf("��ͷԪ�ص�ֵΪ��");
    LPrint(*e,Q->front->next->type);
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {   
    if (Q->front == NULL) {
        printf("���������٣����Ƚ��г�ʼ����\n");
        return -1;
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* Q, void* data) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = (void*)malloc(MAXLENGTH);
    if (p == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        return FALSE;
    }
    memcpy(p->data, data, MAXLENGTH);
    p->type = typeEle;
    Q->rear->next = p;
    Q->rear = p;
    Q->rear->next = NULL;
    Q->length++;
    printf("��ӳɹ���\n");
    return TRUE;
}
void typeChoose(LQueue* Q) {
    if (Q->front == NULL) {
        printf("���������٣����Ƚ��г�ʼ����\n");
        return FALSE;
    }
    int flag;
    char type;
    printf("�������Ԫ���Ǻ������ͣ�\n");
    printf("1.����\n2.������\n3.�ַ���\n4.�ַ���\n");
    do
    {
        flag = 0;
        type = '0';
        scanf_s("%c", &type, sizeof(char));
        if (getchar() != '\n') {
            printf("�����ڸ�ѡ������ԣ�\n");
            flag = 1;
            while (getchar() != '\n');
        }
        else if (type > '4' || type < '1') {
            printf("�����ڸ�ѡ������ԣ�\n");
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
            printf("������Ԫ�ص�ֵ(��СΪ -32768 �� 32767)��");
            scanf_s("%18d", &temp);
            if (getchar() != '\n') {
                printf("�������������ԣ�\n");
                flag = 1;
                while (getchar() != '\n');
            }
            else if (!(temp < 32767 && temp > -32768)) {
                flag = 1;
                printf("�������������ԣ�\n");
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
            printf("������һ����������ΪԪ�ص�ֵ��");
            scanf_s("%lf", &temp);
            if (getchar() != '\n') {
                printf("�������������ԣ�\n");
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
            printf("������һ���ַ���ΪԪ�ص�ֵ��");
            scanf_s("%c", &temp, sizeof(char));
            if (getchar() != '\n') {
                printf("�������������ԣ�\n");
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
            printf("������һ���ַ���(����С��30�ֽ�)��ΪԪ�ص�ֵ��");
            scanf_s("%30s", temp, MAXLENGTH + 2);//���30�ַ���+1�Գ�ȥ\0
            if (getchar() != '\n') {
                printf("�������������ԣ�\n");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
    if (Q->front == NULL) {
        printf("���������٣����Ƚ��г�ʼ����\n");
        return FALSE;
    }
    else if (IsEmptyLQueue(Q)) {
        printf("����Ϊ�գ���Ԫ�ؿɳ��У�\n");
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
Status ClearLQueue(LQueue* Q) {
    if (Q->front == NULL) {
        printf("���������٣����Ƚ��г�ʼ����\n");
        return FALSE;
    }
    else if (IsEmptyLQueue(Q)) {
        printf("����Ϊ�գ������ظ���գ�\n");
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
    if (Q->front == NULL) {
        printf("���������٣����Ƚ��г�ʼ����\n");
        return FALSE;
    }
    else if (IsEmptyLQueue(Q)) {
        printf("����Ϊ�գ���Ԫ�ؿɱ�����\n");
        return FALSE;
    }
    Node* p = Q->front->next;
    int cnt = 0;
    while (p)
    {
        printf("�� %d ��Ԫ��Ϊ��", ++cnt);
        foo(p->data, p->type);
        p = p->next;
    }
    printf("������ɣ�\n");
    return TRUE;
}
/**
 *  @name        : void LPrint(void *q,char type)
 *    @description : ��������
 *    @param         q ָ��q,type����

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