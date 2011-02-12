// Wrong Answer
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

class Vertex {
public:
	int vertex;
	long long cost;
	Vertex(){return;}
	Vertex(int vertex, long long cost){
		this->vertex = vertex;
		this->cost = cost;
		return;
	}
	const bool operator<(const Vertex& ve) const { return this->cost < ve.cost; }
	const bool operator>(const Vertex& ve) const { return this->cost > ve.cost; }
};

class TimeTravellingSalesman {
public:
	vector<vector<long long> > co;
	long long prim(int N){
		vector<long long> mco(N, INT_MAX);
		vector<bool> visited(N, false);
		int size = 0;
		long long total = 0;
		priority_queue <Vertex, vector<Vertex>, greater<Vertex> > pq;
		pq.push(Vertex(0, 0)); mco[0] = 0;
		while(!pq.empty() && size < N){
			Vertex ve = pq.top(); pq.pop();
			if(visited[ve.vertex]) continue;
			visited[ve.vertex] = true;
			total += mco[ve.vertex];
			size++;

			for(int i = 0; i < N; i++){
				if(!visited[i] && co[ve.vertex][i] != INT_MAX){
					mco[i] = co[ve.vertex][i];
					pq.push(Vertex(i, mco[i]));
				}
			}
		}
		return size == N ? total : -1;
	}
	
	void parse_roads(vector<string>& _roads){
		string roads;
		for(int i = 0; i < _roads.size(); i++){
			roads += _roads[i];
		}
		while(!roads.empty()){
			int a, b; long long travelcost;
			sscanf(roads.c_str(), "%d,%d,%lld", &a, &b, &travelcost);
			co[a][b] = co[b][a] = travelcost;
			int p;
			if((p = roads.find(' ')) != string::npos){
				roads = roads.substr(p + 1);
			}else{
				roads.clear();
			}
		}
	}
	long long determineCost(int N, vector<string> roads){
		co = vector<vector<long long> >(N, vector<long long>(N));
		parse_roads(roads);
		return prim(N);
	}
};
