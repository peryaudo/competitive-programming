#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	const char *table[] = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z.?! "};

	string s;
	while(cin >> s){
		int row = 0, col = 0, na = 0;
		string t;
		if(s.size() % 2){
			na = 1;
		}else{
			for(int i = 0, l = s.size(); i < l; i += 2){
				string tmp;
				tmp = s[i];row = atoi(tmp.c_str());
				tmp = s[i + 1];col = atoi(tmp.c_str());
				if((row > 6) || (col > 5) || (row == 0) || (col == 0)){
					na = 1;
					break;
				}
				row--;col--;
				t += table[row][col];
			}
		}
		if(na){
			cout<<"NA\n";
		}else{
			cout<<t<<endl;
		}
	}

	return 0;
}
