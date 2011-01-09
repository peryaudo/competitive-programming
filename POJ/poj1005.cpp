#include <cstdio>
#include <cmath>
int main()
{
	int N;
	const double pi = 3.1415;
	scanf("%d\n", &N);
	for(int i = 0; i < N; i++){
		double X, Y;
		scanf("%lf %lf\n", &X, &Y);
		double a = sqrt(X*X + Y*Y);
		for(int j = 0; ; j++){
			double b = sqrt(50 * 2 * j / pi);
			if(a < b){
				printf("Property %d: This property will begin eroding in year %d.\n", i + 1, j);
				break;
			}
		}
	}
	printf("END OF OUTPUT.\n");
	return 0;
}