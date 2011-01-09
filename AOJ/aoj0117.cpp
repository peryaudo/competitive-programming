#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
class E {
public: int to, cost;
	E(int to, int cost){ this->to = to; this->cost = cost; }
};

class P {
public: int cost, node;
	P(int cost, int node){ this->cost = cost; this->node = node; }
	int operator<(const P& p) const { return this->cost < p.cost; }
	int operator>(const P& p) const { return this->cost > p.cost; }
};

int dijkstra(vector<vector<E> >& v, int from, int dst){
	vector<int> d(v.size(), INT_MAX);
	priority_queue<P, vector<P>, greater<P> > pq;

	d[from] = 0;
	pq.push(P(0, from));
	while(!pq.empty()){
		P p = pq.top(); pq.pop();
		if(d[p.node] < p.cost) continue;
		for(int i = 0; i < v[p.node].size(); i++){
			E e = v[p.node][i];
			if(d[e.to] > d[p.node] + e.cost){
				d[e.to] = d[p.node] + e.cost;
				pq.push(P(d[e.to], e.to));
			}
		}
	}

	return d[dst];
	
}

int main()
{
	int n, m;
	scanf("%d\n%d\n", &n, &m);
	vector<vector<E> > v(n);
	for(int i = 0; i < m; i++){
		int a, b, c, d;
		scanf("%d,%d,%d,%d\n", &a, &b, &c, &d);
		a--, b--;
		v[a].push_back(E(b, c));
		v[b].push_back(E(a, d));
	}
	int x1, x2, y1, y2;
	scanf("%d,%d,%d,%d\n", &x1, &x2, &y1, &y2);
	x1--, x2--;
	printf("%d\n", y1 - dijkstra(v, x1, x2) - dijkstra(v, x2, x1) - y2);

	return 0;
}
