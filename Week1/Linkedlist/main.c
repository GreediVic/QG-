#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "linkedList.h"
int nodes = 0; 
LinkedList *L_addr;  
void visit(ElemType e) 
{
	printf("%d ",e);
}
void inform_cus(int State)
{
    if(State == 1){
        printf("Success!\n");
    }
    else{
        printf("ERROR!Please try agiain in the legal way.");
    }
}
void Functions_menu()
{
    printf("\t============================================================\n");
    printf("\t=If you want to use [2] [3],please always use function 6. ==\n");
    printf("\t============================================================\n");
    printf("\t*[1]Create One Unite                      (InitList)       *\n");
    printf("\t*[2]Insert Info B after Info A            (InsertList)     *\n");
    printf("\t*[3]Get its DATA that will be deleted     (DeleteList)     *\n");
    printf("\t*[4]See all information                   (TraverseList)   *\n");
    printf("\t*[5]Check the unit with datas you want    (SearchList)     *\n");
    printf("\t*[6]Search the number of the node you want(SearchList_0)   *\n");
    printf("\t*[7]Reverse the information               (ReverseList)    *\n");
    printf("\t*[8]Check if the list loop                (IsLoopList)     *\n");
    printf("\t*[9]Reverse EvenList                      (ReverseEveList) *\n");
    printf("\t*[10]Find MidNode                          (FindMidNode)   *\n");
    printf("\t*--------------------------------[191]Destroy All Units----*\n");
    printf("\t============================================================\n");
    printf("\t=If you want to use [2] [3],please always use function 6. ==\n");
    printf("\t============================================================\n");
    printf("Now nodes : %d\n",nodes);
    printf("Your Order IS: ");
}

int main()
{
    LNode *p           = NULL;
    LNode *L           = NULL;    
    ElemType *e        = NULL;
    int A_in_2         = 0;
    int number         = 0;
    L_addr             = (LinkedList *)malloc(sizeof(LinkedList));
    Status State;

    printf("Welcome to use the Functions made BY @VIC.\n");
    printf("Any questions please contact the e_mail : 3347506455@qq.com\n");
    system("pause");
    system("cls");
    while(1){
    int order;
    Functions_menu();
    scanf("%d",&order);

    switch(order)
        {
            p = NULL;
            case 1:{
                State = InitList(L_addr);
                Sleep(300);
                L = (*L_addr);
                inform_cus(State);
                system("pause");
                system("cls");
                break;
            }
       
            case 2:{
                LNode *q = (LNode *)malloc(sizeof(LNode));
                printf("If you have konwn the 'A' node,just press '1'\nOR please press others and use Function 6 to search it.\n");
                scanf("%d",&A_in_2);
                if(A_in_2==1){

                    State = InsertList(p, q);
                    inform_cus(State);
                    system("pause");
                    system("cls");
                }
                break;            
            }

            case 3:{
                e = (ElemType *)malloc(sizeof(ElemType));
                State = DeleteList(p, e);
                inform_cus(State);
                if(State == 1)
                {
                    printf("%d",*e);
                }
                system("pause");
                system("cls");
                free(e);
                e=NULL;
                break; 
            } 

            case 4:{
            	if(nodes != 0) 
                TraverseList(*L_addr, visit);
                printf("\nOver!");
                system("pause");
                system("cls");
                break;
            }

            case 5:{
                printf("Which data would you like to Check:  ");
                e = (ElemType *)malloc(sizeof(ElemType));
                scanf("%d",e);
                State = SearchList(L, *e);
                inform_cus(State);
                system("pause");
                system("cls");
                free(e);
                e=NULL;
                break;
            }

            case 6:{
                printf("Which node would you like to search:  ");
                scanf("%d",&number);
                p = SearchList_0(L, number);
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

            case 7:{
                State = ReverseList(L_addr);
                inform_cus(State);
                system("pause");
                system("cls");
                break;
            }

            case 8:{
                State = IsLoopList(L);
                inform_cus(State);
                system("pause");
                break;
            } 

            case 9:{
                L = ReverseEvenList(L_addr);
                printf("Done!");
                system("pause");
                system("cls");
                break;
            }

            case 10:{
                p = FindMidNode(L_addr);
                printf("Done!");
                system("pause");
                system("csl");
                break;
            } 

            case 191:{
                DestroyList(L_addr);
                printf("Done!");
                system("pause");
                system("csl");
                break;
            } 
        }
        system("cls");
        if(order==191)
        break;
    }
    return 0;
}

