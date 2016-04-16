#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 1000001
/*
欧拉筛法的思想就是不做无用功，
原本Eratosthenes筛法的第一重循环是用来找素数，
然后把素数的倍数标记，而欧拉筛法换了一个角度，
第一位是找素数没有问题，但是标记的时候用的是所有数（合数素数都能用来做标记）来标记，
并加上了一句特判来跳出循环，什么意思呢？对于当前的一个数i，
欧拉筛法把从2， 3， 5....到小于 i 的最大素数分别和 i 相乘得到的数标记成合数。
并且过程中一旦发现 i % （p[j]） == 0，则跳出循环，有什么用呢？
这样做保证了每个合数只被他的最小素因子筛到一次，为什么？这么想，
我们每次想要标记的数是 i * p[j]， 有因子p[j],
如果 i 没有因子 p[j] 则标记（这是第一次用p[j]标记的时候干的事）,
易于发现当 i 中 p[j] 的指数为x时，i 是被 (i / p[j]) 这个数 * p[j] 时标记的，只标记了一次。
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

