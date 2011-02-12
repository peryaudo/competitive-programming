#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
class Vertex {
public:
	int vertex, cost;
	Vertex(){return;}
	Vertex(int vertex, int cost){this->vertex = vertex; this->cost = cost;}
	int operator< (const Vertex& ve) const { return this->cost < ve.cost; }
	int operator> (const Vertex& ve) const { return this->cost > ve.cost; }
};

int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		vector<vector<int> > co(n, vector<int>(n, INT_MAX));

		int m;
		scanf("%d\n", &m);
		for(int i = 0; i < m; i++){
			int a, b, d;
			scanf("%d,%d,%d\n", &a, &b, &d);
			co[a][b] = co[b][a] = d;
		}

		vector<int> mco(n, INT_MAX);
		int total = 0;

		priority_queue<Vertex, vector<Vertex>, greater<Vertex> > pq;
		mco[0] = 0;
		pq.push(Vertex(0, 0));

		while(!pq.empty()){
			Vertex ve = pq.top(); pq.pop();
			if(mco[ve.vertex] < ve.cost) continue;
			total += mco[ve.vertex] ?
				((mco[ve.vertex] / 100) - 2) : mco[ve.vertex] ;

			for(int i = 0; i < mco.size(); i++){
				if(co[ve.vertex][i] < mco[i]){
					mco[i] = co[ve.vertex][i];
					pq.push(Vertex(i, mco[i]));
				}
			}
		}

		printf("%d\n", total);
	}
	return 0;
}

