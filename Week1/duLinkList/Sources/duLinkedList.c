#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
extern int nodes;
extern DuLinkedList *L;
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	if(nodes==0)
        nodes++;    
    *L = (DuLinkedList)malloc(sizeof(DuLinkedList));         
	if(*L == NULL)												/* check if room can be created */
		return WRONG;									
	(*L)->next = NULL;                                  
	(*L)->prior = NULL;
	return SUCCESS;

}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {

    DuLinkedList p;												
	while(*L != NULL){
		p = (*L)->next;
		free(*L);
		*L = p;
		if(p != NULL)											/* make the former one NULL */
			p->prior = NULL;
	}
    
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {

    if(p == NULL)
		return WRONG;
	if(p->prior != NULL){
		p->prior->next = q;                                      /* make the former's tail connect new node */
		q->prior = p->prior;									 /* make the later's head connect the former */
		
	}
	q->next = p;												 /* connect the new with p*/
	p->prior = q;
	if(nodes==1){
	*L = q;
	}
	nodes++;
	return SUCCESS;

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {

    if(p == NULL)												/* check whether p is empty */
		return WRONG;
	if(p->next){								
		p->next->prior = q;										/* the same way as  InsertBeforeList_DuL*/
	 	q->next = p->next;
	}
	nodes++;
	q->prior = p;
	p->next  = q;
	q->next  = NULL;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {

	DuLNode *q = NULL;
    if(p == NULL || p->next == NULL)
		return WRONG;
	q = p->next;
	*e = q->data;											/* assign its value to e */
	q->next->prior = p;										/* kick the mid_one out */
	p->next = q->next;
	free(q);
	nodes--;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    
    DuLNode *p = L;
	while(p){
		(*visit)(p->data);
		p = p->next;
	}
}

