#include"../Headers/qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct Stack {
	int* data;
	int size;

}stack;

/*
 * 这是一个用来完成非递归数组的栈
 */
void InitStack(stack* s)																	/* 初始化 */
{
	int* data = (int*)malloc(200000 * sizeof(int));
	if (data == NULL)
	{
		assert(0);
		return;
	}
	s->data = data;
	s->size = 0;
}
void PushStack(stack* s, int d)																/* 压栈 */
{
	assert(s);
	if (s->size > 20)
	{
		return;
	}
	else
		s->data[s->size++] = d;
}
void PopStack(stack* s)																		/* 出栈 */
{
	assert(s);
	if (s->size == 0)
	{
		return;
	}
	else
		s->size--;
}
int TopStack(stack* s)																		/* 栈顶元素 */
{
	assert(s);
	return s->data[s->size - 1];

}
int EmptyStack(stack* s)																	/* 清空栈 */
{
	assert(s);
	return s->size == 0;
}
/*
*这是一个辅助函数
*用来交换两个数
*/
void swap(int* x, int* y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n)
{
	int start = 0;													/* 开始的位置 */
	int j, tmp;														/* j用来表示i的左边，tmp中间过程用来承接变量 */
	for (int i = start + 1; i < n; i++)								/* 遍历 */
	{
		for (tmp = a[i], j = i - 1; tmp < a[j] && j >= start; j--)	/* 过程相当于把外层遍历到的数和左边的数比较如果小，则继续往左看 */
		{															/* 这就是玩扑克牌是把手中的扑克排序的过程 */
			a[j + 1] = a[j];
		}
		a[j + 1] = tmp;												/* 找到没有符合左边小的则进行在这个位置插入 */
	}																/* j+1是因为上边的j--了之后才进行判断的 */

}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end) 
{																							/* 这是一次合并的操作 */
	int Left_Len = mid - begin + 1;
	int Right_Len = end - mid;
	int* L = (int*)malloc(sizeof(int) * Left_Len);
	int* R = (int*)malloc(sizeof(int) * Right_Len);
	int i, k, j;
	for (i = 0, k = begin; i < Left_Len; i++, k++)											/* 分成两组，左半部分 */
	{
		L[i] = a[k];
	}
	for (j = 0; j < Right_Len; j++, k++)													/* 右半部分 */
	{
		R[j] = a[k];
	}
	for (i = 0, j = 0, k = begin; i < Left_Len && j < Right_Len; k++)						/* 合并放在原来数组内 */
	{
		if (L[i] < R[j]) 
			a[k] = L[i++];
		else 
			a[k] = R[j++];
	}

	if (j < Right_Len)																		/* 对比、合并完了之后可能会有剩余数字在分开的组中 */
	{																						/* 接下来进行直接合并 */
		for (; j < Right_Len; j++, k++) 
		{
			a[k] = R[j];
		}
	}
	if (i < Left_Len)																		/* 同上 */
	{
		for (; i < Left_Len; i++, k++)
		{

			a[k] = L[i];
		}
	}
	free(L);
	L = NULL;
	free(R);
	L = NULL;
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end) 
{
	if (begin >= end)																		/* 判断是否头尾相等，已经分成一个元素 */
		return;
	int mid = (begin + end) / 2;
	MergeSort(a, begin, mid);																/* 把mid当做新的数组的末尾进行左右分组 */
	MergeSort(a, mid + 1, end);																/* 这是右边分成一组 */
	MergeArray(a, begin, mid, end);															/* 合并 */
}



