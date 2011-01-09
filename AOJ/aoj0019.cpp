#include <cstdio>

int main()
{
	int n;
	scanf("%d\n", &n);
	long long m = n;
	while(--n) m *= n;
	printf("%lld\n", m);
	return 0;
}
