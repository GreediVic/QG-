#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "duLinkedList.h"
DuLinkedList *L  = NULL; 
int nodes = 0; 
void visit(ElemType e){
	printf("%d  ",e);
}
void inform_cus(int State)                                            
      /* Tell user if the work is done normally */
{
    if(State){
        printf("Success!\n");
    }
    else{
        printf("ERROR!");
    }
}
DuLNode *Lookfor(DuLinkedList L, int e){
    DuLinkedList p = L;     
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
void Functions_menu()                                                 {
    printf("\t============================================================\n");
    printf("\t=If you want to use [2] [3],please always use function 6. ==\n");
    printf("\t============================================================\n");
    printf("\t*[1]Create One Unite                     (InitList_DuL)    *\n");
    printf("\t*[2]Insert nodes Front                   (InsertBefore)    *\n");
    printf("\t*[3]Insert nodes Back                    (InsertAfter)     *\n");
    printf("\t*[4]Delete node                          (DeleteList_DuL)  *\n");
    printf("\t*[5]See all information you have put in  (TraverseList_DuL)*\n");
    printf("\t*[6]Search the number of the node you want(from 0~the last)*\n");
    printf("\t*--------------------------------[191]DestroyList_DuL------*\n");
    printf("\t============================================================\n");
    printf("\t=If you want to use [2] [3],please always use function 6. ==\n");
    printf("\t============================================================\n");
    printf("Now ,nodes:%d\n",nodes);
    printf("Your Order IS: ");
}
void ask(){
    printf("If you have known the A stress,you can press '1' to continue.\n\
            If not, please press '2' use other functions to get it.");
}
int main()
{
    
    DuLNode *p       = NULL;
    DuLNode *q       = NULL;
    DuLinkedList L_L = NULL; 
    ElemType *e      = NULL;
    int A_in_2       = 0;
    int order        = 0;
    int number       = 0;
    L  = (DuLinkedList *)malloc(sizeof(DuLinkedList));
    Status State;

    printf("Welcome to use the Functions made BY @VIC.\n");
    printf("Any questions please contact the e_mail : 3347506455@qq.com\n");
    system("pause");
    system("cls");
    while(1){
        Functions_menu();
        scanf("%d",&order);
        switch(order){

                case 1:{
                    State = InitList_DuL(L);                                /* get the status */
                    Sleep(300);
                    inform_cus(State);
                    system("pause");
                    system("cls");
                    break;
                }
        
               
                      
                case 2:{
                    DuLNode *q = (DuLNode *)malloc(sizeof(DuLNode)); 
                    printf("Which node would you like to search:  ");
                    scanf("%d",&number);
                    p = Lookfor(*L, number);
                    State = InsertBeforeList_DuL(p, q);
                    inform_cus(State);
                    system("pause");
                    system("cls");
                    
                     break;            
                 }           
                

                case 3:{
                    DuLNode *q = (DuLNode *)malloc(sizeof(DuLNode)); 
                    printf("Which node would you like to search:  ");
                    scanf("%d",&number);
                    p = Lookfor(*L, number);
                    scanf("%d",&A_in_2);
                    State = InsertAfterList_DuL(p, q);
                    inform_cus(State);
                    system("pause");
                    system("cls");
                     break;            
                }    

                case 4:{
                    e = (ElemType *)malloc(sizeof(ElemType));
                    printf("Which node would you like to search:  ");
                    scanf("%d",&number);
                    p = Lookfor(*L, number);
                    State = DeleteList_DuL(p, e);
                    printf("%d\n",*e);
                    printf("\nOver!");
                    system("pause");
                    system("cls");
                    free(e);
                    e = NULL;
                    break;
                }

                case 5:{
                    if(nodes!=0)
                    {
                    TraverseList_DuL(*L, visit);
                    system("pause");
                    system("cls");
                    }
                    system("cls");                    
                    break;
                }

                case 6:{
                    printf("Which node would you like to search:  ");
                    scanf("%d",&number);
                    p = Lookfor(*L, number);
                    if(!p){
                    printf("Couldn't find the node\n");
                    system("pause");
                    system("cls");
                    }
                    else{
                        printf("Found!You can use the function [2] [3] to function\n");
                        system("pause");
                        system("cls");
                    }
                    break;           
                }

                case 191:{
                    DestroyList_DuL(L);
                    printf("Done!");
                    system("pause");
                    system("csl");
                    break;
                }
        }
            if(order==191)
            break;
    }
    return 0;
}

