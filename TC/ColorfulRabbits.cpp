// Challenge Succeeded
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class ColorfulRabbits {
public:
	int getMinimum(vector <int> replies) {
		map<int, int> ma;
		for(int i = 0; i < replies.size(); i++){
			ma[replies[i]]++;
		}
		
		int res = 0;
		for(map<int, int>::iterator it = ma.begin(); it != ma.end(); it++){
			int a = (*it).first, b = (*it).second;
			res += (a + 1) * ((b + 3) / 3);
		}
		return res;
	}
};
