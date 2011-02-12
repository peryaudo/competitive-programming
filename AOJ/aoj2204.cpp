#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		int least = INT_MAX, most = 0;
		for(int i = 0; i < n; i++){
			int cur = 0;
			for(int j = 0, S; j < 5; j++){
				scanf("%d", &S);
				cur += S;
			}
			least = min(least, cur);
			most = max(most, cur);
		}
		printf("%d %d\n", most, least);

	}
	return 0;
}
