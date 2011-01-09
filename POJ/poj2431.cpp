#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	vector<pair<int, int> > v;
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		int x, y;
		scanf("%d %d\n", &x, &y);
		v.push_back(make_pair(x, y));
	}
	int L, P;
	scanf("%d %d\n", &L, &P);
	sort(v.begin(), v.end());
	vector<pair<int, int> >::reverse_iterator rit = v.rbegin();
	priority_queue<int> pq;
	int cnt = 0;
	while(L){
		if(L == (*rit).first){
			pq.push((*rit).second);
			rit++;
		}
		if(P == 0){
			if(pq.empty()){
				cnt = -1;
				break;
			}
			P += pq.top();
			pq.pop();
			cnt++;
		}
		P--;L--;
	}
	printf("%d\n", cnt);
	return 0;
}
