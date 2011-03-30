#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d\n", &n);

	vector<int> v(n);
	for(int i = 0; i < n; i++) scanf("%d", &v[i]);

	bool res = false;
	for(int i = 1; i <= n / 2; i++){
		if(n % i) continue;
		if(n / i < 3) continue;
		for(int j = 0; j < i; j++){
			int t = 1;
			for(int k = j; k < n; k += i){
				if(!v[k]){
					t = 0;
					break;
				}
			}
			if(t) res = true;
			if(res) break;
		}
		if(res) break;
	}
	puts(res ? "YES" : "NO");
	return 0;
}
