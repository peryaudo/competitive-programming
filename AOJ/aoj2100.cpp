#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int t;
	scanf("%d\n", &t);
	for(int _i = 0; _i < t; _i++){
		int n;
		scanf("%d\n", &n);
		int mup = 0, mdown = 0;
		int prev;
		scanf("%d", &prev);
		for(int i = 1, cur; i < n; i++){
			scanf("%d", &cur);
			if(cur > prev) mup = max(mup, cur - prev);
			if(cur < prev) mdown = max(mdown, prev - cur);
			prev = cur;
		}
		printf("%d %d\n", mup, mdown);
	}
	return 0;
}
