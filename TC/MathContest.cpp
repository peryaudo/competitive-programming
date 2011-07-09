#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class MathContest {
public:
	inline char getcur(string& ballSequence, int pos, int repetitions, bool rev){
		return (!rev) ? ballSequence[(pos % repetitions)] : (ballSequence[(pos % repetitions)] == 'B' ? 'W' : 'B');
	}
	int countBlack(string ballSequence, int repetitions) {
		bool reversed = false;
		bool turned = false;
		int full = ballSequence.size() * repetitions;
		int beg = 0, end = full - 1, cnt = full, blk = 0;
		while(cnt > 0){
			printf("hanten:%d mawaru:%d\n", reversed, turned);

			int cur = turned ? end : beg;
			if(turned)
				end--;
			else
				beg++;
			if(getcur(ballSequence, cur, repetitions, reversed) == 'B'){ // Black
				printf("B %d %d %d %d\n", reversed, turned, beg, end);
				reversed = (!reversed);
				blk++;
			}else{
				printf("W %d %d %d %d\n", reversed, turned, beg, end);
				turned = (!turned);
			}
			cnt--;
		}
		return blk;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BBWWB"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BBB"; int Arg1 = 10; int Arg2 = 1; verify_case(1, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BW"; int Arg1 = 10; int Arg2 = 20; verify_case(2, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "WWWWWWWBWWWWWWWWWWWWWW"; int Arg1 = 1; int Arg2 = 2; verify_case(3, Arg2, countBlack(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	MathContest ___test;
	___test.run_test(-1);
}
// END CUT HERE
