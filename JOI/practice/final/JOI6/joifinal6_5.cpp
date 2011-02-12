#include <cstdio>
#include <vector>
#include <set>
#include <queue>
using namespace std;
class Stick {
public:
	Stick(){
		this->l = this->r = this->p = this->q = 0;
	}
	Stick(int l, int r, int p, int q){
		this->l = l; this->r = r; this->p = p; this->q = q;
	}
	int l, r, p, q;
};

int detect_root(vector<Stick>& v){
	for(int i = 0; i < v.size(); i++){
		set<int> se;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			se.insert(q.front());
			Stick st = v[q.front()];
			q.pop();
			if(~st.l) q.push(st.l);
			if(~st.r) q.push(st.r);
		}
		if(se.size() >= v.size()){
			return i;
		}
	}
	return -1;
}

inline int gcd(int a, int b){
	while(a > 0){
		if(b > a) swap(a, b);
		a %= b;
	}
	return b;
}
inline int lcm(int a, int b){
	return a / gcd(a, b) * b;
}
int search(int x, vector<Stick>& v){
	if(v[x].l < 0 && v[x].r < 0){
		return (v[x].p + v[x].q) / gcd(v[x].p, v[x].q);
	}else if(v[x].l < 0 && v[x].r >= 0){
		int _r = search(v[x].r, v);
		return 2 * lcm(_r * v[x].q, v[x].p);
	}else if(v[x].l >= 0 && v[x].r < 0){
		int _l = search(v[x].l, v);
		return 2 * lcm(_l * v[x].p, v[x].q);
		/*if((_l * p) % q){
			return 2 * lcm(_l * p, q);
		}else{
			return _l * p * 2;
		}*/
	}else if(v[x].l >= 0 && v[x].r >= 0){
		int _l = search(v[x].l, v), _r = search(v[x].r, v);
		return lcm(_l * v[x].p,  _r * v[x].q) * 2;
	}else{
		printf("oh, that's strange. It coudln't be occured.\n");
	}
}

int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		vector<Stick> v;
		for(int i = 0; i < n; i++){
			int p, q, r, b;
			scanf("%d %d %d %d\n", &p, &q, &r, &b);
			v.push_back(Stick(r - 1, b - 1, p, q));
		}
		printf("%d\n", search(detect_root(v), v));
	}
	return 0;
}
