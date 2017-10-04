/*
	TITLE: SEPERATE THE MICROORGANISM
	SWEA 2382
	CATEGORY: SIMULATION
	DATE: 2017-10-04
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <utility>
using namespace std;

int arr[1000][4];
int total;

int main()
{
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int N, M, K; scanf("%d %d %d", &N, &M, &K);
		vector <pair<int, int> > v[10000];
		memset(arr, 0, sizeof(arr));
		for (int j = 0; j < K; j++)
		{
			scanf("%d %d %d %d", &arr[j][0], &arr[j][1], &arr[j][2], &arr[j][3]);
		}
		int idx = K;
		for (int w = 0; w < M; w++)
		{
			// 1단계: MOVE TO NEXT STEP (FROM arr TO vector)
			for (int j = 0; j < idx; j++)
			{
				if (arr[j][3] == 1) // 상(-1,0)으로 움직일때
				{
					if (arr[j][0] == 1)
					{
						if (arr[j][2] >= 2) v[arr[j][1]].push_back(make_pair(arr[j][2] / 2, 2 ));
					}
					else
					{
						v[N*(arr[j][0] - 1) + arr[j][1]].push_back(make_pair(arr[j][2], 1 ));
					}
				}
				else if (arr[j][3] == 2) //하(1,0)로 움직일때
				{
					if (arr[j][0] == N - 2)
					{
						if (arr[j][2] >= 2) v[N*N - N + arr[j][1]].push_back(make_pair(arr[j][2] / 2,1 ));
					}
					else
					{
						v[N*(arr[j][0] + 1) + arr[j][1]].push_back(make_pair(arr[j][2], 2 ));
					}
				}
				else if (arr[j][3] == 3) // 좌(0,-1)로 움직일때
				{
					if (arr[j][1] == 1)
					{
						if (arr[j][2] >= 2) v[N*arr[j][0]].push_back(make_pair(arr[j][2] / 2,4 ));
					}
					else
					{
						v[N*arr[j][0] + arr[j][1] - 1].push_back(make_pair(arr[j][2], 3 ));
					}
				}
				else // 우(0,1)로 움직일때
				{
					if (arr[j][1] == N - 2)
					{
						if (arr[j][2] >= 2) v[N*arr[j][0] + (N - 1)].push_back(make_pair(arr[j][2] / 2,3 ));
					}
					else
					{
						v[N*arr[j][0] + (arr[j][1] + 1)].push_back(make_pair(arr[j][2], 4 ));
					}
				}
			}

			idx = 0;
			total = 0;
			// 2단계: 벡터에 있는거 합친 후에 arr배열로 옮기기
			for (int j = 0; j < N*N; j++)
			{
				if (v[j].size() == 0) continue;
				else
				{
					sort(v[j].begin(), v[j].end());
					int result = 0;
					int sz = v[j].size();
					for (int f = 0; f < sz; f++)	result += v[j][f].first;
					arr[idx][0] = j / N;
					arr[idx][1] = j%N;
					arr[idx][2] = result;
					arr[idx][3] = v[j][sz - 1].second;
					idx++;
					total += result;
					v[j].clear();
				}
			}
			if (idx == 0) { total = 0; break; }
		}//M
		printf("#"); printf("%d %d\n", i, total);
	}//Testcase
	return 0;
}