#include <stdio.h>
#include <stdlib.h>
#include<conio.h> 
#pragma warning(disable:4996)
void enter(float a[]);   //输入函数
float calculation(float a[]);  //计算黄金点
void scoreboard(float a[], float goldpoint, int score[]);//计算结果


int main()
{
	char flag;
	int score[10] = { 0 };    //分数
	do {
		
		float a[10];  //每个人输入的数
		float sum = 0;  //10个数的总和
 
		float goldpoint;   //黄金点
		printf("请依次输入10个数\n");
		printf("请输入大于0的数\n");
		enter(a);
		goldpoint = calculation(a);
		scoreboard(a, goldpoint, score);
		printf("\n继续游戏按Y，退出请按任意键\n");
		flag = getch();
	} while (flag == 'y'|| flag == 'Y');
    return 0;
}
void enter(float a[])

{
	int i;
	int o;
	for (i = 0; i < 10; i++)
	{

	F:while (1)
	{
		do
		{
			printf("输入第%d个数:", i + 1);
			scanf("%f", &a[i]);
			if (a[i] == 0 || a[i] < 0)
				printf("输入错误请重新输入\n");
		} while (a[i] == 0 || a[i] < 0);

		for (o = 0; o < i; o++)
		{

			if (a[i] == a[o])
			{
				printf("输入数重复 请重新输入\n");
				goto F;
			}
		}

		break;
	}
	}

}
float calculation(float a[])
{
	int i;
	float sum=0;
	for (i = 0; i < 10; i++)
		sum = sum + a[i];
	return sum / 10 * 0.618;

}
void scoreboard(float a[], float goldpoint, int score[])
{
	float max = 0;
	int m; //记住几号输
	float min = 0;
	int n;  //记住几号赢
	int i;
	float b[10];  //与黄金点的差
	for (i = 0; i < 10; i++)
	{

		if (a[i] < goldpoint)
			b[i] = goldpoint - a[i];
		else b[i] = a[i] - goldpoint;
	}
	min = b[0];
	for (i = 0; i < 10; i++)
	{
		if (b[i] > max)
		{
			max = b[i];
			m = i;
		}
		if (b[i] < min)
		{
			min = b[i];
			n = i;
		}
	}
	score[m] = score[m] - 2;
	score[n] = score[n] + 2;
	printf("黄金点为%f\n", goldpoint);
	printf("获胜者是%d号\n", n + 1);
	printf("失败者是%d号\n", m + 1);
	for(int i=1;i<11;i++)
	printf("%d号选手\t",i);
	printf("\n");
	for (i = 0; i < 10; i++)
	printf("  %d\t", score[i]);
	


}