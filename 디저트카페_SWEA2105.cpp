/*
	TITLE: DESSERTS CAFE
	SW EXPERT ACADEMY 2105
	CATEGORY: DFS
	DATE: 2017-10-19
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int N;
int arr[20][20];
int dx[4] = { -1,1,1,-1 };
int dy[4] = { 1,1,-1,-1 };
int maxlen;
bool type[101];
bool dir[4];
void dfs(int startx, int starty, int curx, int cury, bool *type, int curd, bool dir[], int len)
{
	for (int k = 0; k < 4; k++)
	{
		int nx = curx + dx[k];
		int ny = cury + dy[k];

		if (nx == startx&&ny == starty&&len>2 && maxlen < len)
		{
			maxlen = len;
		}
		else if (nx >= 0 && nx < N&&ny >= 0 && ny < N && !type[arr[nx][ny]])
		{
			if (curd == k)
			{
				type[arr[nx][ny]] = true;
				dfs(startx, starty, nx, ny, type, curd, dir, len + 1);
				type[arr[nx][ny]] = false;
			}
			else if (curd != k && !dir[k])
			{
				type[arr[nx][ny]] = true;
				dir[k] = true;
				dfs(startx, starty, nx, ny, type, k, dir, len + 1);
				type[arr[nx][ny]] = false;
				dir[k] = false;
				//printf("maxlen: %d\n", maxlen);
			}
		}
	}
}


int main()
{
	int T; scanf("%d", &T);
	for (int s = 1; s <= T; s++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		maxlen = -1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == 0 && j == 0) continue;
				else if (i == 0 && j == N - 1) continue;
				else if (i == N - 1 && j == 0) continue;
				else if (i == N - 1 && j == N - 1) continue;
				else
				{
					type[arr[i][j]] = true;
					dfs(i, j, i, j, type, -1, dir, 1);// start
					memset(dir, false, sizeof(dir));
					memset(type, false, sizeof(type));
				}

			}
		}
		printf("#%d %d\n", s, maxlen);
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}