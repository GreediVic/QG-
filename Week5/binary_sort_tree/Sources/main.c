#include"binary_sort_tree.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int menu();                                                                             /* 菜单 */
    int get_digit();                                                                        /* 用来检测输入 */
    void response(int state);                                                               /* 用来返回函数状态 */
    void visit(NodePtr root);                                                               /* 访问树节点的函数 */
    int cases = 0;
    BinarySortTreePtr BSTR = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    BST_init(BSTR);                                                                         /* 初始化 */
    while (1)
    {
        cases = menu();
        switch (cases)
        {
        case 1:
        {
            ElemType insert_num;
            insert_num = get_digit();                                                       /* 用户输入 */
            response(BST_insert(BSTR, insert_num));                                         /* 插入 */
            break;
        }
        case 2:
        {
            ElemType search_num;
            search_num = get_digit();
            if (BST_search(BSTR, search_num)) printf("存在此数字");
            else printf("不存在此数字");
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
    printf("\t=========二叉排序树==========\n");
    printf("\t*[1]插入数字                *\n");
    printf("\t*[2]查找数字                *\n");
    printf("\t*[3]删除数字                *\n");
    printf("\t*[4]递归前序遍历            *\n");
    printf("\t*[5]递归中序遍历            *\n");
    printf("\t*[6]递归后序遍历            *\n");
    printf("\t*[7]迭代前序遍历            *\n");
    printf("\t*[8]迭代中序遍历            *\n");
    printf("\t*[9]迭代后序遍历            *\n");
    printf("\t*[10]层序遍历               *\n");
    printf("\t*[11]退出程序               *\n");
    printf("\t=============================\n");
    printf("Your Order IS: ");
    scanf("%s", cases);
    while (!((cases[0] > '0' && cases[0] <= '9' && cases[1] == '\0')||\
        ((cases[0]=='1' && cases[1]=='0' || cases[1]=='1')&&(cases[2]=='\0')) ))            /* 检测用户是否合法输入 */
    {
        printf("输入非法请重新输入：");
        scanf("%s", cases);
    }
    return cases[1] == '\0' ? (cases[0] - 48) : (10 * (cases[0] - 48) + cases[1] - 48);     /* 返回整型 */
}

void visit(NodePtr root)
{
    printf(">>%d\n", root->value);
}

int get_digit()
{
    int number = 0;                                                                         /* 用来输出输入的数 */
    int _positive_ = -1;                                                                    /* -1是负 */
    int flag = 1;                                                                           /* 1通过 0不通过 */
    ElemType input;   
    char num[100] = { '\0' };
    printf("请进行操作的数字(只接受6位整数)：");
    scanf("%s", num);
    while (1)
    {
        for (int i = 0; (num[0] == '-' ? i < 7 : i < 6) && num[i]!='\0'; i++)               /* 只接受六位有效数字 */
        {
            if (i == 0 && (num[0] >= '0' || num[0] <= '9' || num[0] == '-'))
            {

                if (num[0] != '-') _positive_ = 1;                                          /* 判断正负数 */
                else _positive_ = -1;
                flag = 1;
            }
             if (i != 0 && (num[i] >= '0' || num[i] <= '9'))                                /* 每次都检测每一个字符是否符合要求 */
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
        printf("请重新输入合法数字！\n");
        printf("请进行操作的数字(只接受6位整数)：");
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
        printf("操作成功！");
    else
    {
        printf("操作失败!");
    }
}