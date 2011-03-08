#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class BreakingTheCode {
public:
	string decoding(string code, string message){
		string res("");
		for(int i = 0, t; i < message.size() / 2; i++){
			stringstream ss(message.substr(i * 2, 2));
			ss>>t;
			res += code[t - 1];
		}
		return res;
	}
	string encoding(string code, string message){
		stringstream res;
		map<char, int> ma;
		for(int i = 0; i < code.size(); i++)
			ma[code[i]] = i + 1;

		for(int i = 0; i < message.size(); i++){
			int cur = ma[message[i]];
			if(cur < 10){
				res<<'0';
			}
			res<<cur;
		}

		return res.str();
	}

	string decodingEncoding(string code, string message) {
		if('0' <= message[0] && message[0] <= '9'){
			return decoding(code, message);
		}else{
			return encoding(code, message);
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; string Arg1 = "test"; string Arg2 = "20051920"; verify_case(0, Arg2, decodingEncoding(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; string Arg1 = "20051920"; string Arg2 = "test"; verify_case(1, Arg2, decodingEncoding(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "qesdfvujrockgpthzymbnxawli"; string Arg1 = "mwiizkelza"; string Arg2 = "19242626171202251723"; verify_case(2, Arg2, decodingEncoding(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "faxmswrpnqdbygcthuvkojizle"; string Arg1 = "02170308060416192402"; string Arg2 = "ahxpwmtvza"; verify_case(3, Arg2, decodingEncoding(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	BreakingTheCode ___test;
	___test.run_test(-1);
}
// END CUT HERE
