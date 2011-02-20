#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N, H;
	scanf("%d %d\n", &N, &H);
	vector<int> d(N - 1), h(N - 1);
	for(int i = 0; i < N - 1; i++)
		scanf("%d %d\n", &d[i], &h[i]);
	vector<int> q;
	long long he = H;
	int cnt = 0;
	q.push_back(h[0]);
	for(int i = 1; i < N; i++){
		he -= d[i - 1];
		if(he <= 0){
			he += pq.top();
			pq.pop();
			cnt++;
		}
		pq.push(h[i]);
	}
	printf("%d\n", cnt);
	return 0;
}
