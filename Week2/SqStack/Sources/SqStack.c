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
                                                                
    if(s == NULL || sizes <= 0)                                     /* 检查是否成功分配内存 */
    {
        return ERROR;                                               /* 分配失败返回ERROR */
    }
    else
    {   
        s->elem = (ElemType *)malloc(sizeof(ElemType)*sizes);      /* 分配成功，初始化一个指定长度的栈 */

        if(s->elem == NULL)                                        /* 检查是否成功分配内存 */
        {
            return ERROR;                                     
        }
        else
        {
            s->top = -1;                                           /* 先设置为-1，后面压栈的时候在增加 */
        }      
    }

    return SUCCESS;                                                /* 返回成功 */
} 


/**
 *  @name        : Status isEmptyStack(SqStack *s)
 *	@description : To check if the stack is empty 
 *	@param		 : s(The pointer to the necessary struct of stack)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status isEmptyStack(SqStack *s)//判断栈是否为空
{                                                                   /* 空的情况：有未初始化时候 或者 没有元素压栈的时候 */
    return (s == NULL || s->top == -1 ? SUCCESS : ERROR);           /* 判断为空，则返回成功 */
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
    if(s == NULL)                                                   /* 防止用户未初始化就进行获值操作 */
    {
        return ERROR;                                            
    }
    else if(s->top != -1)
    {   
        *e = s->elem[s->top];                                       /* 给 用来获值的变量 赋值 */                          
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
Status clearStack(SqStack *s)//清空栈
{
    if(s == NULL)                                                  /* 防止用户未初始化就进行获值操作 */
    {
      return ERROR;                                            
    }
    else
    {
        s->top = -1;                                               /* 将栈顶调整为-1，这样在之后重新压栈时，栈会被重新赋值 */
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
Status destroyStack(SqStack *s)//销毁栈
{
    if(s == NULL)
    {
        return SUCCESS;                                            /* 原本就是不存在栈，为了让客户清楚是空的就返回成功，返回失败看起来是出现问题的情况 */
    }
    else
    {
        free(s->elem);                                             /* 将栈空间释放，让指针指向NULL */
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
        return ERROR;                                                     /* 原本就是不存在栈，为了让客户清楚是空的就返回成功，返回失败看起来是出现问题的情况 */
    }
    else
    {
        *length = (s->top)+1;                                             /* +1的原因是数组从0开始 */
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
Status pushStack(SqStack *s,ElemType data)//入栈
{
    if(s==NULL )                                                   /* 未初始化的栈不能压栈 */
    {
        return ERROR;
    }
    else
    {
        s->top ++;                                                /* 将头部向上一单位，准备压栈 */
        (s->elem)[s->top] = data;                                 /* 压栈 */
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
Status popStack(SqStack *s,ElemType *data)//出栈
{
    if(s == NULL || s->top == -1)                                  /* 未初始化或者栈为空，则不能出栈 */
    {
        return ERROR;
    }
    else
    {
        *data = s->elem[s->top];                                   /* 出栈 */
        s->top--;                                                  /* 弹出后调整栈顶位置 */
    }
    
    return SUCCESS;
}
