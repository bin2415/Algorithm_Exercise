#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
int m[100][100]; //用来存取迷宫数据
int best[100][100];
int numLine = 0;

struct node{
	int row;
	int col;
	int value;
};

void input()
{
	cin >> numLine;
	for (int i = 1; i <= numLine; i++)
	{
		int temp;
		int row = i - 1;
		for (int j = 0; j < i; j++)
		{
			cin >> temp;
			m[row][j] = temp;
		}
	}
}

int findBestPath()
{
	queue<node> q;
	node current;
	current.row = 0;
	current.col = 0;
	current.value = m[0][0];
	q.push(current);
	best[0][0] = m[0][0];
	while (!q.empty())
	{
		node top = q.front();
		q.pop();
		if (top.value < best[top.row][top.col])
		{
			continue;
		}
			if (top.row == numLine - 1)
				break;

			int nowRow = top.row;
			int nowCol = top.col;
			if (best[nowRow + 1][nowCol] < best[nowRow][nowCol] + m[nowRow + 1][nowCol])
			{
				//int tempRow = nowRow+1;
				int bestValue = best[nowRow][nowCol] + m[nowRow + 1][nowCol];
				node tempNode;
				tempNode.row = nowRow + 1;
				tempNode.col = nowCol;
				tempNode.value = bestValue;
				q.push(tempNode);
				best[nowRow + 1][nowCol] = bestValue;
			}

			if (best[nowRow + 1][nowCol + 1] < best[nowRow][nowCol] + m[nowRow + 1][nowCol + 1])
			{
				//int tempRow = nowRow+1;
				int bestValue = best[nowRow][nowCol] + m[nowRow + 1][nowCol + 1];
				node tempNode;
				tempNode.row = nowRow + 1;
				tempNode.col = nowCol + 1;
				tempNode.value = bestValue;
				q.push(tempNode);
				best[nowRow + 1][nowCol + 1] = bestValue;
			}

		
	}
	int bestResult = 0;
	for (int i = 0; i < numLine; i++)
	{
		if (bestResult < best[numLine - 1][i])
		{
			bestResult = best[numLine - 1][i];
		}
	}

	return bestResult;
}
int main()
{
	input();
	int bestResult = findBestPath();
	cout << bestResult << endl;
	return 0;
}
