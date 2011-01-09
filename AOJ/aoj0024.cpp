#include <cstdio>
#include <cmath>

int main()
{
	double n;
	while(~scanf("%lf\n", &n)){
		printf("%d\n", (int)ceil((pow(n / 9.8, 2) * 4.9 + 5) / 5));
	}
	return 0;
}
