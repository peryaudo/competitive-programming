#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	double n;
	vector<double> v;
	while(~scanf("%lf", &n))
		v.push_back(n);
	sort(v.begin(), v.end());
	printf("%.1lf\n", *v.rbegin() - *v.begin());
	return 0;
}
