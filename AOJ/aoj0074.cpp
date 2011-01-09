#include <cstdio>

int main()
{
	int l, m, n;
	while(~scanf("%d %d %d", &l, &m, &n), ~l && ~m && ~n){
		long long total = l * 60LL * 60 + m * 60 + n, remaining = 120 * 60 - total;
		printf("%02lld:%02lld:%02lld\n", remaining / 60 / 60, remaining / 60 % 60, remaining % 60);
		remaining *= 3;
		printf("%02lld:%02lld:%02lld\n", remaining / 60 / 60, remaining / 60 % 60, remaining % 60);
	}
	return 0;
}