/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end)
{
	int low = begin, high = end;
	int tmp, check = a[begin];																/* 那开头元素去比较 */
	/*
		此处进行划分，把比check小的放到左边，把大的放到它的右边
	*/
	do
	{
		while (a[high] >= check && low < high)												/* 从右往左找到比check更小的值为止 */
			high--;
		if (a[high]<check)																	/* 然后判断是前者满足的，就进行和low交换 */
			tmp = a[high], a[high] = a[low], a[low] = tmp;

		while (a[low] <= check && low < high)												/* 从左往右找到比check更大的值为止 */
			low++;
		if (a[low] > check)																	/* 同上 */
			tmp = a[high], a[high] = a[low], a[low] = tmp;
		
	} while (low != high);																	/* 一轮遍历将check放到中间 */

	a[low] = check;														
	low--, high++;																			/* 从相遇的地方再分开两边 */
	/*
		此处进行递归，划分好的两部分分别进行快排
	*/
	if (low > begin) 
		QuickSort_Recursion(a, begin, low);													/* 把原本的low当做新的尾部 */
	if (high < end)	
		QuickSort_Recursion(a, high, end);													/* 把原本的high当做头部 */ 
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size)
{
	int end = size;	
	int begin = 0;
	int* stack = (int*)malloc(sizeof(int) * end);
	if (!stack)
		return;
	int begin_temp = begin;																	/* 存储begin与end并且设置栈顶偏移0 */
	int end_temp = end - 1;
	int stack_top = 0;																		
	int p = Partition(a, begin_temp, end_temp);												/* 先进行第一次排序 */
	if (p > (begin_temp + 1))																/* 获取单个数组的起始地址并存入栈 */
	{
		stack[stack_top++] = p - 1;															/* 先入栈的后出栈 */
		stack[stack_top++] = begin_temp;													/* 后入栈的先出栈 */
	}
	if (p < (end_temp - 1))
	{
		stack[stack_top++] = end_temp;
		stack[stack_top++] = p + 1;
	}
																							/* 如果栈顶偏移为0,那说明两个if都未执行 */
	while (stack_top > 0)																	/* 结束循环，排序结束 */
	{
		begin_temp = stack[--stack_top];													/* 从栈中获取起始地址 */
		end_temp = stack[--stack_top];
		p = Partition(a, begin_temp, end_temp);												/* 然后进行单次排序 */
		if (p > (begin_temp + 1))															/* 同上面两个if */
		{
			stack[stack_top++] = p - 1;
			stack[stack_top++] = begin_temp;
		}
		if (p < (end_temp - 1))
		{
			stack[stack_top++] = end_temp;
			stack[stack_top++] = p + 1;
		}
	}
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end) 
{
	int temp = a[begin];
																							/* 如果begin小于end */
	while (begin < end)
	{																						/* 如果找不到比temp小的值 end指针就开始从后往前移动 */
		while ((begin < end) && (temp <= a[end]))
			end--;
		a[begin] = a[end];																	/* 找到后放到begin的位置上 */
																							/* 然后开始从begin开始向后查找比temp大的数 */
		while ((begin < end) && (temp > a[begin]))
			begin++;
																							/*然后将比temp大的数放到end所在的位置上去*/
		a[end] = a[begin];
	}																						/* 再将temp放到begin所在的位置上 */
	a[begin] = temp;																		/* 返回begin的位置，即分界线的位置 */
	return begin;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max)
{
		for (int i = 0; i < size; i++)
		{
			if (a[i] < 0)
			{
				printf("暂时不支持负值排序");
				break;
			}
		}
		int i;																					/* 创建统计数组并统计元素个数 */
		int* t = (int*)malloc(sizeof(int) * (max + 1));
		for (i = 0; i < max + 1; i++) t[i] = 0;													/* 初始化 */
		for (i = 0; i < size; i++)
		{
			t[a[i]]++;
		}																						/* 统计数组做变形，后面的元素等于前面的元素之和 */
		int sum = 0;
		for (i = 0; i < max + 1; i++)
		{
			sum += t[i];
			t[i] = sum;
		}																						/* 倒序遍历原始数组，从统计数组中找到正确的位置，输出到结果数组 */
		int* newa = (int*)malloc(sizeof(int) * size);
		for (i = size - 1; i >= 0; i--)
		{
			newa[t[a[i]] - 1] = a[i];
			t[a[i]]--;																			/* 下次遇到相同的数就会排到之前于他相同的数的前面 */
		}
		for (i = 0; i < size; i++)
		{
			a[i] = newa[i];
		}
	
	
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size)
{
	int i, max = a[0], base = 1;
	for (i = 1; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int* t = (int*)malloc(sizeof(int) * size);
	while (max / base > 0) {
		int bucket[10] = { 0 };
		for (i = 0; i < size; i++) {
			bucket[(a[i] / base) % 10]++;													/* 个位数上的数字，十位数上的数字百位数上的数字，千位数上的数字,bucket桶里面数组记的是出现的次数 */

		}
		for (i = 1; i < 10; i++) {
			bucket[i] += bucket[i - 1];														/* 记录，下面开辟空间后插入到什么位置上时要用到 */
		}
		for (i = size - 1; i >= 0; i--) {
			t[bucket[a[i] / base % 10] - 1] = a[i];
			bucket[a[i] / base % 10]--;
		}
		for (i = 0; i < size; i++) {
			a[i] = t[i];
		}
		base = base * 10;
	}
}


/*
*这是一个辅助函数
*用来求数据的最大位数
*/
int maxp(int* a, int n)
{	
	int d = 1;																				/* 保留最大的位数 */
	int p = 10;
	for (int i = 0; i < n; i++)
	{
		while (a[i] >= p)
			p *= 10, d++;
		return d;
	}
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size) 
{
	int p0 = 0, p2 = size - 1, p1;															/* p0从头开始，p2从尾巴开始 */
	for (p1 = 0; p1 <= p2; p1++) 
	{
		if (a[p1] == 0)																		/* p1比p0走得快，把0都往左边放 */
			swap(&a[p1--], &a[p0++]);														/* 执行i--与i++相互抵消，给多一次机会比较是否能继续交换 */

		else if (a[p1] == 2) 
			swap(&a[p1--], &a[p2--]);														/* 执行i--与i++相互抵消，给多一次机会比较是否能继续交换 */
	}
}



/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int tK_Big(int* a, int begin, int end, int k)
{
	if (begin >= end)
		return a[begin];																	/* 结束标志 */
	int start = begin, last = end;
	int check = a[start];																	/* 选定参考数 */
	do												
	{
		while (start < last && a[last] <= check)	last--;									/* 从右往左找（与快排相同） */
		a[start] = a[last];
		while (start < last && a[start] >= check)	start++;								/* 从左往右找（快排的部分） */
		a[last] = a[start];
	} while (start != last);
	a[start] = check;
	if (start == k)																			/* 当与选定的数相同时进行回溯 */
		return a[k];
	else																					/* 否则继续划分 */
	{		
		if (start > k)	
			return tK_Big(a, begin, start, k);
		else 
			return tK_Big(a, start + 1, end, k);
	}
}


/**
 *	这是一个找中间数的函数
 *	返回中间大小的下标
 */
/*int MiddleNumber(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] > a[mid])
	{
		if (a[begin] > a[end])
		{
			if (a[mid] > a[end])
			{
				return mid;
			}
			else
				return end;
		}
		else
			return begin;
	}
	else
	{
		if (a[mid] > a[end])
		{
			if (a[begin] > a[end])
			{
				return begin;
			}
			else
			{
				return end;
			}
		}
		else
			return mid;																		
	}

}*/
