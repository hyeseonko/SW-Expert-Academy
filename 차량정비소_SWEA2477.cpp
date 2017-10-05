/*
	TITLE: CAR REPAIR SHOP
	SW EXPERT ACADEMY 2477
	CATEGORY: QUEUE, SIMULATION
	DATE: 2017-10-05
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
int reception[9][2]; // fixed, varied
int repair[9][2]; //�� �ش� â�� �ɸ��½ð�(fixed), �����̿�ð�
int people[1000][6]; // �����ð�, �������۽ð�, â����ȣ, �������ð�, ������۽ð�, �����ȣ
queue <pair<int, int> > q; // reception queue
priority_queue<pair<int,ii>, vector<pair<int, ii>>, greater<pair<int,ii>>> pq;

int main()
{
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int customer_sum = 0;
		int N, M, K, A, B; scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		memset(reception, 0, sizeof(reception));
		memset(repair, 0, sizeof(repair));
		memset(people, 0, sizeof(people));
		for (int j = 1; j <= N; j++) scanf("%d", &reception[j][0]);
		for (int j = 1; j <= M; j++) scanf("%d", &repair[j][0]);
		for (int j = 1; j <= K; j++) {
			scanf("%d", &people[j][0]);
			q.push({ j, people[j][0] });
		}

		int current_time = 0;

		/* 1�ܰ�: ���� ��ȣ ���� */
		while (!q.empty())
		{
			/* Reception */
			for (int j = 1; j <= N; j++)
			{
				if (reception[j][1] >= 1) reception[j][1]--;
			}

			for (int j = 1; j <= N; j++)
			{
				int people_num = q.front().first;
				int arrival_time = q.front().second;
				if (reception[j][1] == 0 && arrival_time <= current_time)
				{
					reception[j][1] = reception[j][0];
					people[people_num][1] = current_time;
					people[people_num][2] = j;
					people[people_num][3] = current_time + reception[j][0];
					
					/* queue 2�� ��������� */
					pq.push({ people[people_num][3],{j, people_num} });
					q.pop();
				}
				if (q.empty()) break; //  deque iterator not dereferencable �������� ������ �κ�
			}
			current_time++;
		}

		current_time = pq.top().first; // ���� ���� ����ҿ� ������ �ð��������� ����~
		
		/* 2�ܰ�: ���� ��ȣ ���� */
		while (!pq.empty())
		{
			/* Repair */
			for (int j = 1; j <= M; j++)
			{
				if (repair[j][1] >= 1) repair[j][1]--;
			}

			for (int j = 1; j <= M; j++)
			{
				int arrival_time = pq.top().first;
				//int reception_num = pq.top().second.first;
				int people_num = pq.top().second.second;
				if (repair[j][1] == 0 && arrival_time <= current_time)
				{
					repair[j][1] = repair[j][0];
					people[people_num][4] = j;
					if (j == B && people[people_num][2] == A) customer_sum += people_num;
					pq.pop();
				}
				if (pq.empty()) break; //  deque iterator not dereferencable �������� ������ �κ�
			}
			current_time++;
		}







		/* TEST */
		for (int a = 1; a <= K; a++)
		{
			printf("%d %d %d %d %d\n", people[a][0], people[a][1], people[a][2], people[a][3], people[a][4]);
		}

		printf("#");
		if (customer_sum == 0) printf("%d -1\n", i);
		else printf("%d %d\n", i, customer_sum);
	}
	return 0;
}