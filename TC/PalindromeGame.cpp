// Challenge Succeeded
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
		while(!v.empty()){
			vector<pair<int, string> >::iterator beg = v.begin();
			string t = (*beg).second;
			reverse(t.begin(), t.end());
			for(vector<pair<int, string> >::iterator it = v.begin(); it != v.end(); it++){
				if((*it).second == t){
					total += (*beg).first + (*it).first;
					v.erase(it);
					break;
				}
			}
			v.erase(beg);
		}
		return total;
		
	}

	

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
