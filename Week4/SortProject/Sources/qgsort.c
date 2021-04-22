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
 * ����һ��������ɷǵݹ������ջ
 */
void InitStack(stack* s)																	/* ��ʼ�� */
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
void PushStack(stack* s, int d)																/* ѹջ */
{
	assert(s);
	if (s->size > 20)
	{
		return;
	}
	else
		s->data[s->size++] = d;
}
void PopStack(stack* s)																		/* ��ջ */
{
	assert(s);
	if (s->size == 0)
	{
		return;
	}
	else
		s->size--;
}
int TopStack(stack* s)																		/* ջ��Ԫ�� */
{
	assert(s);
	return s->data[s->size - 1];

}
int EmptyStack(stack* s)																	/* ���ջ */
{
	assert(s);
	return s->size == 0;
}
/*
*����һ����������
*��������������
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
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int* a, int n)
{
	int start = 0;													/* ��ʼ��λ�� */
	int j, tmp;														/* j������ʾi����ߣ�tmp�м���������нӱ��� */
	for (int i = start + 1; i < n; i++)								/* ���� */
	{
		for (tmp = a[i], j = i - 1; tmp < a[j] && j >= start; j--)	/* �����൱�ڰ�����������������ߵ����Ƚ����С����������� */
		{															/* ��������˿����ǰ����е��˿�����Ĺ��� */
			a[j + 1] = a[j];
		}
		a[j + 1] = tmp;												/* �ҵ�û�з������С������������λ�ò��� */
	}																/* j+1����Ϊ�ϱߵ�j--��֮��Ž����жϵ� */

}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int* a, int begin, int mid, int end) 
{																							/* ����һ�κϲ��Ĳ��� */
	int Left_Len = mid - begin + 1;
	int Right_Len = end - mid;
	int* L = (int*)malloc(sizeof(int) * Left_Len);
	int* R = (int*)malloc(sizeof(int) * Right_Len);
	int i, k, j;
	for (i = 0, k = begin; i < Left_Len; i++, k++)											/* �ֳ����飬��벿�� */
	{
		L[i] = a[k];
	}
	for (j = 0; j < Right_Len; j++, k++)													/* �Ұ벿�� */
	{
		R[j] = a[k];
	}
	for (i = 0, j = 0, k = begin; i < Left_Len && j < Right_Len; k++)						/* �ϲ�����ԭ�������� */
	{
		if (L[i] < R[j]) 
			a[k] = L[i++];
		else 
			a[k] = R[j++];
	}

	if (j < Right_Len)																		/* �Աȡ��ϲ�����֮����ܻ���ʣ�������ڷֿ������� */
	{																						/* ����������ֱ�Ӻϲ� */
		for (; j < Right_Len; j++, k++) 
		{
			a[k] = R[j];
		}
	}
	if (i < Left_Len)																		/* ͬ�� */
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
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int* a, int begin, int end) 
{
	if (begin >= end)																		/* �ж��Ƿ�ͷβ��ȣ��Ѿ��ֳ�һ��Ԫ�� */
		return;
	int mid = (begin + end) / 2;
	MergeSort(a, begin, mid);																/* ��mid�����µ������ĩβ�������ҷ��� */
	MergeSort(a, mid + 1, end);																/* �����ұ߷ֳ�һ�� */
	MergeArray(a, begin, mid, end);															/* �ϲ� */
}



