#include"../Headers/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * ��ջ�ṹ����ӵ��һ���յĽ��
 * �ڸÿս����һ����㴢������
 * ���Իؿճ�һ���ս��
 */


/**
 *  @name        : Status initLStack(LinkStack *s)
 *	@description : To initialize an empty stack
 *	@param		 : s(The pointer to the top struct of stack)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status initLStack(LinkStack *s)//��ʼ��ջ
{
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(s->top == NULL)
    {                                                              /* ����ռ�ʧ�� */
       return  ERROR;
    }
    else
    {
        s->top->next = NULL;                                       /* ��ס�ײ� */
    }

    return SUCCESS;
}


/**
 *  @name        : Status isEmptyLStack(LinkStack *s)
 *	@description : To detect if an empty stack
 *	@param		 : s(The pointer to the top struct of stack)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if(s == NULL || s->top->next == NULL)
    {
        return SUCCESS;                                            /* Ϊ�գ����سɹ� */
    }
    else
    {
        return ERROR;
    }
    
}


/**
 *  @name        : Status getTopLStack(LinkStack *s,ElemType *e)
 *	@description : To get the value of the top 
 *	@param		 : s(The pointer to the top struct of stack)
 *                 e(The deliver of value at the top stack )
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
    if (s != NULL && s->top->next != NULL)                          /* ����Ƿ�Ϊ�� */
    {
        *e = s->top->data;                                          /* ��ֵ */
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
    
}


/**
 *  @name        : Status clearLStack(LinkStack *s)
 *	@description : To clear the Stack
 *	@param		 : s(The pointer to the necessary struct of stack)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status clearLStack(LinkStack *s)//���ջ
{
    if (isEmptyLStack(s))
    {
        return ERROR;
    }
    else
    {
        LinkStackPtr free_p = s->top;                                /* ������һ��ָ�룬������ */
        while (s->top->next != NULL)                                 /* ֱ����ʣһ���ײ���� */
        {
            s->top = s->top->next;
            free(free_p);
            free_p = s->top;
        }
        return SUCCESS;
    }
    
}


/**
 *  @name        : Status destroyLStack(LinkStack *s)
 *	@description : To destroy the stack
 *	@param		 : s(The pointer to the top struct of stack)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status destroyLStack(LinkStack *s)//����ջ
{
    if (isEmptyLStack(s))                           
    {
        return ERROR;
    }
    else
    {
        LinkStackPtr free_p = s->top;               
        while (s->top != NULL)
        {
            s->top = s->top->next;
            free(free_p);
            free_p = s->top;
        }
    }
    free(s);                                                        /* �ͷ�������ڴ� */
    s = NULL;
    
    return SUCCESS;
}


/**
 *  @name        : Status LStackLength(LinkStack *s,int *length)
 *	@description : To detect the length of the stack
 *	@param		 : s(The pointer to the necessary struct of stack)
 *                 length(The pointer of the length of stack )
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status LStackLength(LinkStack *s,int *length)//���ջ����
{
    *length = 0;                                                    /* ��ʼ��Ϊ0 */
    if (isEmptyLStack(s))                                           /* �ж��Ƿ�Ϊ�� */             
    {
        return ERROR;
    }
    else
    {   
        LinkStackPtr t_p = s->top;
        while(t_p->next != NULL)
        {
            (*length) ++;                                             /* ÿ����һ����㣬�Զ�+1���� */
            t_p = t_p->next;
        }
    }
    return SUCCESS;
}


/**
 *  @name        : Status pushLStack(LinkStack *s,ElemType data)
 *	@description : To push a data into new node of the stack
 *	@param		 : s(The pointer to the necessary struct of stack)
 *                 data(The data to be pushed into )
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
    LinkStackPtr new_top = NULL;
    new_top = (LinkStackPtr)malloc(sizeof(StackNode));                  /* �����µĽ��׼���洢data */
    if(new_top == NULL)                                                 /* �ж��Ƿ�ɹ�����ռ� */
    {
        return ERROR;
    }
    
    else
    {
        new_top->data = data;   
        new_top->next = s->top;                                         /* ���Ӻ���һ�������½�� */
        s->top = new_top;                                               /* �����µ�ջ��ָ�� */
    }

    return SUCCESS;               
}


/**
 *  @name        : Status popLStack(LinkStack *s,ElemType *data)
 *	@description : To pop the data on the top of the stack
 *	@param		 : s(The pointer to the necessary struct of stack)
 *                 sizes(The length of stack )
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
    if(isEmptyLStack(s))
    {
        return ERROR;
    }
    else
    {
        *data = s->top->data;                                            /* ��ֵ */ 
        s->top = s->top->next;                                           /* ��ջ */ 
    }
    return SUCCESS;
}
