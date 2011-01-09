#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	int i, w, a, b;
	scanf("%d\n%*d\n", &w);
	vector<int> v(w);
	for(i = 0; i < w; i++) v[i] = i+1;
	while(scanf("%d,%d\n", &a, &b)+1) swap(v[a-1], v[b-1]);
	for(i = 0; i < w; i++) printf("%d\n", v[i]);
	return 0;
}
