#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		vector<int> a(n);
		for(int i = 0; i < n; i++) scanf("%d\n", &a[i]);
		long long max = 0;
		for(int i = 0; i < n; i++){
			long long m = a[i];
			for(int j = i + 1; j < n; j++){
				m += a[j];
				if(m > max) max = m;
			}
		}
		printf("%lld\n", max);
	}
	return 0;
}
