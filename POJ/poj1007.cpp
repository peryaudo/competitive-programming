#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class dna {
public:
	string seq;
	int unsortedness;
	int getuns(){
		unsortedness = 0;
		for(int i = 0, l = seq.size() - 1; i < l; i++){
			for(int j = i + 1, m = l + 1; j < m; j++){
				if(seq[i] > seq[j])
					unsortedness++;
			}
		}
		return unsortedness;
	}
	dna(string str){
		seq = str;
		getuns();
	}
	int operator<(const dna& src) const {
		if(unsortedness < src.unsortedness)
			return 1;
		else
			return 0;
	}
};

int main(){
	vector<dna> lst;
	int n, m;
	cin>>n;
	cin>>m;

	for(int i = 0; i < m; i++){
		string s;
		cin>>s;
		lst.push_back(s);
	}


	stable_sort(lst.begin(), lst.end());

	for(int i = 0; i < m; i++){
		cout<<lst[i].seq<<endl;
	}
	
	return 0;
}
