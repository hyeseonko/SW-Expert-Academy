/*
	TITLE: MAKE THE LONGEST MOUNTAIN PATH AS POSSIBLE
	SW EXPERT ACADEMY 1949
	CATEGORY: DFS
	DATE: 2017-10-13
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;
typedef pair<int, pair<int, int> > iii;
vector <iii> v; // <value, used/new, x,y>

struct my_compare {
	bool operator()(const iii &lhs, const iii &rhs) const {
		return lhs.first > rhs.first;
	}
};
int arr[8][8];
int starting_point[5][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = {0,0, 1,-1 };
int N, K;
int max_updated;
void dfs(int val, int x, int y, bool used, int len, bool visited[][8])
{
	//printf("%d %d %d %d\n", val, x, y, len);
	if (len > max_updated) max_updated = len;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx&&nx < N && 0 <= ny&&ny < N && !visited[nx][ny])
		{
			if (arr[nx][ny] < val)
			{
				visited[nx][ny] = true;
				dfs(arr[nx][ny], nx, ny, used, len + 1, visited);
				visited[nx][ny] = false;
			}
			else if (used==false&&arr[nx][ny] >= val)
			{
				for (int j = 1; j <= K; j++)
				{
					if (arr[nx][ny] - j < val)
					{
						visited[nx][ny] = true;
						dfs(arr[nx][ny] - j, nx, ny, true, len + 1, visited);
						visited[nx][ny] = false;
					}
				}
			}
		}
	}
}

int main()
{
	int T; scanf("%d", &T);
	for (int s = 1; s <= T; s++)
	{
		scanf("%d %d", &N, &K);
		bool visited[8][8];
		max_updated = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &arr[i][j]);
				v.push_back(make_pair(arr[i][j], make_pair(i,j))); // 가장 높은 봉우리의 높이와 좌표를 알기 위해
			}
		}
		sort(v.begin(), v.end(),my_compare()); // Sorting을 하여 높은 봉우리를 찾는다.
		int highest = v[0].first;
		int starting_number = 0;
		for (int i = 0; i < 5; i++)
		{
			if (v[i].first != highest) break;
			starting_point[i][0] = v[i].second.first;
			starting_point[i][1] = v[i].second.second;
			starting_number++;
		}
		for (int i = 0; i < starting_number; i++)
		{
			memset(visited, false, sizeof(visited));
			visited[starting_point[i][0]][starting_point[i][1]] = true;
			dfs(highest, starting_point[i][0], starting_point[i][1], false, 1, visited);
		}
		printf("#"); printf("%d %d\n", s, max_updated);
		memset(arr, 0, sizeof(arr));
		memset(starting_point, 0, sizeof(starting_point));
		v.clear();
	}
	return 0;
}