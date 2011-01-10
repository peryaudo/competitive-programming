#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	scanf("%d\n%d\n", &n, &m);
	vector<int> in(n + 1), out(n + 1);
	for(int i = 1; i <= n; i++)
		scanf("%d %d\n", &in[i], &out[i]);
	int cur = m;
	int maximum = 0;
	for(int i = 1; i <= n; i++){
		cur += in[i];
		cur -= out[i];
		maximum = max(maximum, cur);
	}
	printf("%d\n", maximum);
	return 0;
}
