#include"binary_sort_tree.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int menu();                                                                             /* �˵� */
    int get_digit();                                                                        /* ����������� */
    void response(int state);                                                               /* �������غ���״̬ */
    void visit(NodePtr root);                                                               /* �������ڵ�ĺ��� */
    int cases = 0;
    BinarySortTreePtr BSTR = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    BST_init(BSTR);                                                                         /* ��ʼ�� */
    while (1)
    {
        cases = menu();
        switch (cases)
        {
        case 1:
        {
            ElemType insert_num;
            insert_num = get_digit();                                                       /* �û����� */
            response(BST_insert(BSTR, insert_num));                                         /* ���� */
            break;
        }
        case 2:
        {
            ElemType search_num;
            search_num = get_digit();
            if (BST_search(BSTR, search_num)) printf("���ڴ�����");
            else printf("�����ڴ�����");
            break;
        }
        case 3:
        {
            ElemType del_num;
            del_num = get_digit();
            response(BST_delete(BSTR, del_num));
            break;
        }
        case 4:
        {
            response(BST_preorderR(BSTR->root, visit));
            break;
        }
        case 5:
        {
            response(BST_inorderR(BSTR->root, visit));
            break;
        }
        case 6:
        {
            response(BST_postorderR(BSTR->root, visit));
            break;
        }
        case 7:
        {
            response(BST_preorderI(BSTR, visit));
            break;
        }
        case 8:
        {
            response(BST_inorderI(BSTR, visit));
            break;
        }
        case 9:
        {
            response(BST_postorderI(BSTR, visit));
            break;
        }
        case 10:
        {
            response(BST_levelOrder(BSTR, visit));
            break;
        }
        default:
            break;
        }
        system("pause");
        system("cls");
        if (cases == 11)    break;
    }
	return 0;
}

int menu()
{
    char cases[10] = { '\0' };
    printf("\t=========����������==========\n");
    printf("\t*[1]��������                *\n");
    printf("\t*[2]��������                *\n");
    printf("\t*[3]ɾ������                *\n");
    printf("\t*[4]�ݹ�ǰ�����            *\n");
    printf("\t*[5]�ݹ��������            *\n");
    printf("\t*[6]�ݹ�������            *\n");
    printf("\t*[7]����ǰ�����            *\n");
    printf("\t*[8]�����������            *\n");
    printf("\t*[9]�����������            *\n");
    printf("\t*[10]�������               *\n");
    printf("\t*[11]�˳�����               *\n");
    printf("\t=============================\n");
    printf("Your Order IS: ");
    scanf("%s", cases);
    while (!((cases[0] > '0' && cases[0] <= '9' && cases[1] == '\0')||\
        ((cases[0]=='1' && cases[1]=='0' || cases[1]=='1')&&(cases[2]=='\0')) ))            /* ����û��Ƿ�Ϸ����� */
    {
        printf("����Ƿ����������룺");
        scanf("%s", cases);
    }
    return cases[1] == '\0' ? (cases[0] - 48) : (10 * (cases[0] - 48) + cases[1] - 48);     /* �������� */
}

void visit(NodePtr root)
{
    printf(">>%d\n", root->value);
}

int get_digit()
{
    int number = 0;                                                                         /* �������������� */
    int _positive_ = -1;                                                                    /* -1�Ǹ� */
    int flag = 1;                                                                           /* 1ͨ�� 0��ͨ�� */
    ElemType input;   
    char num[100] = { '\0' };
    printf("����в���������(ֻ����6λ����)��");
    scanf("%s", num);
    while (1)
    {
        for (int i = 0; (num[0] == '-' ? i < 7 : i < 6) && num[i]!='\0'; i++)               /* ֻ������λ��Ч���� */
        {
            if (i == 0 && (num[0] >= '0' || num[0] <= '9' || num[0] == '-'))
            {

                if (num[0] != '-') _positive_ = 1;                                          /* �ж������� */
                else _positive_ = -1;
                flag = 1;
            }
             if (i != 0 && (num[i] >= '0' || num[i] <= '9'))                                /* ÿ�ζ����ÿһ���ַ��Ƿ����Ҫ�� */
            {
                flag = 1;   
            }
             else if(i != 0 && !(num[i] >= '0' || num[i] <= '9'))
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1) break;
        printf("����������Ϸ����֣�\n");
        printf("����в���������(ֻ����6λ����)��");
        memset(num, 0, sizeof(num));
        scanf("%s", num);
    }
    if (_positive_ == 1)
    {
        number = 0;
        for (int i = 0; i < 6 && num[i] != '\0'; i++)
        {
            number = number*10 + (num[i] - 48);
        }
    }
    else
    {
        number = 0;
        for (int i = 0; i < 7 && num[i] != '\0'; i++)
        {
            if(i!=0&&num[0]=='-')
                number = number * 10 + ((int)(num[i] - 48))*(-1);
            if(num[0]!='-')
                number = number * 10 + ((int)(num[i] - 48)) * (-1);
        }
    }

    return number;
}

void response(int state)
{
    if (state)
        printf("�����ɹ���");
    else
    {
        printf("����ʧ��!");
    }
}