/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int* a, int begin, int end)
{
	int low = begin, high = end;
	int tmp, check = a[begin];																/* �ǿ�ͷԪ��ȥ�Ƚ� */
	/*
		�˴����л��֣��ѱ�checkС�ķŵ���ߣ��Ѵ�ķŵ������ұ�
	*/
	do
	{
		while (a[high] >= check && low < high)												/* ���������ҵ���check��С��ֵΪֹ */
			high--;
		if (a[high]<check)																	/* Ȼ���ж���ǰ������ģ��ͽ��к�low���� */
			tmp = a[high], a[high] = a[low], a[low] = tmp;

		while (a[low] <= check && low < high)												/* ���������ҵ���check�����ֵΪֹ */
			low++;
		if (a[low] > check)																	/* ͬ�� */
			tmp = a[high], a[high] = a[low], a[low] = tmp;
		
	} while (low != high);																	/* һ�ֱ�����check�ŵ��м� */

	a[low] = check;														
	low--, high++;																			/* �������ĵط��ٷֿ����� */
	/*
		�˴����еݹ飬���ֺõ������ֱַ���п���
	*/
	if (low > begin) 
		QuickSort_Recursion(a, begin, low);													/* ��ԭ����low�����µ�β�� */
	if (high < end)	
		QuickSort_Recursion(a, high, end);													/* ��ԭ����high����ͷ�� */ 
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int* a, int size)
{
	int end = size;	
	int begin = 0;
	int* stack = (int*)malloc(sizeof(int) * end);
	if (!stack)
		return;
	int begin_temp = begin;																	/* �洢begin��end��������ջ��ƫ��0 */
	int end_temp = end - 1;
	int stack_top = 0;																		
	int p = Partition(a, begin_temp, end_temp);												/* �Ƚ��е�һ������ */
	if (p > (begin_temp + 1))																/* ��ȡ�����������ʼ��ַ������ջ */
	{
		stack[stack_top++] = p - 1;															/* ����ջ�ĺ��ջ */
		stack[stack_top++] = begin_temp;													/* ����ջ���ȳ�ջ */
	}
	if (p < (end_temp - 1))
	{
		stack[stack_top++] = end_temp;
		stack[stack_top++] = p + 1;
	}
																							/* ���ջ��ƫ��Ϊ0,��˵������if��δִ�� */
	while (stack_top > 0)																	/* ����ѭ����������� */
	{
		begin_temp = stack[--stack_top];													/* ��ջ�л�ȡ��ʼ��ַ */
		end_temp = stack[--stack_top];
		p = Partition(a, begin_temp, end_temp);												/* Ȼ����е������� */
		if (p > (begin_temp + 1))															/* ͬ��������if */
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
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int* a, int begin, int end) 
{
	int temp = a[begin];
																							/* ���beginС��end */
	while (begin < end)
	{																						/* ����Ҳ�����tempС��ֵ endָ��Ϳ�ʼ�Ӻ���ǰ�ƶ� */
		while ((begin < end) && (temp <= a[end]))
			end--;
		a[begin] = a[end];																	/* �ҵ���ŵ�begin��λ���� */
																							/* Ȼ��ʼ��begin��ʼ�����ұ�temp����� */
		while ((begin < end) && (temp > a[begin]))
			begin++;
																							/*Ȼ�󽫱�temp������ŵ�end���ڵ�λ����ȥ*/
		a[end] = a[begin];
	}																						/* �ٽ�temp�ŵ�begin���ڵ�λ���� */
	a[begin] = temp;																		/* ����begin��λ�ã����ֽ��ߵ�λ�� */
	return begin;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int* a, int size, int max)
{
		for (int i = 0; i < size; i++)
		{
			if (a[i] < 0)
			{
				printf("��ʱ��֧�ָ�ֵ����");
				break;
			}
		}
		int i;																					/* ����ͳ�����鲢ͳ��Ԫ�ظ��� */
		int* t = (int*)malloc(sizeof(int) * (max + 1));
		for (i = 0; i < max + 1; i++) t[i] = 0;													/* ��ʼ�� */
		for (i = 0; i < size; i++)
		{
			t[a[i]]++;
		}																						/* ͳ�����������Σ������Ԫ�ص���ǰ���Ԫ��֮�� */
		int sum = 0;
		for (i = 0; i < max + 1; i++)
		{
			sum += t[i];
			t[i] = sum;
		}																						/* �������ԭʼ���飬��ͳ���������ҵ���ȷ��λ�ã������������� */
		int* newa = (int*)malloc(sizeof(int) * size);
		for (i = size - 1; i >= 0; i--)
		{
			newa[t[a[i]] - 1] = a[i];
			t[a[i]]--;																			/* �´�������ͬ�����ͻ��ŵ�֮ǰ������ͬ������ǰ�� */
		}
		for (i = 0; i < size; i++)
		{
			a[i] = newa[i];
		}
	
	
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
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
			bucket[(a[i] / base) % 10]++;													/* ��λ���ϵ����֣�ʮλ���ϵ����ְ�λ���ϵ����֣�ǧλ���ϵ�����,bucketͰ��������ǵ��ǳ��ֵĴ��� */

		}
		for (i = 1; i < 10; i++) {
			bucket[i] += bucket[i - 1];														/* ��¼�����濪�ٿռ����뵽ʲôλ����ʱҪ�õ� */
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
*����һ����������
*���������ݵ����λ��
*/
int maxp(int* a, int n)
{	
	int d = 1;																				/* ��������λ�� */
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
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int* a, int size) 
{
	int p0 = 0, p2 = size - 1, p1;															/* p0��ͷ��ʼ��p2��β�Ϳ�ʼ */
	for (p1 = 0; p1 <= p2; p1++) 
	{
		if (a[p1] == 0)																		/* p1��p0�ߵÿ죬��0������߷� */
			swap(&a[p1--], &a[p0++]);														/* ִ��i--��i++�໥����������һ�λ���Ƚ��Ƿ��ܼ������� */

		else if (a[p1] == 2) 
			swap(&a[p1--], &a[p2--]);														/* ִ��i--��i++�໥����������һ�λ���Ƚ��Ƿ��ܼ������� */
	}
}



/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
int tK_Big(int* a, int begin, int end, int k)
{
	if (begin >= end)
		return a[begin];																	/* ������־ */
	int start = begin, last = end;
	int check = a[start];																	/* ѡ���ο��� */
	do												
	{
		while (start < last && a[last] <= check)	last--;									/* ���������ң��������ͬ�� */
		a[start] = a[last];
		while (start < last && a[start] >= check)	start++;								/* ���������ң����ŵĲ��֣� */
		a[last] = a[start];
	} while (start != last);
	a[start] = check;
	if (start == k)																			/* ����ѡ��������ͬʱ���л��� */
		return a[k];
	else																					/* ����������� */
	{		
		if (start > k)	
			return tK_Big(a, begin, start, k);
		else 
			return tK_Big(a, start + 1, end, k);
	}
}


/**
 *	����һ�����м����ĺ���
 *	�����м��С���±�
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
