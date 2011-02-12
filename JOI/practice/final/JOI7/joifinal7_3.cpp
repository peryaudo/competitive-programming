#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	while(scanf("%d %d\n", &N, &M), N || M){
		vector<int> P(N + 1), Pd;
		for(int i = 0; i < N; i++)
			scanf("%d\n", &P[i]);
		P[N] = 0;

		for(int i = 0; i < P.size(); i++)
		for(int j = 0; j < P.size(); j++)
			Pd.push_back(P[i] + P[j]);

		int res = 0;
		sort(Pd.begin(), Pd.end());
		for(int i = 0, t; i < Pd.size(); i++){
			if((t = M - Pd[i]) < 0) continue;
			res = max(res, Pd[i] + *(lower_bound(Pd.begin(), Pd.end(), t) - 1));
		}

		printf("%d\n", res);
	}
	return 0;
}
