#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
extern int nodes;
extern LinkedList *L_addr;  
Status InitList(LinkedList *L) {

        if(nodes==0)
        nodes++;                                           /* count the nodes */
        (*L) = (LNode *)malloc(sizeof(LNode));
        if(*L == NULL)
            return WRONG;
        
        (*L) -> next = NULL;
            return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
                         
    LinkedList *After_L;
    while((*L)!= NULL){
        *After_L = (*L)->next;
        free(*L);                                         
        *L = *After_L;
    }
                                    
}
/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {

    if(p == NULL){                                                /* to check whether the p node is empty */
    
        return WRONG;
    }     
    LinkedList *p1 = &p,*q1 = &q;               
    (*q1)->next = (*p1)->next;                                    /* connect in the middle */
    (*p1)->next = *q1;
    nodes++;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {

    if(p == NULL || p->next == NULL)
		return WRONG;
	LNode *q;
	q = p->next;
	*e = q->data;		//记得调用前检查e是否有指向一个已知的内存空间
	p->next = q->next;
	free(q);
    nodes--;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {

    LinkedList p = L;       
	while(p != NULL){                                                      /* easily traverse the List */  
		(*visit)(p->data);
		p = p->next;
	}

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {

    LinkedList p = L;                       
	while(p != NULL){
		if(p->data == e)                                  /* according to e, find the first node */
			return SUCCESS;
		else
			p = p->next;
	}
	return WRONG;
}
LNode *SearchList_0(LinkedList L, int e){
    LinkedList p = L;     
    if(p->next == NULL)                                    /* 只有一个结点就返回这个 */
    {
        return L;
    }                  
	while(p->next != NULL && e>0){                         /* 不然就遍历到指定结点处 */
			p = p->next;
            e--;
	}
    if(e==0)         
        return L;
	return NULL;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L)
{
	if(!(*L) && !(*L)->next)
		return WRONG;
	LNode *front, *mid, *last;		
	front = *L;
	mid = (*L)->next;			
	front->next = NULL;
	while(mid){
		last = mid->next;		
		mid->next = front;		
		front = mid;				
		mid = last;
	}
	*L = front;					
	return SUCCESS;
}
/**  递归实现
 *LinkedList ReverseList(LinkedList L) {
 *
 *    if(L == NULL || L->next == NULL)
 *       return L;
 *    else{
 *        LinkedList P = ReverseList(L->next);
 *        L->next->next = L;
 *        L->next = NULL;
 *        return P;
 *    }
 */

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {

    LinkedList fast = L, slow = L;		                                   	/* Start together at the same place */
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;			
		fast = fast->next->next;	
		if(fast == slow)
			return SUCCESS;
	}
	return WRONG;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

    LNode *front, *mid, *last;		//定义前中后指针，用途和反转相似
	front = *L;
	*L = front->next;
	while(front && front->next){
		mid = front->next;
		last = mid->next;
		if(mid->next && mid->next->next){			//如果mid->last不存在，结点个数为偶数
			front->next = mid->next->next;			//如果mid->last->last不存在，结点个数为奇数
		}else{										//如果都存在，遍历未结束
			front->next = mid->next;
		}
		mid->next = front;							//将偶数结点反转
		front = last;
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {

    int i_BOOK = 0; 
    LNode *Fast = *L, *Slow = *L;
    LNode *p = NULL;
    while((*L)->next->next != NULL && \
        (Fast->next->next != NULL ||Fast->next != NULL)){        /* 229th to check whether there are 3 nodes and whether reach the end */
        i_BOOK = 1;
        Fast = Fast->next->next;
        Slow = Slow->next;
    }
    if(i_BOOK==1)  {
        return Slow;
    }                                                             /* i_BOOK to book if 229th satisfied  */

    else
    return *L;                                                    /* No matter 0|1|2 nodes, return the node L  */

}

