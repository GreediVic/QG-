#include"binary_sort_tree.h"
#include<stdio.h>
#include<stdlib.h>

/**
* 用来实现非递归遍历的栈或者队列 
*/
typedef struct Stack {
	NodePtr nodes[100];																		/* 用来存树的结点 */  
	int top;																				/* 栈顶或者入队的位置 */  
	int tail;																				/* 队尾，用栈的时候没有使用这个变量 */  
}stack;



/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr BSTR)
{
	BSTR->root = (NodePtr)malloc(sizeof(Node));												/* 初始化树 */
	BSTR->root->value = (int)BSTR->root;													/* 作为一个特征，用来定义还没有数值的树 */
	if (!BSTR->root)
	{
		printf("初始化失败！\n");
		return failed;
	}
	BSTR->root->left = NULL;																/* 封住左右子树的口 */
	BSTR->root->right = NULL;	
	printf("初始化成功！\n");

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
	if (BSTR->root->value == (int)BSTR->root)												/* 判断是否还没有数值 */
	{
		BSTR->root->value = a;
		return succeed;
	}
	NodePtr pre;																			/* 用pre当做temp的前辈（爸爸） */
	NodePtr temp = BSTR->root;																/* 用temp去搜索 */
	NodePtr insert_p = (NodePtr)malloc(sizeof(Node));										
	insert_p->value = a;																	/* 先赋值 */
	insert_p->left = insert_p->right = NULL;												/* 先准备好要插入的子树 */
	while (temp)	
	{
		pre = temp;																			/* pre是上一个 */
		if (a < temp->value)																/* 让temp去搜索，小的往左大的往右 */
			temp = temp->left;														
		else
			temp = temp->right;
	}
	if (a < pre->value)																		/* 看一下，找到了后，看一下是在上边的左还是右子树 */
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
		printf("没有数据");
		return failed;
	}
	else
	{
		NodePtr root = BSTR->root;															/* 只是方便打代码 */
		NodePtr temp = BSTR->root;
		NodePtr parent = BSTR->root;
		int child = 0;																		/* 用于判断相对于父节点的左右子树 */
		while (temp)
		{
			if (a < temp->value)															/* 如果是比他小就往左边走 */
			{
				child = 0;																	/* 记录：在上一个节点的左边 */
				parent = temp;																/* 继续搜索 */
				temp = temp->left;
			}
			else if (a > temp->value)
			{
				child = 1;																	/* 同上 */
				parent = temp;
				temp = temp->right;
			}
			if (temp && a == temp->value)													/* 这里大致分9种情况 */
			{
				if (!temp->left && !temp->right)											/* 如果是两个孩子都为空 */
				{		
					if (temp == root)													
					{
						free(temp);															/* 如果是根找到了就直接删除 */
						temp = NULL;
						return succeed;														/* 返回 */
					}
					else if (child == 0)													/*如果当前节点位于上一个节点左边*/
					{
						free(temp);															/* 删除 */
						parent->left = NULL;												/* 封住这个口 */
						return succeed;
					}
					else if (child == 1)
					{
						free(temp);
						parent->right = NULL;												/* 同上 */
						return succeed;
					}
				}
				else if (!temp->left)														/* 当前节点的左孩子空 */
				{
					if (child == 0)															/* 当前节点时上一个节点的左孩子 */
						parent->left = temp->right;
					else
						parent->right = temp->right;
				}
				else if (!temp->right)														/* 右孩子空 */
				{
					if (child == 0)															/* 当前节点是上一个节点的左孩子 */
						parent->left = temp->left;
					else
						parent->right = temp->left;
				}
				else if (temp->left && temp->right)
				{
					NodePtr pre=NULL;
					NodePtr del_temp = temp;												/* 保存左节点 */
					temp = temp->right;
					if (!temp->left)														/* 一开始没有左节点 */												
					{
						del_temp->value = temp->value;										/* 直接用右节点代替 */
						if (!temp->right)													/* 如果右节点没有右节点 */
							del_temp->right = NULL;											/* 代替后直接封住右边的节点 */
						else
							del_temp->right = temp->right;									/* 如果有  则把temp的右节点当作要删除节点的右节点 */
						return succeed;
					}
					while (temp->left)														/* 如果有左节点，直接找到底部 */
					{
						pre = temp;
						temp = temp->left;
					}
					if (!temp->right)														/* 底部节点没有右节点 */
						pre->left = NULL;													/* 直接把当前节点删除 */
					else
						pre->left = temp->right;											/* 若有，底部右节点换成上一个的左节点 */
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
		printf("请先插入数据!");
	}
	NodePtr temp = BSTR->root;																/* 用来搜索的 */
	while (temp)
	{
		if (temp->value == a)																/* 如果相等 就返回 */
		{
			return true;
		}
		else
		{
			if (a < temp->value)															/* 根据方向寻找 */
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	return false;																			/* 找不到就退出 */
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr BSTR, void (*visit)(NodePtr root))
{
	stack sNODES;																			/* 初始化栈 */
	sNODES.top = -1;																		/* 刚开始将顶设置为-1 */
	if (BSTR->root)																			/* 判断不是空的树 */
	{
		NodePtr temp;										
		sNODES.nodes[++(sNODES.top)] = BSTR->root;											/* 将根节点压入栈中 */
		while (sNODES.top != -1)															/* 栈不为空 */
		{
			temp = sNODES.nodes[(sNODES.top)--];											/* 出栈 */
			visit(temp);
			if (temp->right != NULL)														/* 如果这个根部有右节点 */
				sNODES.nodes[++(sNODES.top)] = temp->right;									/* 先将右子节点压入栈中 */
			if (temp->left != NULL)															/* 再将左节点压入 */
				sNODES.nodes[++(sNODES.top)] = temp->left;									/* 因为出站是先是后入栈的先出 */
		}
		return succeed;
	}
	else
	{
		printf("树为空!");
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
		visit(root);																			/* 先序，根 左 右 */
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
		printf("请先初始化！");
		return failed;
	}
	stack sNODES;																			/* 初始化栈 */
	sNODES.top = -1;
	NodePtr temp = BSTR->root;
	while (temp != NULL || sNODES.top != -1)												/* 当栈不为空或仍有节点 */
	{
		if (temp != NULL)
		{
			sNODES.nodes[++(sNODES.top)] = temp;											/* 不为空就压栈 */
			temp = temp->left;														
		}
		else																				/* 栈顶也是重新调整当前结点的依据 */
		{
			temp = sNODES.nodes[(sNODES.top)--];											/* 当前为空，没有就返回到栈顶，并且出栈 */
			visit(temp);																	/* 输出栈顶元素 */
			temp = temp->right ;															/* 当前指针调到右节点 */
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
		
		BST_inorderR(root->left, visit);													/* 左 根 右 */
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
	stack sNODES;																			/* 初始化 */
	sNODES.top = -1;
	NodePtr lastVisit = NULL;																/* 记录每个节点访问次数栈 */
	NodePtr temp = BSTR->root;
	while (temp)																			/* 一路走到底 */
	{
		sNODES.nodes[++(sNODES.top)] = temp;
		temp = temp->left;
	}
	while (sNODES.top != -1)
	{
		temp = sNODES.nodes[(sNODES.top)--];												/* 当前结点左右是否被访问 */
		if (temp->right == NULL || temp->right == lastVisit)
		{
			visit(temp);																	/* 如果被访问就可以答应当前节点数据 */
			lastVisit = temp;
		}
		else
		{
			sNODES.nodes[++(sNODES.top)] = temp;											/* 右边没有被访问 */
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
		BST_postorderR(root->right, visit);													/* 左 右 根 */
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
		q.top = 0;																			/* 从顶部入队 */
		q.tail = 0;																			/* 入队之后顶部递增，先入队的从尾部出队 */
		q.nodes[q.top++] = BSTR->root;														/* 从一开始 */

		while (q.top > q.tail)																/* 当队列中有元素 */
		{
			if (q.nodes[q.tail])															/* 如果尾部有元素 */
			{
				visit(q.nodes[q.tail]);														/* 访问 */
				q.nodes[q.top++] = q.nodes[q.tail]->left;									/* 先放入左子树 */
				q.nodes[q.top++] = q.nodes[q.tail]->right;									/* 再放入右子树 */
			}
			q.tail++;																		/* 访问后尾部++，准备下一次的访问 */
		}
	}
	return succeed;
}

