#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
int main(){
	int n, k;
	while(scanf("%d %d\n", &n, &k), n || k){
		vector<int> v(n);
		for(int i = 0; i < n; i++)
			scanf("%d\n", &v[i]);
		int Sc = 0;
		for(int i = 0; i < k; i++)
			Sc += v[i];
		int Sm = Sc;
		for(int i = 0; i < n - k; i++){
			Sc -= v[i];
			Sc += v[i + k];
			Sm = max(Sm, Sc);
		}
		printf("%d\n", Sm);
	}
	
	return 0;
}
