#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class CountExpressions {
public:
	int calcExpressions(int x, int y, int val) {
		vector<int> v;
		v.push_back(x); v.push_back(x);
		v.push_back(y); v.push_back(y);
		sort(v.begin(), v.end());
		int cnt = 0;
		do {
			queue<pair<int, int> > q;
			q.push(make_pair(v[0], 0));
			while(!q.empty()){
				pair<int, int> t = q.front(); q.pop();
				if(t.second >= 3){
					if(t.first == val) cnt++;
					continue;
				}
				int s;
				s = t.first + v[t.second + 1]; q.push(make_pair(s, t.second + 1));
				s = t.first - v[t.second + 1]; q.push(make_pair(s, t.second + 1));
				s = t.first * v[t.second + 1]; q.push(make_pair(s, t.second + 1));
			}
		} while(next_permutation(v.begin(), v.end()));
		return cnt;
	}

	

};
