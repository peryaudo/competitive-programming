#include <cstdio>

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int a, b, c;
		scanf("%d %d %d\n", &a, &b, &c);
		puts(((a *a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a))?"YES":"NO");
	}
	return 0;
}
