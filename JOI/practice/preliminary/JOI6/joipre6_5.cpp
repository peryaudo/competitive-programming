#include <cstdio>
#include <vector>
using namespace std;
class test {
public:
	int i, j, k, r;
};
int main(){
	int a, b, c;
	while(scanf("%d %d %d\n", &a, &b, &c), a || b || c){
		vector<int> v(a + b + c + 1, 2);
		int N;
		scanf("%d\n", &N);
		vector<test> w(N);
		for(int _i = 0; _i < N; _i++){
			int i, j, k, r;
			scanf("%d %d %d %d\n", &i, &j, &k, &r);
			w[_i].i = i; w[_i].j = j;
			w[_i].k = k; w[_i].r = r;
		}
		for(int i = 0; i < w.size(); i++){
			if(w[i].r){
				v[w[i].i] = 1; v[w[i].j] = 1; v[w[i].k] = 1;
			}
		}
		for(int i = 0; i < w.size(); i++){
			if(!(w[i].r)){
				if(v[w[i].i] == 1 && v[w[i].j] == 1) v[w[i].k] = 0;
				if(v[w[i].i] == 1 && v[w[i].k] == 1) v[w[i].j] = 0;
				if(v[w[i].j] == 1 && v[w[i].k] == 1) v[w[i].i] = 0;
			}
		}
		for(int i = 1; i < v.size(); i++)
			printf("%d\n", v[i]);
	}
	return 0;
}
