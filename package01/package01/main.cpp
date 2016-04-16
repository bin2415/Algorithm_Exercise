#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> Need;
vector<int> Value;

void input()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;
		Need.push_back(a);
		Value.push_back(b);
	}
}

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
int solution()
{
	int *f;
	f = new int[M + 1];
	memset(f, 0, sizeof(int) * (M + 1));

	for (int i = 0; i < N; i++)
	{
		for (int j = M; j >= Need[i]; j--)
			f[j] = max(f[j - Need[i]] + Value[i], f[j]);
	}

	return f[M];
}


int main(int argc, char** argv)
{
	input();
	int result = solution();
	cout << result << endl;
	return 0;
}