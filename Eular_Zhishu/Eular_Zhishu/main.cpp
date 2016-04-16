#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 1000001
/*
ŷ��ɸ����˼����ǲ������ù���
ԭ��Eratosthenesɸ���ĵ�һ��ѭ����������������
Ȼ��������ı�����ǣ���ŷ��ɸ������һ���Ƕȣ�
��һλ��������û�����⣬���Ǳ�ǵ�ʱ���õ�������������������������������ǣ�����ǣ�
��������һ������������ѭ����ʲô��˼�أ����ڵ�ǰ��һ����i��
ŷ��ɸ���Ѵ�2�� 3�� 5....��С�� i ����������ֱ�� i ��˵õ�������ǳɺ�����
���ҹ�����һ������ i % ��p[j]�� == 0��������ѭ������ʲô���أ�
��������֤��ÿ������ֻ��������С������ɸ��һ�Σ�Ϊʲô����ô�룬
����ÿ����Ҫ��ǵ����� i * p[j]�� ������p[j],
��� i û������ p[j] ���ǣ����ǵ�һ����p[j]��ǵ�ʱ��ɵ��£�,
���ڷ��ֵ� i �� p[j] ��ָ��Ϊxʱ��i �Ǳ� (i / p[j]) ����� * p[j] ʱ��ǵģ�ֻ�����һ�Ρ�
*/
int isVia[MAXSIZE] = { 0 };
int ZhiShu[MAXSIZE] = { 0 };
int Eular(int n)
{
	int countNum = 0;
	int i = 2;
	for (; i <= n; i++)
	{
		if (!isVia[i])
		{
			ZhiShu[countNum++] = i;
		}
		int j;
		for (j = 0; j < countNum; j++)
		{
			if (i * ZhiShu[j] > n) break;
		
			isVia[i*ZhiShu[j]] = 1;

			if (i % ZhiShu[j] == 0) break;
			

		}
	}
	return countNum;

}

int main()
{
	int N, count;
	scanf("%d", &N);
	count = Eular(N);
	printf("%d\n", count);

}

