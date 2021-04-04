#include"../Headers/LinkStack.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * 该栈结构是先拥有一个空的结点
 * 在该空结点上一个结点储存内容
 * 所以回空出一个空结点
 */


/**
 *  @name        : Status initLStack(LinkStack *s)
 *	@description : To initialize an empty stack
 *	@param		 : s(The pointer to the top struct of stack)
 *	@return		 : The status :SUCCESS or ERROR
 *  @notice      : None
 */
Status initLStack(LinkStack *s)//初始化栈
{
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(s->top == NULL)
    {                                                              /* 分配空间失败 */
       return  ERROR;
    }
    else
    {
        s->top->next = NULL;                                       /* 封住底部 */
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
Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
    if(s == NULL || s->top->next == NULL)
    {
        return SUCCESS;                                            /* 为空，返回成功 */
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
Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
    if (s != NULL && s->top->next != NULL)                          /* 检测是否为空 */
    {
        *e = s->top->data;                                          /* 赋值 */
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
Status clearLStack(LinkStack *s)//清空栈
{
    if (isEmptyLStack(s))
    {
        return ERROR;
    }
    else
    {
        LinkStackPtr free_p = s->top;                                /* 借助多一个指针，逐个清空 */
        while (s->top->next != NULL)                                 /* 直到仅剩一个底部结点 */
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
Status destroyLStack(LinkStack *s)//销毁栈
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
    free(s);                                                        /* 释放最初的内存 */
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
Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
    *length = 0;                                                    /* 初始化为0 */
    if (isEmptyLStack(s))                                           /* 判断是否为空 */             
    {
        return ERROR;
    }
    else
    {   
        LinkStackPtr t_p = s->top;
        while(t_p->next != NULL)
        {
            (*length) ++;                                             /* 每遍历一个结点，自动+1长度 */
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
Status pushLStack(LinkStack *s,ElemType data)//入栈
{
    LinkStackPtr new_top = NULL;
    new_top = (LinkStackPtr)malloc(sizeof(StackNode));                  /* 创建新的结点准备存储data */
    if(new_top == NULL)                                                 /* 判断是否成功分配空间 */
    {
        return ERROR;
    }
    
    else
    {
        new_top->data = data;   
        new_top->next = s->top;                                         /* 连接好上一个结点和新结点 */
        s->top = new_top;                                               /* 调整新的栈顶指针 */
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
Status popLStack(LinkStack *s,ElemType *data)//出栈
{
    if(isEmptyLStack(s))
    {
        return ERROR;
    }
    else
    {
        *data = s->top->data;                                            /* 赋值 */ 
        s->top = s->top->next;                                           /* 出栈 */ 
    }
    return SUCCESS;
}
