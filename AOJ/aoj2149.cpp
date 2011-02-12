#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int N, A, B, C, X;
	while(scanf("%d %d %d %d %d\n", &N, &A, &B, &C, &X),
			N || A || B || C || X){
		vector<int> v(N);
		for(int i = 0; i < N; i++)
			scanf("%d\n", &v[i]);

		int p = 0, f = -1;

		for(int i = 0; i <= 10000; i++){
			if(X == v[p]){
				p++;
				if(N <= p){
					f = i;
					break;
				}
			}
			X = (A * X + B) % C;
		}

		printf("%d\n", f);

	}
	return 0;
}
