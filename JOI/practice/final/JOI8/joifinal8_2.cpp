#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	unsigned int d;
	while(scanf("%u\n", &d), d){
		int n, m;
		scanf("%d\n%d\n", &n, &m);

		vector<unsigned int> v(n);
		v[0] = 0;
		for(int i = 1; i < n; i++)
			scanf("%u\n", &v[i]);

		sort(v.begin(), v.end());

		unsigned int dst = 0;
		for(int i = 0; i < m; i++){
			long long k;
			scanf("%lld\n", &k);
			long long shortest = LLONG_MAX;

			vector<unsigned int>::iterator it = lower_bound(v.begin(), v.end(), k);
			if(it != v.end()) shortest = min(shortest, abs(*it - k));
			if(--it >= v.begin()) shortest = min(shortest, abs(*it - k));
			k += d;
			it = lower_bound(v.begin(), v.end(), k);
			if(it != v.end()) shortest = min(shortest, abs(*it - k));
			if(--it >= v.begin()) shortest = min(shortest, abs(*it - k));
			k -= d; k -= d;
			it = lower_bound(v.begin(), v.end(), k);
			if(it != v.end()) shortest = min(shortest, abs(*it - k));
			if(--it >= v.begin()) shortest = min(shortest, abs(*it - k));
			dst += shortest;
		}
		printf("%d\n", dst);

	}
	return 0;
}
