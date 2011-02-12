#include <cstdio>
#include <cmath>

int main(){
	int n;
	scanf("%d\n", &n);

	for(int i = 0; i < n; i++){
		double x1, y1, x2, y2, x3, y3;
		scanf("%lf %lf %lf %lf %lf %lf\n", &x1, &y1, &x2, &y2, &x3, &y3);
		/*
		 * Consider each side of the triangle as a, b, and c.
		 * a = sqrt((x1 - x2)^2 + (y1 - y2)^2)
		 * b = sqrt((x2 - x3)^2 + (y2 - y3)^2)
		 * c = sqrt((x3 - x1)^2 + (y3 - y1)^2)
		 *
		 * cos B = (a^2 + c^2 - b^2)/2ac
		 * sin^2 B = 1 - cos^2 B
		 * sin B = sqrt(1 - cos^2 B)
		 *
		 * b / sin B = 2R
		 * <=> R = b / 2 sin B
		 *
		 * R = sqrt((x2 - x3)^2 + (y2 - y3)^2) / 
		 *       2 * sqrt(1 - cos^2 B)
		 *
		 * <=> R = sqrt((x2 - x3)^2 + (y2 - y3)^2) / 
		 *       2 * sqrt(1 - ((a^2 + c^2 - b^2)/2ac)^2)
		 *
		 * (As a matter of fact, it is a kind of formula.)
		 *
		 * Consider the center of the circumscribed circle O(xp, yp)
		 * AO = BO = CO
		 *
		 * AO, BO, CO are real numbers, therefore
		 * AO^2 = BO^2 = CO^2
		 * (x1 - xp)^2 + (y1 - yp)^2 = (x2 - xp)^2 + (y2 - yp)^2
		 * x1^2 -2 x1 xp + xp^2 + (ry
		 *
		 * x1^2 + y1^2 - x2^2  - y2^2 = 2 x1 xp + 2 y1 yp - 2 x2 xp - 2 y2 yp
		 * x1^2 + y1^2 - x2^2  - y2^2 = 2xp(x1 - x2) + 2yp(y1 - y2)
		 *
		 * (x1^2 + y1^2 - x2^2  - y2^2) / 2 = (x1 - x2)xp + (y1 - y2)yp -- (1)
		 * (x3^2 + y3^2 - x2^2  - y2^2) / 2 = (x3 - x2)xp + (y3 - y2)yp -- (2)
		 * (2) <=> (x3^2 + y3^2 - x2^2  - y2^2) / 2 - (x3 - x2)xp = (y3 - y2)yp
		 *     <=> (x3^2 + y3^2 - x2^2  - y2^2) / (2 - (x3 - x2)xp) * (y3 - y2) = yp
		 * substitute (2) into (1):
		 * (x1^2 + y1^2 - x2^2  - y2^2) / 2 = (x1 - x2)xp + (y1 - y2)yp -- (1)
		 *
		 *
		 */

		double a_sq = pow(x1 - x2, 2) + pow(y1 - y2, 2),
		       b_sq = pow(x2 - x3, 2) + pow(y2 - y3, 2),
		       c_sq = pow(x3 - x1, 2) + pow(y3 - y1, 2);
		double R = sqrt(b_sq / (4 * (1 - pow(a_sq + c_sq - b_sq, 2) / (4 * a_sq * c_sq))));
		double xp = (x1 + x2 + x3) / 3, yp = (y1 + y2 + y3) / 3; // wrong
		printf("%lf %lf %lf\n", xp, yp, R);
	}
	return 0;
}
