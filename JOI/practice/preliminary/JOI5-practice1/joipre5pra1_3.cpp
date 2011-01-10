#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
inline int keta(int x){
	int dst = 1;
	while(dst < x)
		dst *= 10;
	return dst;
}
int main()
{
	int n;
	scanf("%d\n", &n);
	vector<int> v(n);
	vector<pair<int, int> > w(n*(n - 1));
	for(int i  = 0; i < n; i++)
		scanf("%d\n", &v[i]);
	//sort(v.begin(), v.end());
	for(int i = 0, cnt = 0; i < v.size(); i++)
		for(int j = 0; j < v.size(); j++){
			if(i == j) continue;
			// w[cnt] = v[i] * keta(v[j]) + v[j];
			w[cnt] = make_pair(v[i], v[j]);
			cnt++;
		}
	sort(w.begin(), w.end());
	for(int i = 0; i < 4; i++){
		printf(">%d,%d\n", w[i].first, w[i].second);
	}
	if(w.size() >= 3){
		printf("%d,%d\n", w[2].first, w[2].second);
	}
	return 0;
}
