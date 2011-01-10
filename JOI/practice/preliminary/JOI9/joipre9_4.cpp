#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
long long fact(long long x){
	long long y = x;
	if(x == 0) return 0;
	while(--x) y *= x;
	return y;
}

int main()
{
	int n, k;
	while(scanf("%d\n%d\n", &n, &k), n || k){
		vector<int> v(n);
		set<vector<int> > se;
		set<string> tf;
		for(int i = 0; i < n; i++) scanf("%d\n", &v[i]);
		for(int i = 0; i < (1 << n); i++){
			int c = 0;
			for(int j = 0; j < n; j++)
				if(i & (1 << j)) c++;
			if(c != k) continue;
			vector<int> w;
			for(int j = 0; j < n; j++)
				if(i & (1 << j)) w.push_back(v[j]);
			sort(w.begin(), w.end());
			if(se.find(w) == se.end()){
				se.insert(w);
				do {
					stringstream ss;
					for(vector<int>::iterator it = w.begin(); it != w.end(); it++){
						ss<<*it;
					}
					tf.insert(ss.str());
				} while(next_permutation(w.begin(), w.end()));
			}
		}
		printf("%d\n", tf.size());
	}

	return 0;
}
