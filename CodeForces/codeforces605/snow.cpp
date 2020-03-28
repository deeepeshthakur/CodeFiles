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
	int l=0,r=0,u=0,d=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='L')
			l++;
		if(s[i]=='R')
			r++;
		if(s[i]=='D')
			d++;
		if(s[i]=='U')
			u++;
	}
	if(l<r){
		r=l;
	}
	else{
		l=r;
	}

	if(u<d){
		d=u;
	}
	else{
		u=d;
	}
	if(l>0&&d>0){
		cout<<l+r+u+d<<"\n";
		for(int i=0;i<l;i++){
			cout <<"L";
		}
		for(int i=0;i<u;i++){
			cout <<"U";
		}
		for(int i=0;i<r;i++){
			cout <<"R";
		}
		for(int i=0;i<d;i++){
			cout <<"D";
		}
	}
	else{
		if(l==0&&d>0){
			cout << "2\nUD";
		}
		if(d==0&&l>0){
			cout << "2\nLR";
		}
		if(l==0 && d==0){
			cout << "0\n";
		}
	}
	cout<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;       
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}