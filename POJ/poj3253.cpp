#include <cstdio>
#include <queue>
using namespace std;
int main(){
	int N;
	scanf("%d\n", &N);

	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i = 0; i < N; i++){
		int L;
		scanf("%d", &L);
		pq.push(L);
	}

	long long cnt = 0;
	while(pq.size() > 1){
		int n = pq.top();pq.pop();
		int m = pq.top();pq.pop();
		cnt += n + m;
		pq.push(n + m);
	}

	printf("%lld\n", cnt);
	return 0;
}
