#include <cstdio>
#include <vector>
using namespace std;
inline vector<int> shuffle(vector<int>& v){
	vector<int> w;
	int n = v.size() / 2;
	for(int i = 0; i < n; i++){
		w.push_back(v[i]);
		w.push_back(v[i + n]);
	}
	return w;
}
inline vector<int> cut(vector<int>& v, int k){
	vector<int> w;
	for(int i = k; i < v.size(); i++)
		w.push_back(v[i]);
	for(int i = 0; i < k; i++)
		w.push_back(v[i]);
	return w;
}
int main(){
	int n, m;
	scanf("%d\n%d\n", &n, &m);
	vector<int> v(2 * n);
	for(int i = 0; i < 2 * n; i++) v[i] = i + 1;
	for(int i = 0; i < m; i++){
		int k;
		scanf("%d\n", &k);
		if(k == 0){
			v = shuffle(v);
		}else{
			v = cut(v, k);
		}
	}
	for(int i = 0; i < v.size(); i++){
		printf("%d\n", v[i]);
	}
	return 0;
}
