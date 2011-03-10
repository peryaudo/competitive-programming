// System Test Passed
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class PalindromeGame {
public:
	int getMaximum(vector <string> front, vector <int> back) {
		vector<pair<int, string> > v(front.size());
		for(int i = 0; i < front.size(); i++){
			v[i] = make_pair(back[i], front[i]);
		}
		sort(v.begin(), v.end(), greater<pair<int, string> >());

		int total = 0;
		int f = 0;
		while(!v.empty()){
			int fd = 0;
			vector<pair<int, string> >::iterator beg = v.begin();
			string t = (*beg).second;
			reverse(t.begin(), t.end());
			for(vector<pair<int, string> >::iterator it = v.begin() + 1; it != v.end(); it++){
				if((*it).second == t){
					total += (*beg).first + (*it).first;
					v.erase(it);
					fd = 1;
					break;
				}
			}
			if(!fd && !f){
				if(t == (*beg).second){
					total += (*beg).first;
					f = 1;
				}
			}
			v.erase(beg);
		}
		return total;
	}
};
