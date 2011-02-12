#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
int main()
{
	vector<bool> prime((int)SHRT_MAX + 1, true);
	prime[0] = false, prime[1] = false;
	for(int i = 2; i < prime.size(); i++){
		if(!prime[i]) continue;
		for(int j = i + i; j < prime.size(); j += i){
			prime[j] = false;
		}
	}

	int n;
	while(scanf("%d\n", &n), n){
		int cnt = 0;
		for(int i = 1; i <= n / 2; i++){
			if(prime[i]){
				if(prime[n - i]) cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
