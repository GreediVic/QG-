#include"binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>

/**
* ����ʵ�ַǵݹ������ջ���߶��� 
*/
typedef struct Stack {
	NodePtr nodes[100];																		/* ���������Ľ�� */  
	int top;																				/* ջ��������ӵ�λ�� */  
	int tail;																				/* ��β����ջ��ʱ��û��ʹ��������� */  
}stack;



/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr BSTR)
{
	BSTR->root = (NodePtr)malloc(sizeof(Node));												/* ��ʼ���� */
	BSTR->root->value = (int)BSTR->root;													/* ��Ϊһ���������������廹û����ֵ���� */
	if (!BSTR->root)
	{
		printf("��ʼ��ʧ�ܣ�\n");
		return failed;
	}
	BSTR->root->left = NULL;																/* ��ס���������Ŀ� */
	BSTR->root->right = NULL;	
	printf("��ʼ���ɹ���\n");

	return succeed;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr BSTR, ElemType a)
{
	if (BSTR->root->value == (int)BSTR->root)												/* �ж��Ƿ�û����ֵ */
	{
		BSTR->root->value = a;
		return succeed;
	}
	NodePtr pre;																			/* ��pre����temp��ǰ�����ְ֣� */
	NodePtr temp = BSTR->root;																/* ��tempȥ���� */
	NodePtr insert_p = (NodePtr)malloc(sizeof(Node));										
	insert_p->value = a;																	/* �ȸ�ֵ */
	insert_p->left = insert_p->right = NULL;												/* ��׼����Ҫ��������� */
	while (temp)	
	{
		pre = temp;																			/* pre����һ�� */
		if (a < temp->value)																/* ��tempȥ������С������������ */
			temp = temp->left;														
		else
			temp = temp->right;
	}
	if (a < pre->value)																		/* ��һ�£��ҵ��˺󣬿�һ�������ϱߵ����������� */
		pre->left = insert_p;
	else
		pre->right = insert_p;
	return succeed;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr BSTR, ElemType a)
{
	if (!BSTR->root)
	{
		printf("û������");
		return failed;
	}
	else
	{
		NodePtr root = BSTR->root;															/* ֻ�Ƿ������� */
		NodePtr temp = BSTR->root;
		NodePtr parent = BSTR->root;
		int child = 0;																		/* �����ж�����ڸ��ڵ���������� */
		while (temp)
		{
			if (a < temp->value)															/* ����Ǳ���С��������� */
			{
				child = 0;																	/* ��¼������һ���ڵ����� */
				parent = temp;																/* �������� */
				temp = temp->left;
			}
			else if (a > temp->value)
			{
				child = 1;																	/* ͬ�� */
				parent = temp;
				temp = temp->right;
			}
			if (temp && a == temp->value)													/* ������·�9����� */
			{
				if (!temp->left && !temp->right)											/* ������������Ӷ�Ϊ�� */
				{		
					if (temp == root)													
					{
						free(temp);															/* ����Ǹ��ҵ��˾�ֱ��ɾ�� */
						temp = NULL;
						return succeed;														/* ���� */
					}
					else if (child == 0)													/*�����ǰ�ڵ�λ����һ���ڵ����*/
					{
						free(temp);															/* ɾ�� */
						parent->left = NULL;												/* ��ס����� */
						return succeed;
					}
					else if (child == 1)
					{
						free(temp);
						parent->right = NULL;												/* ͬ�� */
						return succeed;
					}
				}
				else if (!temp->left)														/* ��ǰ�ڵ�����ӿ� */
				{
					if (child == 0)															/* ��ǰ�ڵ�ʱ��һ���ڵ������ */
						parent->left = temp->right;
					else
						parent->right = temp->right;
				}
				else if (!temp->right)														/* �Һ��ӿ� */
				{
					if (child == 0)															/* ��ǰ�ڵ�����һ���ڵ������ */
						parent->left = temp->left;
					else
						parent->right = temp->left;
				}
				else if (temp->left && temp->right)
				{
					NodePtr pre=NULL;
					NodePtr del_temp = temp;												/* ������ڵ� */
					temp = temp->right;
					if (!temp->left)														/* һ��ʼû����ڵ� */												
					{
						del_temp->value = temp->value;										/* ֱ�����ҽڵ���� */
						if (!temp->right)													/* ����ҽڵ�û���ҽڵ� */
							del_temp->right = NULL;											/* �����ֱ�ӷ�ס�ұߵĽڵ� */
						else
							del_temp->right = temp->right;									/* �����  ���temp���ҽڵ㵱��Ҫɾ���ڵ���ҽڵ� */
						return succeed;
					}
					while (temp->left)														/* �������ڵ㣬ֱ���ҵ��ײ� */
					{
						pre = temp;
						temp = temp->left;
					}
					if (!temp->right)														/* �ײ��ڵ�û���ҽڵ� */
						pre->left = NULL;													/* ֱ�Ӱѵ�ǰ�ڵ�ɾ�� */
					else
						pre->left = temp->right;											/* ���У��ײ��ҽڵ㻻����һ������ڵ� */
					del_temp->value = temp->value;
					free(temp);
					return succeed;
				}
				return succeed;
			}
		}
	}
	return failed;
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr BSTR, ElemType a)
{
	if (!BSTR->root)
	{
		printf("���Ȳ�������!");
	}
	NodePtr temp = BSTR->root;																/* ���������� */
	while (temp)
	{
		if (temp->value == a)																/* ������ �ͷ��� */
		{
			return true;
		}
		else
		{
			if (a < temp->value)															/* ���ݷ���Ѱ�� */
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	return false;																			/* �Ҳ������˳� */
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr BSTR, void (*visit)(NodePtr root))
{
	stack sNODES;																			/* ��ʼ��ջ */
	sNODES.top = -1;																		/* �տ�ʼ��������Ϊ-1 */
	if (BSTR->root)																			/* �жϲ��ǿյ��� */
	{
		NodePtr temp;										
		sNODES.nodes[++(sNODES.top)] = BSTR->root;											/* �����ڵ�ѹ��ջ�� */
		while (sNODES.top != -1)															/* ջ��Ϊ�� */
		{
			temp = sNODES.nodes[(sNODES.top)--];											/* ��ջ */
			visit(temp);
			if (temp->right != NULL)														/* �������������ҽڵ� */
				sNODES.nodes[++(sNODES.top)] = temp->right;									/* �Ƚ����ӽڵ�ѹ��ջ�� */
			if (temp->left != NULL)															/* �ٽ���ڵ�ѹ�� */
				sNODES.nodes[++(sNODES.top)] = temp->left;									/* ��Ϊ��վ�����Ǻ���ջ���ȳ� */
		}
		return succeed;
	}
	else
	{
		printf("��Ϊ��!");
		return failed;
	}
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr root, void (*visit)(NodePtr root))
{
	if (!root)
	{
		return succeed;
	}
	else
	{
		visit(root);																			/* ���򣬸� �� �� */
		BST_preorderR(root->left,visit);
		BST_preorderR(root->right, visit);
		return succeed;
	}
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */


Status BST_inorderI(BinarySortTreePtr BSTR, void (*visit)(NodePtr root))
{
	if (!BSTR->root)
	{
		printf("���ȳ�ʼ����");
		return failed;
	}
	stack sNODES;																			/* ��ʼ��ջ */
	sNODES.top = -1;
	NodePtr temp = BSTR->root;
	while (temp != NULL || sNODES.top != -1)												/* ��ջ��Ϊ�ջ����нڵ� */
	{
		if (temp != NULL)
		{
			sNODES.nodes[++(sNODES.top)] = temp;											/* ��Ϊ�վ�ѹջ */
			temp = temp->left;														
		}
		else																				/* ջ��Ҳ�����µ�����ǰ�������� */
		{
			temp = sNODES.nodes[(sNODES.top)--];											/* ��ǰΪ�գ�û�оͷ��ص�ջ�������ҳ�ջ */
			visit(temp);																	/* ���ջ��Ԫ�� */
			temp = temp->right ;															/* ��ǰָ������ҽڵ� */
		}																					
	}
	return succeed;
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr root, void (*visit)(NodePtr root))
{
	if (!root)
	{
		return succeed;
	}
	else
	{
		
		BST_inorderR(root->left, visit);													/* �� �� �� */
		visit(root);
		BST_inorderR(root->right, visit);
		return succeed;
	}
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr BSTR, void (*visit)(NodePtr root))
{
	stack sNODES;																			/* ��ʼ�� */
	sNODES.top = -1;
	NodePtr lastVisit = NULL;																/* ��¼ÿ���ڵ���ʴ���ջ */
	NodePtr temp = BSTR->root;
	while (temp)																			/* һ·�ߵ��� */
	{
		sNODES.nodes[++(sNODES.top)] = temp;
		temp = temp->left;
	}
	while (sNODES.top != -1)
	{
		temp = sNODES.nodes[(sNODES.top)--];												/* ��ǰ��������Ƿ񱻷��� */
		if (temp->right == NULL || temp->right == lastVisit)
		{
			visit(temp);																	/* ��������ʾͿ��Դ�Ӧ��ǰ�ڵ����� */
			lastVisit = temp;
		}
		else
		{
			sNODES.nodes[++(sNODES.top)] = temp;											/* �ұ�û�б����� */
			temp = temp->right;
			while (temp)
			{
				sNODES.nodes[++(sNODES.top)] = temp;
				temp = temp->left;
			}
		}
	}
	return succeed;
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr root, void (*visit)(NodePtr root))
{
	if (!root)
	{
		return succeed;
	}
	else
	{
		BST_postorderR(root->left, visit);
		BST_postorderR(root->right, visit);													/* �� �� �� */
		visit(root);
		return succeed;
	}
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr BSTR, void (*visit)(NodePtr root))
{
	{
		stack q;  
		q.top = 0;																			/* �Ӷ������ */
		q.tail = 0;																			/* ���֮�󶥲�����������ӵĴ�β������ */
		q.nodes[q.top++] = BSTR->root;														/* ��һ��ʼ */

		while (q.top > q.tail)																/* ����������Ԫ�� */
		{
			if (q.nodes[q.tail])															/* ���β����Ԫ�� */
			{
				visit(q.nodes[q.tail]);														/* ���� */
				q.nodes[q.top++] = q.nodes[q.tail]->left;									/* �ȷ��������� */
				q.nodes[q.top++] = q.nodes[q.tail]->right;									/* �ٷ��������� */
			}
			q.tail++;																		/* ���ʺ�β��++��׼����һ�εķ��� */
		}
	}
	return succeed;
}

