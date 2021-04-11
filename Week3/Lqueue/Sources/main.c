#include<stdio.h>
#include<stdlib.h>
#include"../Headers/LQueue.h"
#define MAXLENGTH 30
int main() {
	LQueue head;
	void Menu();
	InitAQueueAtBegining(&head);
	int n, flag;
	while (1)
	{
		system("cls");
		Menu();
		do
		{
			flag = 0;
			n = 0;
			printf("请选择您想进行的操作：");
			scanf_s("%d", &n);
			if (getchar() != '\n') 
			{
				printf("不存在该选项，请重试！\n");
				flag = 1;
				while (getchar() != '\n');
			}
			else if (n > 11 || n < 1) 
			{
				printf("不存在该选项，请重试！\n");
				flag = 1;
			}
		}while (flag);

		switch (n)
		{
			case 1: 
			{
				InitLQueue(&head);
				system("pause");
				break;
			}
			case 2: 
			{
				DestoryLQueue(&head);
				system("pause");
				break;
			}
			case 3: 
			{
				int ret = IsEmptyLQueue(&head);
				if (ret == TRUE) printf("队列为空！\n");
				else if (ret == FALSE) printf("队列不为空！\n");
				system("pause");
				break;
			}
			case 4: 
			{
				void *e;
				GetHeadLQueue(&head, &e);
				system("pause");
				break;
			}
			case 5: 
			{
				int ret = LengthLQueue(&head);
				if (ret != -1) printf("队列长度为：%d\n", ret);
				system("pause");
				break;
			}
			case 6: 
			{
				typeChoose(&head);
				system("pause");
				break;
			}
			case 7: {
				if(DeLQueue(&head)) printf("出队成功！\n");
				system("pause");
				break;
			}
			case 8: {
				if(ClearLQueue(&head)) printf("清空完毕！\n");;
				system("pause");
				break;
			}
			case 9: {
				TraverseLQueue(&head, LPrint);			
				system("pause");
				break;
			}
			case 10: {
				printf("程序已退出！\n");
				return 0;
				break;
			}
			default:
				printf("未找到该选项，请重试！\n");
				system("pause");
				break;
			}
		system("cls");
	}
}

void Menu() 
{

	printf("************************************************\n");
	printf("** 1 -初始化队列             2 -销毁队列      **\n");
	printf("** 3 -判空                   4 -查看队头元素  **\n");
	printf("** 5 -确定队列长度           6 -入队          **\n");
	printf("** 7 -出队                   8 -清空队列      **\n");
	printf("** 9 -遍历队列               10-退出程序      **\n");
	printf("************************************************\n\n");

}