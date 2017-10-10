/*
	TITLE: capture absconder
	SW EXPERT ACADEMY 1953
	CATEGORY: BFS
	DATE: 2017-10-11

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
queue <pair<int, pair<int, int>>> q;
bool visited[50][50];
int arr[50][50];
int main()
{
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int N, M, R, C, L; scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		q.push(make_pair(1, make_pair(R, C)));
		visited[R][C] = true;
		int result = 0;
		while (!q.empty())
		{
			int qx = q.front().second.first;
			int qy = q.front().second.second;
			int qt = q.front().first;
			result++;
			q.pop();
			switch (arr[qx][qy])
			{
			case 1:
				if (!visited[qx - 1][qy] && qt<L&&(arr[qx - 1][qy] == 1 || arr[qx - 1][qy] == 2 || arr[qx - 1][qy] == 5 || arr[qx - 1][qy] == 6))
				{
					q.push(make_pair(qt+1, make_pair(qx-1, qy)));
					visited[qx - 1][qy] = true;
				} // 위
				if (!visited[qx + 1][qy] && qt < L && (arr[qx+ 1][qy] == 1 || arr[qx + 1][qy] == 2 || arr[qx + 1][qy] == 4 || arr[qx + 1][qy] == 7))
				{
					q.push(make_pair(qt+1, make_pair(qx + 1, qy)));
					visited[qx + 1][qy] = true;
				} //아래
				if (!visited[qx][qy - 1] && qt < L && (arr[qx][qy - 1] == 1 || arr[qx][qy - 1] == 3 || arr[qx][qy - 1] == 4 || arr[qx][qy - 1] == 5))
				{
					q.push(make_pair(qt + 1, make_pair(qx, qy - 1)));
					visited[qx][qy - 1] = true;
				} // 왼쪽
				if (!visited[qx][qy + 1] && qt < L && (arr[qx][qy + 1] == 1 || arr[qx][qy + 1] == 3 || arr[qx][qy + 1] == 6 || arr[qx][qy + 1] == 7))
				{
					q.push(make_pair(qt + 1, make_pair(qx, qy + 1)));
					visited[qx][qy + 1] = true;
				} //오른쪽
				break;
			case 2:
				if (!visited[qx - 1][qy] && qt < L && (arr[qx - 1][qy] == 1 || arr[qx - 1][qy] == 2 || arr[qx - 1][qy] == 5 || arr[qx - 1][qy] == 6))
				{
					q.push(make_pair(qt + 1, make_pair(qx - 1, qy)));
					visited[qx - 1][qy] = true;
				} // 위
				if (!visited[qx + 1][qy] && qt < L && (arr[qx + 1][qy] == 1 || arr[qx + 1][qy] == 2 || arr[qx + 1][qy] == 4 || arr[qx + 1][qy] == 7))
				{
					q.push(make_pair(qt + 1, make_pair(qx + 1, qy)));
					visited[qx + 1][qy] = true;
				} //아래
				break;
			case 3:
				if (!visited[qx][qy - 1] && qt < L && (arr[qx][qy - 1] == 1 || arr[qx][qy - 1] == 3 || arr[qx][qy - 1] == 4 || arr[qx][qy - 1] == 5))
				{
					q.push(make_pair(qt + 1, make_pair(qx, qy - 1)));
					visited[qx][qy - 1] = true;
				} // 왼쪽
				if (!visited[qx][qy + 1] && qt < L && (arr[qx][qy + 1] == 1 || arr[qx][qy + 1] == 3 || arr[qx][qy + 1] == 6 || arr[qx][qy + 1] == 7))
				{
					q.push(make_pair(qt + 1, make_pair(qx, qy + 1)));
					visited[qx][qy + 1] = true;
				} //오른쪽
				break;
			case 4:
				if (!visited[qx - 1][qy] && qt < L && (arr[qx - 1][qy] == 1 || arr[qx - 1][qy] == 2 || arr[qx - 1][qy] == 5 || arr[qx - 1][qy] == 6))
				{
					q.push(make_pair(qt + 1, make_pair(qx - 1, qy)));
					visited[qx - 1][qy] = true;
				} // 위
				if (!visited[qx][qy + 1] && qt < L && (arr[qx][qy + 1] == 1 || arr[qx][qy + 1] == 3 || arr[qx][qy + 1] == 6 || arr[qx][qy + 1] == 7))
				{
					q.push(make_pair(qt + 1, make_pair(qx, qy + 1)));
					visited[qx][qy + 1] = true;
				} //오른쪽
				break;
			case 5:
				if (!visited[qx][qy + 1] && qt < L && (arr[qx][qy + 1] == 1 || arr[qx][qy + 1] == 3 || arr[qx][qy + 1] == 6 || arr[qx][qy + 1] == 7))
				{
					q.push(make_pair(qt + 1, make_pair(qx, qy + 1)));
					visited[qx][qy + 1] = true;
				} //오른쪽
				if (!visited[qx + 1][qy] && qt < L && (arr[qx + 1][qy] == 1 || arr[qx + 1][qy] == 2 || arr[qx + 1][qy] == 4 || arr[qx + 1][qy] == 7))
				{
					q.push(make_pair(qt + 1, make_pair(qx + 1, qy)));
					visited[qx + 1][qy] = true;
				} //아래
				break;
			case 6:
				if (!visited[qx + 1][qy] && qt < L && (arr[qx + 1][qy] == 1 || arr[qx + 1][qy] == 2 || arr[qx + 1][qy] == 4 || arr[qx + 1][qy] == 7))
				{
					q.push(make_pair(qt + 1, make_pair(qx + 1, qy)));
					visited[qx + 1][qy] = true;
				} //아래
				if (!visited[qx][qy - 1] && qt < L && (arr[qx][qy - 1] == 1 || arr[qx][qy - 1] == 3 || arr[qx][qy - 1] == 4 || arr[qx][qy - 1] == 5))
				{
					q.push(make_pair(qt + 1, make_pair(qx, qy - 1)));
					visited[qx][qy - 1] = true;
				} // 왼쪽
				break;
			case 7:
				if (!visited[qx][qy - 1] && qt < L && (arr[qx][qy - 1] == 1 || arr[qx][qy - 1] == 3 || arr[qx][qy - 1] == 4 || arr[qx][qy - 1] == 5))
				{
					q.push(make_pair(qt + 1, make_pair(qx, qy - 1)));
					visited[qx][qy - 1] = true;
				} // 왼쪽
				if (!visited[qx - 1][qy] && qt < L && (arr[qx - 1][qy] == 1 || arr[qx - 1][qy] == 2 || arr[qx - 1][qy] == 5 || arr[qx - 1][qy] == 6))
				{
					q.push(make_pair(qt + 1, make_pair(qx - 1, qy)));
					visited[qx - 1][qy] = true;
				} // 위
				break;
			}
		}
		printf("#"); printf("%d %d\n", i, result);
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
	}
	return 0;
}