#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

void solve(){
	string s;
	cin>>s;
	vector<int> outp(int(1e6),-1);
	int x=5*int(1e5),y;
	for(y=0;y<s.size();y++){
		outp[x+1+y]=int(s[y]-'a');
	}
	y=s.size()+1+x;


	bool flag =true;
	int q;
	cin>>q;
	int t,f;
	char c;
	for(int i=0;i<q;i++){
		cin>>t;
		if(t==1){
			flag=(!flag);
		}
		else{
			cin>>f>>c;
			if(flag){
				if(f==1){
					outp[x]=int(c-'a');
					x--;
				}
				else{
					outp[y]=int(c-'a');
					y++;
				}
			}
			else{
				if(f==2){
					outp[x]=int(c-'a');
					x--;
				}
				else{
					outp[y]=int(c-'a');
					y++;
				}
			}
		}
	}
	if(flag){
		for(int i=0;i<outp.size();i++)
			if(outp[i]!=-1)
			cout<<char(outp[i]+'a');
		cout<<"\n";
	}
	else{
		for(int i=outp.size()-1;i>-1;i--)
			if(outp[i]!=-1)
			cout<<char(outp[i]+'a');
		cout<<"\n";
	}

}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}