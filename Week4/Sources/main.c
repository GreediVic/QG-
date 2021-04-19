#define _CRT_SECURE_NO_WARNINGS
#include"../Headers/qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t start, stop;
double duration;

int main()
{
    int right = 0;
    void _creat_numbers(int a[], int size);
    void print(int* a, int size);
    int menu();
    void Save(int* a, int size);
    void swich(int choice, int a[]);
    int choice;
    int size = 0;
    int* a = NULL;
    int m = 0;
    while (1)
    {
        switch (choice = menu())
        {
        case 0:
        {
            printf("请选择从文件读取还是随机生成：\n[1]从文件读取；[2]随机生成\n");
            int c = input();
            int iters = 0;
            if (c == 1)
            {
                printf("请要利用文件中的前几个数据:\n");
                scanf("%d", &iters);
                FILE* fp2 = fopen("../Headers/F_Save.txt", "r");
                if (fp2 == NULL)
                {
                    printf("读取出错，请检查文件\n");
                    return;
                }
                int i = 1;
                a = (int*)malloc(sizeof(int)*1);
                int* b = NULL;
                 while (!feof(fp2)&&(iters--))
                {
                    fscanf(fp2, "%d", &a[i-1]);
                    b = (int *)realloc(a, (++i)*(sizeof(int)));
                    if (b)
                    {
                        a = b;
                    }
                    else
                    {
                        printf("分配内存失败！");
                        right = 0;
                        free(a);
                        free(b);
                        a = NULL;
                        b = NULL;
                        break;
                    }
                    
                }
                a = (int*)realloc(a, (i - 1) * (sizeof(int)));
                size = i-1;
                right = 1;
            }
            else if(c == 2)
            {
                printf("请选择要创建的数量大小：\n[1]:10000\n[2]:50000\n[3]:200000\n");
                m = input();
                if (m == 1)
                {
                    size = 10000;
                    a = (int*)malloc(sizeof(int) * size);
                    _creat_numbers(a, 10000);
                    Save(a, size);
                }
                if (m == 2)
                {
                    size = 50000;
                    a = (int*)malloc(sizeof(int) * size);
                    _creat_numbers(a, 50000);
                    Save(a, size);
                }
                if (m == 3)
                {
                    size = 200000;
                    a = (int*)malloc(sizeof(int) * size);
                    _creat_numbers(a, 200000);
                    Save(a, size);
                }
                right = 1;
            }
            system("pause");
            break;
        }

        case 1:
        {
            if (right == 1)
            {
                start = clock();
                insertSort(a, size);
                stop = clock();

                duration = (double)(stop - start) / CLK_TCK;                                    /* CLK_TCK为clock()函数的时间单位，即时钟打点 */
                printf("使用了%f秒\n", duration);

                print(a, size);
                system("pause");
                right = 0;
            }
            break;
            
        }

        case 2:
        {
            if (right == 1)
            {
                start = clock();
                MergeSort(a, 0, size - 1);
                stop = clock();

                duration = (double)(stop - start) / CLK_TCK;
                printf("使用了%f秒\n", duration);

                print(a, size);
                system("pause");
                right = 0;
                
            }
            break;  
        }

        case 3:
        {
            if (right == 1)
            {
                start = clock();
                QuickSort_Recursion(a, 0, size - 1);
                stop = clock();

                duration = (double)(stop - start) / CLK_TCK;
                printf("使用了%f秒\n", duration);

                print(a, size);
                system("pause");
                right = 0;
            }
            break;
        }

        case 4:
        {
            if (right == 1)
            {
                start = clock();
                QuickSort(a, size);
                stop = clock();

                duration = (double)(stop - start) / CLK_TCK;
                printf("使用了%f秒\n", duration);

                print(a, size);
                system("pause");
                right = 0;
                
            }
            break;
        }

        case 5:
        {
            if (right == 1)
            {
                start = clock();
                int max = -1;
                for (int i = 0; i < size; i++)
                {
                	if (max < a[i])
                        max = a[i];
				} 
                    
                CountSort(a, size, max);
                stop = clock();

                duration = (double)(stop - start) / CLK_TCK;
                printf("使用了%f秒\n", duration);

                print(a, size);
                system("pause");
                right = 0;
            }
            break;
        }

        case 6:
        {
            if (right == 1)
            {
                start = clock();
                RadixCountSort(a, size);
                stop = clock();

                duration = (double)(stop - start) / CLK_TCK;
                printf("使用了%f秒\n", duration);

                print(a, size);
                system("pause");
                right = 0;
            }
            break;
        }

        case 7:
        {
            int nm = 0;
            printf("该函数无需使用功能[1]，此功能内部自动创建\n");
            printf("请选择要创建的数量大小：\n[1]:10000\n[2]:50000\n[3]:200000\n");
            m = input();

            if (m == 1)
                size = 10000;
            if (m == 2)
                size = 50000;
            if (m == 3)
                size = 200000;

            a = (int*)malloc(sizeof(int) * size);

            srand(time(0));                                                                 /* 将时间函数传入到随机数产生函数 */
            printf("A set of random numbers:\n");
            for (int i = 0; i < size; i++) {
                nm = rand() % 3;
                a[i] = nm;
                printf("%d  ", nm);
            }
            putchar('\n');
            Save(a, size);

            start = clock();
            ColorSort(a, size);
            stop = clock();

            duration = (double)(stop - start) / CLK_TCK; 
            printf("使用了%f秒\n", duration);

            print(a, size);
            system("pause");
            right = 0;
            break;
        }

        case 8:
        {
            if (right == 1)
            {
                int k, k_value;                                                                  /* 承接第k大的数 */
                printf("请选择第k大的数(不能大于选择创建的数组大小)： ");
                scanf("%d", &k);
                if (k > size)
                    break;

                start = clock();
                k_value = tK_Big(a, 0, size - 1, k);
                stop = clock();

                duration = (double)(stop - start) / CLK_TCK;
                printf("使用了%f秒\n", duration);

                printf("第%d大是：%d\n", k, k_value);
                system("pause");
            }
            break;
        }

        case 9:
            break;

        default:
            break;
        }
        if (choice == 9)
            break;
        system("cls");
    }
    
	return 0;
}


