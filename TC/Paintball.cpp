// System Test Failed
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Paintball {
public:
	vector <string> getLeaderboard(vector <string> players, vector <string> messages) {
		map<string, int> ps, ts; // player score, team score
		map<string, string> pt; // player team
		for(int i = 0; i < players.size(); i++){
			int p = players[i].find(' ');
			string name = players[i].substr(0, p), team = players[i].substr(p + 1);
			ps[name] = 0;
			pt[name] = team;
			ts[team] = 0;
		}
		for(int i = 0; i < messages.size(); i++){
			string from = messages[i].substr(0, messages[i].find(' '));
			string to = messages[i].substr(messages[i].rfind(' '));
			// team kill
			if(pt[from] == pt[to]){
				ps[from]--;
				ts[pt[from]]--;
			}else{
				ps[from]++;
				ps[to]--;
				ts[pt[from]]++;
				ts[pt[to]]++;
			}
		}
		vector<pair<int, string> > v;
		for(map<string, int>::iterator it = ts.begin(); it != ts.end(); it++){
			v.push_back(make_pair((*it).second, (*it).first));
		}
		sort(v.begin(), v.end(), greater<pair<int, string> >());

		map<string, vector<pair<int, string> > > ma;
		for(map<string, int>::iterator it = ps.begin(); it != ps.end(); it++){
			ma[pt[(*it).first]].push_back(make_pair((*it).second, (*it).first));
		}
		for(map<string, vector<pair<int, string> > >::iterator it = ma.begin(); it != ma.end(); it++){
			sort((*it).second.begin(), (*it).second.end(), greater<pair<int, string> >());
		}

		stringstream ss;
		for(int i = 0; i < v.size(); i++){
			ss<<v[i].second<<' '<<v[i].first<<endl;
			for(int j = 0; j < ma[v[i].second].size(); j++){
				ss<<"  "<<ma[v[i].second][j].second<<' '<<ma[v[i].second][j].first<<endl;
			}
		}
		string sres = ss.str();
		vector<string> res;
		while(!sres.empty()){
			int p = sres.find('\n');
			res.push_back(sres.substr(0, p));
			sres = sres.substr(p + 1);
		}
		
		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"A RED", "B BLUE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A SPLATTERED B"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"RED 1", "  A 1", "BLUE -1", "  B -1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"LISA RED", "BART RED", "HOMER BLUE", "MARGE BLUE", "MAGGIE GREEN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"MAGGIE SPLATTERED HOMER", "MAGGIE SPLATTERED MARGE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"GREEN 2", "  MAGGIE 2", "RED 0", "  BART 0", "  LISA 0", "BLUE -2", "  HOMER -1", "  MARGE -1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"TODD STRIKEFORCE",
 "BART OMEGA",
 "DATA STRIKEFORCE",
 "MILHOUSE OMEGA",
 "NELSON DISCOVERYCHANNEL",
 "MARTIN DISCOVERYCHANNEL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BART SPLATTERED MARTIN","TODD SPLATTERED MARTIN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"OMEGA 1", "  BART 1", "  MILHOUSE 0", "STRIKEFORCE 1", "  TODD 1", "  DATA 0", "DISCOVERYCHANNEL -2", "  NELSON 0", "  MARTIN -2" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"DR COHO", "ST COHO", "PE COHO"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"DR SPLATTERED ST",
 "ST SPLATTERED PE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"COHO -2", "  PE 0", "  DR -1", "  ST -1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getLeaderboard(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"A B", "AA AA", "AAA AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A SPLATTERED AAA", "A SPLATTERED AAA", "A SPLATTERED AAA", 
"AA SPLATTERED AAA", "AA SPLATTERED AAA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"B 3", "  A 3", "AA 2", "  AA 2", "AAA -5", "  AAA -5" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getLeaderboard(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	Paintball ___test;
	___test.run_test(-1);
}
// END CUT HERE
