#include <cstdio>

int main()
{
	int l;
	double m, n;
	while(~scanf("%d,%lf,%lf\n", &l, &m, &n))
		if(25.0 <= m/(n*n)) printf("%d\n", l);
	return 0;
}