void Save(int* a,int size) 
{
    FILE* fp1=NULL;
    int i;
    if (!(fp1 = fopen("../Headers/F_Save.txt", "a+"))) 
    {
        printf("打开文件出错，请检查文件\n");
        return;
    }
    for (i = 0; i < size; i++) 
    {
        fprintf(fp1, "%d", a[i]);
        fprintf(fp1, " ");
    }
    fprintf(fp1, "\n");
    fclose(fp1);
}


int menu()
{
    char cases[10] = { '\0' };
    printf("\t注：每次创建随机数和排序后都会自动保存\n");
    printf("\t=============================\n");
    printf("\t*[0]获得随机数              *\n");
    printf("\t*[1]插入排序                *\n");
    printf("\t*[2]归并排序                *\n");
    printf("\t*[3]快速排序                *\n");
    printf("\t*[4]快排（非递归）          *\n");
    printf("\t*[5]计数排序                *\n");
    printf("\t*[6]基数排序                *\n");
    printf("\t*[7]颜色排序                *\n");
    printf("\t*[8]寻找第K大的数           *\n");
    printf("\t*[9]退出                    *\n");
    printf("\t=============================\n");
    printf("Your Order IS: ");
    scanf("%s", cases);
    while (!(cases[0] >= '0' && cases[0] <= '9' && cases[1] == '\0'))                       /* 检测用户是否合法输入 */
    {
        printf("输入非法请重新输入：");
        scanf("%s", cases);
    }
    return (cases[0] - 48);
}


void _creat_numbers(int a[],int size)
{
    int num;
    srand(time(666));                                                                       /* 将时间函数传入到随机数产生函数 */
    printf("成功创建%d个的随机数（100000内的）\n",size);
    for (int i = 0; i < size; i++) 
    {
        a[i] = rand() % 32768;
    }
    putchar('\n');
}

void print(int* a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    putchar('\n');
}

int input()
{
    char num[3];
    scanf("%s", num);
    while (!(num[0] >= '1' && num[0] <= '3' && num[1] == '\0'))                     /* 检测用户是否合法输入 */
    {
        printf("输入非法请重新输入：");
        scanf("%s", num);
    }
    return (num[0] - 48);
}
