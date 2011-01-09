#include <iostream>
int main(){
        using namespace std;
        int p,q,r,o;
        for(int c=1;;c++){
                cin>>p>>q>>r>>o;
                if(p==-1)break;
                for(int i=1;i<21253;i++){
                        if(!((i+o-p)%23)&&!((i+o-q)%28)&&!((i+o-r)%33)){
                                cout<<"Case "<<c<<": the next triple peak occurs in "<<i<<" days.\n";
                                break;
                        }
                }
        }
}
