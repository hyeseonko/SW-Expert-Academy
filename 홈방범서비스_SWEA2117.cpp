/*
	TITLE: HOME SECURITY SERVICE
	SW EXPERT ACADEMY 2117
	CATEGORY: SIMULATION
	DATE: 2017-10-12
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[20][20];
int house_info[400][2];
int how_far[401];

int dis(int x1, int y1, int x2, int y2)
{
	if (x1 > x2)
	{
		if (y1 > y2) return (x1 - x2) + (y1 - y2)+1;
		else return (x1 - x2) + (y2 - y1)+1;
	}
	else
	{
		if (y1 > y2) return (x2 - x1) + (y1 - y2)+1;
		else return (x2 - x1) + (y2 - y1)+1;
	}
}

int main()
{
	int T; scanf("%d", &T);
	for (int s = 1; s <= T; s++)
	{
		int max_houses = 1;
		int total_houses = 0;
		int N, M; scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1)
				{
					house_info[total_houses][0] = i;
					house_info[total_houses][1] = j;
					total_houses++;
				}
			}
		}
	
		// 1단계: 다 계산하지 않아도 되는 부분은 걸러주자
		if (M*total_houses - 2 * N*N + 2 * N - 1 >= 0) max_houses = total_houses;
		// 2단계: house_info별 how_far 계산후 뒤에서부터 처리
		else
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					for (int k = 0; k < total_houses; k++)
					{
						how_far[k] = dis(i, j, house_info[k][0], house_info[k][1]);
					}
					std::sort(how_far, how_far + total_houses);
					for (int k = total_houses - 1; k >= 1; k--)
					{
						if (k + 1 < max_houses) break;
						if (how_far[k] > N || how_far[k] == how_far[k + 1]) continue;
						if ((k + 1)*M-2*how_far[k]*how_far[k]+2*how_far[k]-1>=0)
						{
							if (k + 1 > max_houses) max_houses = k + 1;
							break;
						}
					}
				}
			}
		}
		printf("#"); printf("%d %d\n", s, max_houses);
		memset(arr, 0, sizeof(arr));
		memset(house_info, 0, sizeof(house_info));
	}

	return 0;
}