#include <cstdio>
inline int colour(int N, int a, int b){
	if(a > N / 2) a = N - a + 1;
	if(b > N / 2) b = N - b + 1;
	if(a > b){
		int t = a;
		a = b;
		b = t;
	}
	return ((a - 1) % 3) + 1;
}
int main()
{
	int N, K;
	scanf("%d\n%d\n", &N, &K);
	for(int i = 0; i < K; i++){
		int a, b;
		scanf("%d %d\n", &a, &b);
		printf("%d\n", colour(N, a, b));
	}
	return 0;
}
