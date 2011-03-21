#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SRMCards {
public:
	inline int exists(int x, int sz){
		return 0 <= x && x < sz;
	}
	int maxTurns(vector <int> cards) {
		sort(cards.begin(), cards.end());
		int turn = 0;
		while(!cards.empty()){
			vector<int> v(cards.size(), 0);
			for(int i = 0; i < cards.size(); i++){
				if(exists(i - 1, cards.size())){
					if(cards[i - 1] == cards[i] - 1) v[i]++;
				}
				if(exists(i + 1, cards.size())){
					if(cards[i + 1] == cards[i] + 1) v[i]++;
				}
			}
			vector<int> w;
			for(int i = 0; i < v.size(); i++){
				if(v[i] == 0){
					w.push_back(cards[i]);
				}
			}
			if(w.size()){
				for(int i = 0; i < w.size(); i++){
					cards.erase(remove(cards.begin(), cards.end(), w[i]), cards.end());
					turn++;
				}
				continue;
			}
			for(int i = 0; i < v.size(); i++){
				if(v[i] > 0){
					cards.erase(remove(cards.begin(), cards.end(), cards[i] - 1), cards.end());
					cards.erase(remove(cards.begin(), cards.end(), cards[i] + 1), cards.end());
					cards.erase(remove(cards.begin(), cards.end(), cards[i]), cards.end());
					turn++;
					break;
				}
			}
		}
		return turn;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {498, 499}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxTurns(Arg0)); }
	void test_case_1() { int Arr0[] = {491, 492, 495, 497, 498, 499}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maxTurns(Arg0)); }
	void test_case_2() { int Arr0[] = {100, 200, 300, 400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, maxTurns(Arg0)); }
	void test_case_3() { int Arr0[] = {11, 12, 102, 13, 100, 101, 99, 9, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, maxTurns(Arg0)); }
	void test_case_4() { int Arr0[] = {118, 321, 322, 119, 120, 320}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, maxTurns(Arg0)); }
	void test_case_5() { int Arr0[] = {10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(5, Arg1, maxTurns(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	SRMCards ___test;
	___test.run_test(-1);
}
// END CUT HERE
