#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class E {
public:
	int to, cost;
	E(int to, int cost){this->to = to;this->cost = cost;}
};
class Pr {
public:
	int cost, edge;
	Pr(int cost, int edge){this->cost = cost;this->edge = edge;}
	int operator<(const Pr& src) const { return cost < src.cost; }
	int operator>(const Pr& src) const { return cost > src.cost; }
};
int main()
{
	int n, k;
	while(scanf("%d %d\n", &n, &k), n || k){
		vector<vector<E> > v(n);
		for(int h = 0; h < k; h++){
			int mode;
			scanf("%d ", &mode);
			if(!mode){
				/* customer */
				int a, b;
				scanf("%d %d\n", &a, &b);
				a--, b--;

				vector<int> d(n, INT_MAX);
				priority_queue<Pr, vector<Pr>, greater<Pr> > pq;
				d[a] = 0;
				pq.push(Pr(0, a));
				while(!pq.empty()){
					Pr pr = pq.top(); pq.pop();
					if(d[pr.edge] < pr.cost) continue;
					for(int i = 0; i < v[pr.edge].size(); i++){
						E edge = v[pr.edge][i];
						if(d[edge.to] > d[pr.edge] + edge.cost){
							d[edge.to] = d[pr.edge] + edge.cost;
							pq.push(Pr(d[edge.to], edge.to));
						}
					}
				}
				printf("%d\n", d[b] == INT_MAX ? -1 : d[b]);
			}else{
				/* boat information */
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
