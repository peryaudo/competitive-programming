//Wrong Answer
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

class StrongPrimePower {
public:
	inline bool isprime(int x, vector<bool>& sieve){
		for(int i = 2, l = (int)sqrt(x); i < l; i++){
			if(i < sieve.size()){
				if(!sieve[i]) continue;
				if(!(x % i)){
					return false;
				}
			}
		}
		return true;
	}
	vector<int> baseAndExponent(string _n){
		stringstream ss(_n);
		ull n;
		ss>>n;
		int l = (int)min((int)sqrt((long double)n), INT_MAX);
		int pnl = min((int)sqrt(INT_MAX), l) + 1;
		vector<bool> pn(pnl, true);
		pn[0] = pn[1] = false;
		for(int i = 2; i < l; i++){
			if(i < pnl){
				if(!pn[i]) continue;
				for(int j = i + i; j < l; j += i) pn[j] = false;
			}else{
				if(!isprime(i, pn)) continue;
			}
			int q = 0; ull t = n;
			while(!(t % i)){
				t /= i;
				q++;
				if(t == 1){
					vector<int> ;
					v.push_back(i);
					v.push_back(q);
					return v;
				}
			}
		}
		return vector<int>();
	}
};
