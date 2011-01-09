#include <cstdio>

int main()
{
	int n;
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++){
		double x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf\n", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		puts(((y1 - y2) / (x1 - x2)) == ((y3 - y4) / (x3 - x4)) ? "YES" : "NO");
	}
	return 0;
}
