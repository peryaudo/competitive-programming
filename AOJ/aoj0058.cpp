#include <cstdio>

int main(){
	double xA, yA, xB, yB, xC, yC, xD, yD;
	while(~scanf("%lf %lf %lf %lf %lf %lf %lf %lf\n", &xA, &yA, &xB, &yB, &xC, &yC, &xD, &yD)){
		printf("(%lf, %lf), (%lf, %lf)\n", (xA - xB), (yA - yB), (xC - xD), (yC - yD));
	}
	return 0;
}
