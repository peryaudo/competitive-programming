#include <cstdio>

int main()
{
	int m, n;
	int total = 0, ave = 0, row = 0;
	while(~scanf("%d,%d\n", &m, &n)){
		total += m * n;
		ave += n;
		row++;
	}
	printf("%d\n%d\n", total, (int)(ave / (double)row + 0.5));
	return 0;
}
