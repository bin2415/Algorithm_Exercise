#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
int N, M;
//int *need, *value;
vector<int> need;
vector<int> value;
void input()
{
	cin >> N;
	cin >> M;
	//need = new int[N];
	//value = new int[M];
	for (int i = 0; i < N; i++)
	{
		int tempa, tempb;
		cin >> tempa;
		cin >> tempb;
		//need[i] = tempa;
		//value[i] = tempb;
		need.push_back(tempa);
		value.push_back(tempb);
	}

}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int solution()
{
	int* f;
	f = new int[M + 1];
	memset(f, 0, sizeof(int) * (M + 1));
	
	for (int i = 0; i < N; i++)
	{
		
		for (int j = M; j >= need[i]; j--)
		{
			int maxK = (int)floor(((float)j) / need[i]);
			for (int k = 0; k <= maxK; k++)
			{
				f[j] = max(f[j - k * need[i]] + value[i] * k, f[j]);
			}
		}
	}

	return f[M];
}
int main(int argc, char** argv)
{
	input();
	int result;
	result = solution();
	cout << result;
}
