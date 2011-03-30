#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d\n", &n);
	queue<int> pq;
	pq.push(n);
	int res = 0;
	while(!pq.empty()){
		int x = pq.front(); pq.pop();
		if(x - 1 <= 1){
			res = (res + 3) % 1000003;
			continue;
		}else{
			pq.push(x - 1);
			pq.push(x - 1);
			pq.push(x - 1);
		}
	}
	printf("%d\n", res);
	return 0;
}
