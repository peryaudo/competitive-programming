#include <cstdio>

int main()
{
	int n, a;
	while(a = 0, scanf("%d\n", &n), n){
		while(n /= 5) a += n;
		printf("%d\n", a);
	}
	return 0;
}

