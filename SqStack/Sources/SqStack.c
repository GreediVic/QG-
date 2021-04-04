#include "../Headers/SqStack.h"
#include<stdio.h>
#include<stdlib.h>


/**
 *  @name        : Status initStack(SqStack *s,int sizes)
 *	@description : To initialize an empty stack
 *	@param		 : s(The pointer to the necessary struct of stack)
 *                 sizes(The length of stack )
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status initStack(SqStack *s,int sizes)
{
                                                                
    if(s == NULL || sizes <= 0)                                     /* ����Ƿ�ɹ������ڴ� */
    {
        return ERROR;                                               /* ����ʧ�ܷ���ERROR */
    }
    else
    {   
        s->elem = (ElemType *)malloc(sizeof(ElemType)*sizes);      /* ����ɹ�����ʼ��һ��ָ�����ȵ�ջ */

        if(s->elem == NULL)                                        /* ����Ƿ�ɹ������ڴ� */
        {
            return ERROR;                                     
        }
        else
        {
            s->top = -1;                                           /* ������Ϊ-1������ѹջ��ʱ�������� */
        }      
    }

    return SUCCESS;                                                /* ���سɹ� */
} 


/**
 *  @name        : Status isEmptyStack(SqStack *s)
 *	@description : To check if the stack is empty 
 *	@param		 : s(The pointer to the necessary struct of stack)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{                                                                   /* �յ��������δ��ʼ��ʱ�� ���� û��Ԫ��ѹջ��ʱ�� */
    return (s == NULL || s->top == -1 ? SUCCESS : ERROR);           /* �ж�Ϊ�գ��򷵻سɹ� */
}                                                               


/**
 *  @name        : Status getTopStack(SqStack *s,ElemType *e)
 *	@description : To get the element at the top of the stack
 *	@param		 : s(The pointer to the necessary struct of stack)
 *                 e(the pointer used to pass the element at the top of stack)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status getTopStack(SqStack *s,ElemType *e)
{
    if(s == NULL)                                                   /* ��ֹ�û�δ��ʼ���ͽ��л�ֵ���� */
    {
        return ERROR;                                            
    }
    else if(s->top != -1)
    {   
        *e = s->elem[s->top];                                       /* �� ������ֵ�ı��� ��ֵ */                          
    } 

    return SUCCESS;       
}


/**
 *  @name        : Status clearStack(SqStack *s)
 *	@description : To set the value of top to -1
 *	@param		 : s(The pointer to the necessary struct of stack)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status clearStack(SqStack *s)//���ջ
{
    if(s == NULL)                                                  /* ��ֹ�û�δ��ʼ���ͽ��л�ֵ���� */
    {
      return ERROR;                                            
    }
    else
    {
        s->top = -1;                                               /* ��ջ������Ϊ-1��������֮������ѹջʱ��ջ�ᱻ���¸�ֵ */
    }

    return SUCCESS;    
}


/**
 *  @name        : Status destroyStack(SqStack *s)
 *	@description : To destroy the stack and free the room 
 *	@param		 : s(The pointer to the necessary struct of stack) 
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status destroyStack(SqStack *s)//����ջ
{
    if(s == NULL)
    {
        return SUCCESS;                                            /* ԭ�����ǲ�����ջ��Ϊ���ÿͻ�����ǿյľͷ��سɹ�������ʧ�ܿ������ǳ����������� */
    }
    else
    {
        free(s->elem);                                             /* ��ջ�ռ��ͷţ���ָ��ָ��NULL */
        s->elem = NULL;
        free(s);
        s = NULL;
    }
    
    return SUCCESS;
}


/**
 *  @name        : Status stackLength(SqStack *s,int *length)
 *	@description : To detecte the length of the stack
 *	@param		 : s(The pointer to the necessary struct of stack) 
 *                 length (length of the stack) 
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status stackLength(SqStack *s,int *length)
{
    if(s == NULL)
    {
        *length = 0;  
        return ERROR;                                                     /* ԭ�����ǲ�����ջ��Ϊ���ÿͻ�����ǿյľͷ��سɹ�������ʧ�ܿ������ǳ����������� */
    }
    else
    {
        *length = (s->top)+1;                                             /* +1��ԭ���������0��ʼ */
    }

    return SUCCESS;
}


/**
 *  @name        : Status pushStack(SqStack *s,ElemType data)
 *	@description : To push the data into the stack
 *	@param		 : s(The pointer to the necessary struct of stack) 
 *                 data(The data you want to push into)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status pushStack(SqStack *s,ElemType data)//��ջ
{
    if(s==NULL )                                                   /* δ��ʼ����ջ����ѹջ */
    {
        return ERROR;
    }
    else
    {
        s->top ++;                                                /* ��ͷ������һ��λ��׼��ѹջ */
        (s->elem)[s->top] = data;                                 /* ѹջ */
    }
    
    return SUCCESS;
}


/**
 *  @name        : Status popStack(SqStack *s,ElemType *data)
 *	@description : To pop the lates element for data to deliver 
 *	@param		 : s(The pointer to the necessary struct of stack) 
 *                 data(To deliver the element)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status popStack(SqStack *s,ElemType *data)//��ջ
{
    if(s == NULL || s->top == -1)                                  /* δ��ʼ������ջΪ�գ����ܳ�ջ */
    {
        return ERROR;
    }
    else
    {
        *data = s->elem[s->top];                                   /* ��ջ */
        s->top--;                                                  /* ���������ջ��λ�� */
    }
    
    return SUCCESS;
}
