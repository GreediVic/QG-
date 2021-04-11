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
			printf("��ѡ��������еĲ�����");
			scanf_s("%d", &n);
			if (getchar() != '\n') 
			{
				printf("�����ڸ�ѡ������ԣ�\n");
				flag = 1;
				while (getchar() != '\n');
			}
			else if (n > 11 || n < 1) 
			{
				printf("�����ڸ�ѡ������ԣ�\n");
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
				if (ret == TRUE) printf("����Ϊ�գ�\n");
				else if (ret == FALSE) printf("���в�Ϊ�գ�\n");
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
				if (ret != -1) printf("���г���Ϊ��%d\n", ret);
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
				if(DeLQueue(&head)) printf("���ӳɹ���\n");
				system("pause");
				break;
			}
			case 8: {
				if(ClearLQueue(&head)) printf("�����ϣ�\n");;
				system("pause");
				break;
			}
			case 9: {
				TraverseLQueue(&head, LPrint);			
				system("pause");
				break;
			}
			case 10: {
				printf("�������˳���\n");
				return 0;
				break;
			}
			default:
				printf("δ�ҵ���ѡ������ԣ�\n");
				system("pause");
				break;
			}
		system("cls");
	}
}

void Menu() 
{

	printf("************************************************\n");
	printf("** 1 -��ʼ������             2 -���ٶ���      **\n");
	printf("** 3 -�п�                   4 -�鿴��ͷԪ��  **\n");
	printf("** 5 -ȷ�����г���           6 -���          **\n");
	printf("** 7 -����                   8 -��ն���      **\n");
	printf("** 9 -��������               10-�˳�����      **\n");
	printf("************************************************\n\n");

}