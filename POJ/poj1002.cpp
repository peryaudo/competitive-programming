#include <iostream>
#include <map>
#include <string>
int main(){
        using namespace std;
        int i, j, c, sz, n;
        string s;
        char r[9];
        map<string, int> m;
        cin>>n;
        for(i=0;i<n;i++){
                c=0;
                cin>>s;
                for(j=0,sz=s.size();j<sz;j++){
                        if(47<s[j]&&s[j]<58){r[c]=s[j];c++;continue;}
                        if(64<s[j]&&s[j]<81){r[c]=(s[j]-65)/3+50;c++;continue;}
                        if(81<s[j]&&s[j]<90){r[c]=(s[j]-66)/3+50;c++;continue;}
                }
                r[c]=0;
                m[r]++;
        }
        map<string, int>::iterator it = m.begin();
        while(it != m.end()){
                if(1 < (*it).second){
                        n = 0;
                        s=(*it).first;s.insert(3,"-");
                        cout<<s<<" "<<(*it).second<<endl;
                }
                ++it;
        }
        if(n) cout<<"No duplicates.";
}
