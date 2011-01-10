#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int N, M;
	while(scanf("%d %d\n", &N, &M), N || M){
		vector<int> v(N), w(M);
		for(int i = 0; i < N; i++) scanf("%d\n", &v[i]);
		for(int i = 0; i < M; i++) scanf("%d\n", &w[i]);
		for(int i = 0, p = 0; i < M; i++){
			if((p += w[i]) >= N){ printf("%d\n", i + 1); break; }
			p += v[p];
			if(p >= (N - 1)){ printf("%d\n", i + 1); break; }
		}
	}
	return 0;
}
