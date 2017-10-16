/*
	TITLE: SWIMMING POOL
	SW EXPERT ACADEMY 1952
	CATEGORY: DP
	DATE: 2017-10-16

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define smaller(a,b) a>b?b:a
int cost[4];
int plan[12];
int dp[12];

int main()
{
	int T; scanf("%d", &T);
	for (int s = 1; s <= T; s++)
	{
		for (int i = 0; i < 4; i++)		scanf("%d", &cost[i]);
		for (int i = 0; i < 12; i++)
		{
			scanf("%d", &plan[i]);
			if (plan[i] * cost[0] > cost[1]) plan[i] = cost[1];
			else plan[i] = plan[i] * cost[0];
		}
		dp[0] = plan[0];
		dp[1] = plan[0] + plan[1];
		dp[2]= smaller(dp[1]+plan[2], cost[2]);

		for (int i = 3; i < 12; i++)
		{
			dp[i] = smaller(dp[i - 1] + plan[i], dp[i-3]+cost[2]);
		}
		dp[11] = smaller(dp[11], cost[3]);
		printf("#%d %d\n", s, dp[11]);
	}
	return 0;
}