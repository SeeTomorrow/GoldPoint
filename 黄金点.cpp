#include <stdio.h>
#include <stdlib.h>
#include<conio.h> 
#pragma warning(disable:4996)
void enter(float a[]);   //���뺯��
float calculation(float a[]);  //����ƽ��
void scoreboard(float a[], float goldpoint, int score[]);//������


int main()
{
	char flag;
	int score[10] = { 0 };    //����
	do {
		
		float a[10];  //ÿ�����������
		float sum = 0;  //10�������ܺ�
 
		float goldpoint;   //�ƽ��
		printf("����������10����\n");
		printf("���������0����\n");
		enter(a);
		goldpoint = calculation(a);
		scoreboard(a, goldpoint, score);
		printf("\n������Ϸ��Y���˳��밴�����\n");
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
			printf("�����%d����:", i + 1);
			scanf("%f", &a[i]);
			if (a[i] == 0 || a[i] < 0)
				printf("�����������������\n");
		} while (a[i] == 0 || a[i] < 0);

		for (o = 0; o < i; o++)
		{

			if (a[i] == a[o])
			{
				printf("�������ظ� ����������\n");
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
	int m; //��ס������
	float min = 0;
	int n;  //��ס����Ӯ
	int i;
	float b[10];  //��ƽ��Ĳ�
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
	printf("�ƽ��Ϊ%f\n", goldpoint);
	printf("��ʤ����%d��\n", n + 1);
	printf("ʧ������%d��\n", m + 1);
	for(int i=1;i<11;i++)
	printf("%d��ѡ��\t",i);
	printf("\n");
	for (i = 0; i < 10; i++)
	printf("  %d\t", score[i]);
	


}