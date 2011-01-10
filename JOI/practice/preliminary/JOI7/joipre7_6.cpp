#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
class E {
public:
	int to, cost;
	E(int to, int cost){
		this->to = to;
		this->cost = cost;
		return;
	}
};
class P {
public:
	int node, cost;
	P(int node, int cost){
		this->node = node;
		this->cost = cost;
		return;
	}
	bool operator<(const P& src) const { return cost < src.cost; }
	bool operator>(const P& src) const { return cost > src.cost; }
};
int main()
{
	int n, k;
	while(scanf("%d %d\n", &n, &k), n || k){
		vector<vector<E> > v(n);
		for(int i = 0; i < k; i++){
			int mode;
			scanf("%d ", &mode);
			if(!mode){
				int a, b;
				scanf("%d %d\n", &a, &b);
				a--, b--;

				vector<int> w(n, INT_MAX);
				priority_queue<P, vector<P>, greater<P> > q;
				w[a] = 0;
				q.push(P(a, 0));
				while(!q.empty()){
					P p = q.top(); q.pop();
					if(w[p.node] < p.cost) continue;
					for(int j = 0; j < v[p.node].size(); j++){
						E e = v[p.node][j];
						if(w[e.to] > p.cost + e.cost){
							w[e.to] = p.cost + e.cost;
							q.push(P(e.to, w[e.to]));
						}
					}
				}
				printf("%d\n", w[b] == INT_MAX ? -1 : w[b]);
			}else{
				int c, d, e;
				scanf("%d %d %d\n", &c, &d, &e);
				c--, d--;
				v[c].push_back(E(d, e));
				v[d].push_back(E(c, e));
			}
		}
	}
	return 0;
}
