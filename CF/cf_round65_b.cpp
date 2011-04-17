#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n, k, t;
	scanf("%d %d %d\n", &n, &k, &t);

	int sat = n * k *  t / 100;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		if(sat >= k){
			v[i] = k;
		}else if(sat < k && 0 < sat){
			v[i] = sat;
		}else if(sat <= 0){
			v[i] = 0;
		}
		sat -= k;
	}
	for(int i = 0; i < v.size(); i++){
		printf("%d%c", v[i], i != v.size() - 1 ? ' ' : '\n');
	}
	return 0;
}
