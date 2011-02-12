#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<bool> prime(1299710, true);
	prime[0] = false;
	prime[1] = false;
	for(int i = 2; i < prime.size(); i++){
		if(!prime[i]) continue;
		for(int j = i + i; j < prime.size(); j += i){
			prime[j] = false;
		}
	}

	int n;
	while(scanf("%d\n", &n), n){
		int lower = 0, upper = 0;
		for(int i = n; 0 <= i; i--){
			if(prime[i]){ lower = i; break; }
		}
		for(int i = n; i < prime.size(); i++){
			if(prime[i]){ upper = i; break; }
		}
		printf("%d\n", upper - lower);
	}
	return 0;
}
