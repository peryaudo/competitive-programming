#include <cstdio>
int main()
{
	int A, B;
	while(scanf("%d %d\n", &A, &B), A || B){
		int hyak = 0, gohyak = 0, sen = 0;
		int x = B - A;
		if(1000 <= x){ sen = x / 1000; x %= 1000; }
		if(500 <= x){ gohyak = x / 500; x %= 500; }
		if(100 <= x){ hyak = x / 100; x %= 100; }
		printf("%d %d %d\n", hyak, gohyak, sen);
	}
	return 0;
}
