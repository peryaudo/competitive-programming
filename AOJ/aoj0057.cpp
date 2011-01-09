#include <cstdio>

int main()
{
	int n;
	while(~scanf("%d\n", &n))
		printf("%d\n", (n * n + n + 2) / 2);
	return 0;
}
